/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:40 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:31:41 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_ray	get_reflection_ray(t_trace_record *rec)
{
	t_ray		ray;
	double		d_dot_n;

	d_dot_n = -v3_dotpdt(rec->ray.dir, rec->normal);
	ray.ori = v3_add(rec->point, v3_scalar(rec->normal, RT_BIAS));
	ray.dir = v3_add(rec->ray.dir, v3_scalar(rec->normal, 2.0 * d_dot_n));
	ray.type = RT_RAY_TYPE_REFLECTION;
	ray.ior = rec->ray.ior;
	ray.t = FAR;
	return (ray);
}

t_col			reflection_shade(
	t_env *e,
	t_trace_record *prev,
	double coeff
)
{
	t_trace_record		cur;

	if (prev->obj->reflectivity == 0.0)
		return ((t_col){0, 0, 0});
	cur.prev = prev;
	cur.ray = get_reflection_ray(prev);
	cur.depth = prev->depth + 1;
	if (!intersect(e, &cur))
		return ((t_col){0, 0, 0});
	return (calc_shade(e, &cur, coeff * prev->obj->reflectivity));
}
