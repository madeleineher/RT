/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:08 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:04:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_cyl *arg)
{
	if (arg->radius <= 0)
		return (handle_fail("set_cyl : radius 0 or below 0"));
	if (v3_norm2(arg->axis) < RT_APPROX_0)
		return (handle_fail("set_cyl : axis's length almost 0"));
	if (arg->height <= 0)
		return (handle_fail("set_cyl : height 0 or below 0"));
	return (RT_SUCCESS);
}

int				set_cyl(t_ol *ol, t_arg_cyl *arg)
{
	t_cyl	*cyl;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_cy;
	ol->get_normal = &normal_cylinder;
	ol->uv_mapping = &cyl_uv_mapping;
	ol->translate = &cyl_translate;
	ol->rotate = &cyl_rotate;
	cyl = (t_cyl *)ol->object;
	cyl->cen = arg->cen;
	cyl->axis = v3_normalise(arg->axis);
	cyl->radius = arg->radius;
	cyl->height = arg->height;
	pick_axis_from_plane(&cyl->axis, &ol->axis_mat);
	return (RT_SUCCESS);
}
