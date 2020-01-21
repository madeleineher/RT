/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:51:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 07:12:52 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	choose_t(t_ray *ray, t_cone *cone, double *t, int need_swap)
{
	int			i;
	double		det;

	if (need_swap)
	{
		det = t[0];
		t[0] = t[1];
		t[1] = det;
	}
	i = -1;
	while (++i < 2)
	{
		if (t[i] < 0.0)
			continue ;
		ray->t = t[i];
		det = v3_dotpdt(
			v3_sub(find_point_from_ray(*ray), cone->cen), cone->axis);
		if (det >= 0.0 && det < cone->lower_height)
			return (t[i]);
		else if (det < 0.0 && det > -cone->upper_height)
			return (t[i]);
	}
	return (FAR);
}

static double	get_t(t_ray ray, t_cone *cone, t_vec3 v, double k)
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	t[2];

	a = v3_dotpdt(ray.dir, ray.dir) - (1 + k * k)\
		* v3_dotpdt(ray.dir, cone->axis) * v3_dotpdt(ray.dir, cone->axis);
	b = 2 * (v3_dotpdt(ray.dir, v) - (1 + k * k)\
		* (v3_dotpdt(ray.dir, cone->axis) * v3_dotpdt(v, cone->axis)));
	c = v3_dotpdt(v, v) - (1 + k * k)\
		* v3_dotpdt(v, cone->axis) * v3_dotpdt(v, cone->axis);
	det = b * b - 4 * a * c;
	if (det < 0.0)
		return (FAR);
	det = sqrt(det);
	t[0] = (-b + det) / (2 * a);
	t[1] = (-b - det) / (2 * a);
	return (choose_t(&ray, cone, t, a > 0.0));
}

double			v_intersect_co(t_ray ray, void *object)
{
	t_vec3	v;
	double	k;
	t_cone	*cone;

	cone = object;
	v = v3_frompoints(cone->cen, ray.ori);
	k = tan(((cone->angle * M_PI) / 180) / 2);
	return (get_t(ray, cone, v, k));
}

t_vec3			normal_cone(t_ray ray, void *object)
{
	t_vec3	p;
	t_vec3	n;
	double	k;
	double	m;
	t_cone	*cone;

	cone = object;
	p = find_point_from_ray(ray);
	k = tan(((cone->angle * M_PI) / 180) / 2);
	m = ray.t * v3_dotpdt(ray.dir, cone->axis) +
		v3_dotpdt(v3_frompoints(cone->cen, ray.ori), cone->axis);
	n.x = p.x - cone->cen.x - (1 + k * k) * m * cone->axis.x;
	n.y = p.y - cone->cen.y - (1 + k * k) * m * cone->axis.y;
	n.z = p.z - cone->cen.z - (1 + k * k) * m * cone->axis.z;
	return (v3_normalise(n));
}
