/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:10 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:04:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_plane *arg)
{
	if (v3_norm2(arg->normal) < RT_APPROX_0)
		return (handle_fail("set_plane : normal's length almost 0"));
	return (RT_SUCCESS);
}

int				set_plane(t_ol *ol, t_arg_plane *arg)
{
	t_plane		*plane;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_pl;
	ol->get_normal = &normal_plane;
	ol->uv_mapping = NULL;
	ol->translate = &plane_translate;
	ol->rotate = &plane_rotate;
	plane = (t_plane *)ol->object;
	plane->normal = v3_normalise(arg->normal);
	plane->d = arg->d;
	pick_axis_from_plane(&plane->normal, &ol->axis_mat);
	return (RT_SUCCESS);
}
