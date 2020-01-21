/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:43 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 01:49:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_ior(t_trace_record *rec)
{
	t_trace_record		*cur;

	cur = rec->prev;
	while (cur != NULL)
	{
		if (cur->obj == rec->obj &&
			(cur->ray.type == RT_RAY_TYPE_REFRACTION ||
			cur->ray.type == RT_RAY_TYPE_ORIGIN))
			return (cur->ray.ior);
		cur = cur->prev;
	}
	return (rec->obj->ior);
}

static t_ray	get_refraction_ray(t_trace_record *rec)
{
	t_ray		ray;
	double		snell_ratio;
	double		cos_th1;
	double		det;
	t_vec3		a;

	ray.ior = get_ior(rec);
	snell_ratio = rec->ray.ior / ray.ior;
	cos_th1 = -v3_dotpdt(rec->ray.dir, rec->normal);
	det = 1.0 - snell_ratio * snell_ratio * (1.0 - cos_th1 * cos_th1);
	if (det < 0.0)
	{
		ray.type = RT_RAY_TYPE_NONE;
		return (ray);
	}
	ray.ori = v3_sub(rec->point, v3_scalar(rec->normal, RT_BIAS));
	a = v3_add(rec->ray.dir, v3_scalar(rec->normal, cos_th1));
	a = v3_scalar(a, snell_ratio);
	ray.dir = v3_sub(a, v3_scalar(rec->normal, sqrt(det)));
	ray.type = RT_RAY_TYPE_REFRACTION;
	ray.t = FAR;
	return (ray);
}

t_col			refraction_shade(
	t_env *e,
	t_trace_record *prev,
	double coeff
)
{
	t_trace_record		cur;

	if (prev->obj->transparency == 0.0)
		return ((t_col){0, 0, 0});
	cur.prev = prev;
	cur.ray = get_refraction_ray(prev);
	cur.depth = prev->depth + 1;
	if (!intersect(e, &cur))
		return ((t_col){0, 0, 0});
	return (calc_shade(e, &cur,
		coeff * (1.0 - prev->obj->reflectivity) * prev->obj->transparency));
}
