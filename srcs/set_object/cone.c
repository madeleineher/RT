/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:06 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:04:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_cone *arg)
{
	if (arg->angle <= 0.0 || arg->angle >= 90)
		return (handle_fail("set_cone : angle out of 0 ~ 90"));
	if (v3_norm2(arg->axis) < RT_APPROX_0)
		return (handle_fail("set_cone : axis's length almost 0"));
	if (arg->upper_height < 0.0)
		return (handle_fail("set_cone : upper_height below 0"));
	if (arg->lower_height < 0.0)
		return (handle_fail("set_cone : lower_height below 0"));
	if (arg->upper_height < RT_APPROX_0 && arg->lower_height < RT_APPROX_0)
		return (handle_fail("set_cone : upper and lower height both almost 0"));
	return (RT_SUCCESS);
}

int				set_cone(t_ol *ol, t_arg_cone *arg)
{
	t_cone		*cone;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_co;
	ol->get_normal = &normal_cone;
	ol->uv_mapping = &cone_uv_mapping;
	ol->translate = &cone_translate;
	ol->rotate = &cone_rotate;
	cone = (t_cone *)ol->object;
	cone->cen = arg->cen;
	cone->axis = v3_normalise(arg->axis);
	cone->angle = arg->angle;
	cone->upper_height = arg->upper_height;
	cone->lower_height = arg->lower_height;
	pick_axis_from_plane(&cone->axis, &ol->axis_mat);
	return (RT_SUCCESS);
}
