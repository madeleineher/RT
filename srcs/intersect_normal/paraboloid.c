/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:51:53 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 22:59:01 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	v_intersect_paraboloid(t_ray ray, void *object)
{
	t_vec3			v;
	double			a;
	double			b;
	double			c;
	t_paraboloid	*para;

	para = object;
	v = v3_frompoints(para->cen, ray.ori);
	para->axis = v3_normalise(para->axis);
	a = v3_dotpdt(ray.dir, ray.dir) - \
		v3_dotpdt(ray.dir, para->axis) * v3_dotpdt(ray.dir, para->axis);
	b = 2 * (v3_dotpdt(ray.dir, v) - \
		v3_dotpdt(ray.dir, para->axis) *
		(v3_dotpdt(v, para->axis) + 2 * para->k));
	c = v3_dotpdt(v, v) - 1\
		* v3_dotpdt(v, para->axis) * (v3_dotpdt(v, para->axis) + 4 * para->k);
	return (find_closest_intersection(a, b, c));
}

t_vec3	normal_paraboloid(t_ray ray, void *object)
{
	double			m;
	t_vec3			p;
	t_vec3			v;
	t_vec3			n;
	t_paraboloid	*para;

	para = object;
	p = find_point_from_ray(ray);
	v = v3_frompoints(para->cen, ray.ori);
	m = v3_dotpdt(v3_frompoints(para->cen, p), para->axis);
	n.x = p.x - para->cen.x - para->axis.x * (m + para->k);
	n.y = p.y - para->cen.y - para->axis.y * (m + para->k);
	n.z = p.z - para->cen.z - para->axis.z * (m + para->k);
	return (v3_normalise(n));
}
