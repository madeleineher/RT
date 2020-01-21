/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:39:40 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 23:39:41 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	find_closest_intersection1(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		return (t1);
	}
}

static double	find_closest_intersection2(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FAR);
	else
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		return (t2);
	}
}

static double	get_t(t_ray ray, t_cyl *cyl, t_vec3 v)
{
	double	a;
	double	b;
	double	c;
	double	m;
	double	t[2];

	a = v3_dotpdt(ray.dir, ray.dir)\
		- v3_dotpdt(ray.dir, cyl->axis) * v3_dotpdt(ray.dir, cyl->axis);
	b = 2 * (v3_dotpdt(ray.dir, v)\
		- v3_dotpdt(ray.dir, cyl->axis) * v3_dotpdt(v, cyl->axis));
	c = v3_dotpdt(v, v) - v3_dotpdt(v, cyl->axis) * v3_dotpdt(v, cyl->axis)\
		- cyl->radius * cyl->radius;
	t[0] = find_closest_intersection1(a, b, c);
	t[1] = find_closest_intersection2(a, b, c);
	m = v3_dotpdt(ray.dir, cyl->axis) * t[0] + v3_dotpdt(v, cyl->axis);
	if (m > cyl->height || m < -cyl->height)
		t[0] = FAR;
	m = v3_dotpdt(ray.dir, cyl->axis) * t[1] + v3_dotpdt(v, cyl->axis);
	if (m > cyl->height || m < -cyl->height)
		t[1] = FAR;
	if (t[0] <= 0 && t[1] <= 0)
		return (FAR);
	t[0] = t[0] > 0 ? t[0] : t[1];
	t[0] = t[1] < t[0] && t[1] > 0 ? t[1] : t[0];
	return (t[0]);
}

double			v_intersect_cy(t_ray ray, void *object)
{
	t_vec3	v;
	t_cyl	*cyl;

	cyl = object;
	v = v3_frompoints(cyl->cen, ray.ori);
	return (get_t(ray, cyl, v));
}

t_vec3			normal_cylinder(t_ray ray, void *object)
{
	t_vec3	v;
	t_vec3	n;
	double	m;
	t_cyl	*cyl;

	cyl = object;
	v = v3_frompoints(cyl->cen, ray.ori);
	m = ray.t * v3_dotpdt(ray.dir, cyl->axis) + v3_dotpdt(v, cyl->axis);
	n.x = ray.ori.x + ray.dir.x * ray.t - cyl->cen.x - m * cyl->axis.x;
	n.y = ray.ori.y + ray.dir.y * ray.t - cyl->cen.y - m * cyl->axis.y;
	n.z = ray.ori.z + ray.dir.z * ray.t - cyl->cen.z - m * cyl->axis.z;
	n = v3_normalise(n);
	return (n);
}
