/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:45:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			v_intersect_triangle(t_ray ray, void *object)
{
	t_triangle		*triangle;
	double			det_m;
	double			t;
	double			u;
	double			v;

	triangle = (t_triangle *)object;
	ray.dir = v3_scalar(ray.dir, -1.0);
	ray.ori = v3_sub(ray.ori, triangle->a);
	det_m = v3_dotpdt(ray.dir,
		v3_cross(triangle->ab, triangle->ac));
	if (det_m == 0.0)
		return (FAR);
	t = v3_dotpdt(ray.ori,
		v3_cross(triangle->ab, triangle->ac)) / det_m;
	u = v3_dotpdt(ray.dir,
		v3_cross(ray.ori, triangle->ac)) / det_m;
	v = v3_dotpdt(ray.dir,
		v3_cross(triangle->ab, ray.ori)) / det_m;
	if (t < 0.0 || u < 0.0 || v < 0.0 || u + v > 1.0)
		return (FAR);
	return (t);
}

t_vec3			normal_triangle(t_ray ray, void *object)
{
	t_triangle		*triangle;

	triangle = object;
	if (v3_dotpdt(ray.dir, triangle->normal) <= 0)
		return (triangle->normal);
	else
		return (v3_scalar(triangle->normal, -1));
}
