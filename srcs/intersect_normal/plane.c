/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:40:36 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 23:39:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec3	find_point_on_plane(t_plane *plane)
{
	t_vec3	c;
	t_vec3	normal;

	normal = v3_normalise(plane->normal);
	c.x = plane->normal.x * (double)plane->d / v3_norm2(plane->normal);
	c.y = plane->normal.y * (double)plane->d / v3_norm2(plane->normal);
	c.z = plane->normal.z * (double)plane->d / v3_norm2(plane->normal);
	return (c);
}

double			v_intersect_pl(t_ray ray, void *object)
{
	t_vec3	c;
	t_vec3	v;
	t_vec3	norm;
	double	t;
	t_plane	*plane;

	plane = object;
	norm = v3_normalise(plane->normal);
	c = find_point_on_plane(plane);
	v = v3_frompoints(c, ray.ori);
	if (v3_dotpdt(ray.dir, norm) == 0)
		return (FAR);
	t = -v3_dotpdt(v, norm) / v3_dotpdt(ray.dir, norm);
	if (t <= 0)
		return (FAR);
	return (t);
}

t_vec3			normal_plane(t_ray ray, void *object)
{
	t_plane	*plane;
	t_vec3	normal;

	plane = object;
	if (v3_dotpdt(ray.dir, v3_normalise(plane->normal)) <= 0)
		normal = v3_scalar(plane->normal, 1);
	else
		normal = v3_scalar(plane->normal, -1);
	return (v3_normalise(normal));
}
