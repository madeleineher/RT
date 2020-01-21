/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:39:54 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 23:39:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	v_intersect_sp2(t_ray ray, void *object)
{
	t_sphere	*sphere;
	t_vec3		v;
	double		a;
	double		b;
	double		c;

	sphere = (t_sphere *)object;
	v = v3_frompoints(sphere->cen, ray.ori);
	a = v3_dotpdt(ray.dir, ray.dir);
	b = 2 * v3_dotpdt(ray.dir, v);
	c = v3_dotpdt(v, v) - sphere->radius * sphere->radius;
	return (find_closest_intersection(a, b, c));
}

t_vec3	normal_sphere(t_ray ray, void *object)
{
	t_sphere	*sphere;
	t_vec3		normal;
	t_vec3		point;

	sphere = object;
	point = find_point_from_ray(ray);
	normal = v3_frompoints(sphere->cen, point);
	normal = v3_normalise(normal);
	return (normal);
}
