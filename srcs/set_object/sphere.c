/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:23 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:05:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_sphere *arg)
{
	if (arg->radius <= 0.0)
		return (handle_fail("set_sphere : radius 0 or below 0"));
	return (RT_SUCCESS);
}

static void		set_axis(t_mat3 *axis_mat)
{
	static double	axis[9] = {
		-1.0, 0.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, 0.0, -1.0
	};

	ft_memcpy(axis_mat, axis, sizeof(t_mat3));
}

int				set_sphere(t_ol *ol, t_arg_sphere *arg)
{
	t_sphere	*sphere;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_sp2;
	ol->get_normal = &normal_sphere;
	ol->uv_mapping = &sphere_uv_mapping;
	ol->translate = &sphere_translate;
	ol->rotate = &sphere_rotate;
	sphere = (t_sphere *)ol->object;
	sphere->cen = arg->cen;
	sphere->radius = arg->radius;
	set_axis(&ol->axis_mat);
	return (RT_SUCCESS);
}
