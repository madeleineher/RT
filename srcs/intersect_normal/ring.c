/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:37 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:41:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_plane_intersection_t(t_ray *ray, t_ring *ring)
{
	t_plane			plane;

	plane.normal = ring->normal;
	plane.d = ring->d;
	return (v_intersect_pl(*ray, &plane));
}

double			v_intersect_ring(t_ray ray, void *object)
{
	double		length;
	double		t;
	t_vec3		cp;
	t_ring		*ring;

	ring = (t_ring *)object;
	t = get_plane_intersection_t(&ray, ring);
	if (t == FAR)
		return (FAR);
	ray.t = t;
	cp = v3_sub(find_point_from_ray(ray), ring->center);
	length = v3_norm(cp);
	if (length >= ring->r1 && length <= ring->r2)
		return (t);
	return (FAR);
}

t_vec3			normal_ring(t_ray ray, void *object)
{
	t_ring		*ring;

	ring = (t_ring *)object;
	if (v3_dotpdt(ray.dir, ring->normal) <= 0)
		return (ring->normal);
	else
		return (v3_scalar(ring->normal, -1.0));
}
