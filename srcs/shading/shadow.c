/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:47 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:31:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_ray	get_shadow_ray(t_trace_record *rec, t_vec3 light_dir)
{
	t_ray	ray;

	ray.ori = v3_add(rec->point, v3_scalar(rec->normal, RT_BIAS));
	ray.dir = light_dir;
	ray.t = FAR;
	return (ray);
}

double			get_transmittance(
	t_trace_record *rec,
	t_vec3 light_dir,
	double light_dist,
	t_env *e
)
{
	int			i;
	double		transmittance;
	double		t;
	t_ray		ray;

	ray = get_shadow_ray(rec, light_dir);
	transmittance = 1.0;
	i = 0;
	while (i < e->num_objs)
	{
		t = e->ll_obj[i].intersect(ray, e->ll_obj[i].object);
		if (t > 0.0 && t < light_dist)
			transmittance *= e->ll_obj[i].transparency;
		i++;
	}
	return (transmittance);
}
