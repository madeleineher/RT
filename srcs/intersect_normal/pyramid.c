/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:32 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			v_intersect_pyramid(t_ray ray, void *object)
{
	int			i;
	double		t[2];
	t_pyramid	*pyramid;

	pyramid = (t_pyramid *)object;
	t[0] = FAR;
	i = 0;
	while (i < 4)
	{
		t[1] = v_intersect_triangle(ray, (void *)(pyramid->sides + i));
		if (t[1] > 0.0 && t[1] < t[0])
			t[0] = t[1];
		i++;
	}
	return (t[0]);
}

static void		set_ray_to_pyramid_coordinate(t_pyramid *pyramid, t_ray *ray)
{
	t_vec3		y_axis;
	t_vec3		temp;

	y_axis = v3_cross(pyramid->v, pyramid->u);
	temp = v3_sub(ray->ori, pyramid->sides[0].a);
	ray->ori.x = v3_dotpdt(pyramid->u, temp);
	ray->ori.y = v3_dotpdt(y_axis, temp);
	ray->ori.z = v3_dotpdt(pyramid->v, temp);
	temp = ray->dir;
	ray->dir.x = v3_dotpdt(pyramid->u, temp);
	ray->dir.y = v3_dotpdt(y_axis, temp);
	ray->dir.z = v3_dotpdt(pyramid->v, temp);
}

static int		get_intersect_side_index(t_vec3 *point, t_pyramid *pyramid)
{
	int			side_index;
	double		delta;
	double		delta_ad;

	if (point->x == 0.0)
		return (2);
	if (point->x == pyramid->norm_u)
		return (1);
	delta = point->z / point->x;
	delta_ad = pyramid->norm_v / pyramid->norm_u;
	side_index = (delta > delta_ad) ? 2 : 0;
	delta = point->z / (pyramid->norm_u - point->x);
	if (delta > delta_ad)
		side_index++;
	return (side_index);
}

t_vec3			normal_pyramid(t_ray ray, void *object)
{
	int			side_index;
	t_vec3		point;
	t_ray		ray_transformed;
	t_pyramid	*pyramid;

	pyramid = (t_pyramid *)object;
	ray_transformed = ray;
	set_ray_to_pyramid_coordinate(pyramid, &ray_transformed);
	point = find_point_from_ray(ray_transformed);
	side_index = get_intersect_side_index(&point, pyramid);
	return (normal_triangle(ray, pyramid->sides + side_index));
}
