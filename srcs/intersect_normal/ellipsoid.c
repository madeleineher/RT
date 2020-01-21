/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:51:33 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 23:46:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_t(t_ray ray, t_ellipsoid *ell, t_vec3 v)
{
	double	a;
	double	b;
	double	c;
	double	a1;
	double	a2;

	a1 = 2 * ell->d * v3_dotpdt(ray.dir, ell->axis);
	a2 = ell->sum * ell->sum + 2 * ell->d * v3_dotpdt(v, ell->axis) - ell->d;
	a = 4 * ell->sum * ell->sum * v3_dotpdt(ray.dir, ray.dir) - a1 * a1;
	b = 2 * (4 * ell->sum * ell->sum * v3_dotpdt(ray.dir, v) - a1 * a2);
	c = 4 * ell->sum * ell->sum * v3_dotpdt(v, v) - a2 * a2;
	return (find_closest_intersection(a, b, c));
}

double			v_intersect_ellipsoid(t_ray ray, void *object)
{
	t_vec3			v;
	t_ellipsoid		*ell;

	ell = object;
	v = v3_frompoints(ell->cen, ray.ori);
	ell->axis = v3_normalise(ell->axis);
	return (get_t(ray, ell, v));
}

t_vec3			normal_ellipsoid(t_ray ray, void *object)
{
	t_vec3			p;
	t_vec3			cmid;
	t_vec3			n;
	t_ellipsoid		*ell;

	ell = object;
	cmid = v3_add(ell->cen, v3_scalar(ell->axis, ell->d / 2));
	p = find_point_from_ray(ray);
	n = v3_normalise(v3_frompoints(cmid, p));
	return (n);
}
