/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:45 by jebae             #+#    #+#             */
/*   Updated: 2019/12/17 21:12:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_col	shade_per_lights(t_env *e, t_trace_record *rec)
{
	int			i;
	double		light_dist;
	t_vec3		light_dir;
	t_col		sh[2];
	t_ll		*ll;

	i = 0;
	ft_bzero(&sh[0], sizeof(t_col));
	while (i < e->num_lights)
	{
		ll = &e->ll_lit[i];
		light_dir = ll->get_dir(&rec->point, ll->light);
		light_dist = ll->get_distance(&rec->point, ll->light);
		sh[1] = diffuse_specular(light_dir, ll, rec, e);
		sh[1] = color_scalar(sh[1],
			get_transmittance(rec, light_dir, light_dist, e));
		sh[0] = color_add(sh[0], sh[1]);
		i++;
	}
	return (sh[0]);
}

t_col			calc_shade(t_env *e, t_trace_record *rec, double coeff)
{
	t_col		sh;

	if (rec->depth >= RT_MAX_TRACE_DEPTH - 1)
		return ((t_col){0, 0, 0});
	sh = color_scalar(shade_per_lights(e, rec),
		coeff * (1.0 - rec->obj->reflectivity) *
		(1.0 - rec->obj->transparency));
	sh = color_add(sh, reflection_shade(e, rec, coeff));
	sh = color_add(sh, refraction_shade(e, rec, coeff));
	return (sh);
}
