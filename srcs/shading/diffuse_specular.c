/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_specular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:38 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:31:39 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_col	diffuse_color(
	t_vec3 light_dir,
	t_trace_record *rec,
	int round_n_dot_l_bit
)
{
	t_col		col;
	double		it;
	double		kd;

	kd = 1;
	it = v3_dotpdt(light_dir, rec->normal);
	if (round_n_dot_l_bit)
		it = round_n_dot_l(it);
	it *= kd;
	it = it < 0 ? 0 : it;
	it = it > 1.0 ? 1.0 : it;
	col.r = it * rec->color.x;
	col.g = it * rec->color.y;
	col.b = it * rec->color.z;
	return (col);
}

static t_col	specular_color(t_vec3 light_dir, t_trace_record *rec, t_ll *ll)
{
	double		tmp;
	t_vec3		r;
	t_vec3		v;
	t_col		c;
	t_ol		*ol;

	ol = rec->obj;
	v = v3_scalar(rec->ray.dir, -1);
	tmp = v3_dotpdt(rec->normal, light_dir);
	tmp = tmp < 0 ? 0 : tmp;
	r = v3_scalar(rec->normal, 2 * tmp);
	r = v3_sub(r, light_dir);
	tmp = v3_dotpdt(r, v);
	tmp = tmp < 0 ? 0 : tmp;
	tmp = pow(tmp, ol->specpower) * ol->specvalue / 100;
	c.r = tmp * ll->its.x;
	c.g = tmp * ll->its.y;
	c.b = tmp * ll->its.z;
	return (c);
}

t_col			diffuse_specular(
	t_vec3 light_dir,
	t_ll *ll,
	t_trace_record *rec,
	t_env *e
)
{
	t_col		diffuse;
	t_col		specular;

	ft_bzero(&specular, sizeof(t_col));
	diffuse = diffuse_color(
		light_dir, rec, e->mask & RT_ENV_MASK_ROUND_N_DOT_L);
	if (!(e->mask & RT_ENV_MASK_NO_SPECULAR))
		specular = specular_color(light_dir, rec, ll);
	return (color_add(diffuse, specular));
}
