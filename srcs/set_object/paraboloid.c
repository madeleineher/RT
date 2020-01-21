/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:38:52 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:04:39 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_paraboloid *arg)
{
	if (v3_norm2(arg->axis) < RT_APPROX_0)
		return (handle_fail("set_paraboloid : axis's length almost 0"));
	if (arg->k <= 0.0)
		return (handle_fail("set_paraboloid : k 0 or below 0"));
	if (arg->min < 0.0)
		return (handle_fail("set_paraboloid : min below 0"));
	if (arg->min >= arg->max)
		return (handle_fail("set_paraboloid : min bigger than max"));
	return (RT_SUCCESS);
}

int				set_paraboloid(t_ol *ol, t_arg_paraboloid *arg)
{
	t_paraboloid	*paraboloid;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_paraboloid;
	ol->get_normal = &normal_paraboloid;
	ol->uv_mapping = NULL;
	ol->translate = &paraboloid_translate;
	ol->rotate = &paraboloid_rotate;
	paraboloid = (t_paraboloid *)ol->object;
	paraboloid->cen = arg->cen;
	paraboloid->axis = v3_normalise(arg->axis);
	paraboloid->k = arg->k;
	paraboloid->min = arg->min;
	paraboloid->max = arg->max;
	pick_axis_from_plane(&paraboloid->axis, &ol->axis_mat);
	return (RT_SUCCESS);
}
