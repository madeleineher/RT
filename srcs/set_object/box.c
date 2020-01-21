/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:00 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:01:18 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_box *arg)
{
	if (v3_norm2(arg->a) < RT_APPROX_0)
		return (handle_fail("set_box : a's length almost 0"));
	if (v3_norm2(arg->b) < RT_APPROX_0)
		return (handle_fail("set_box : b's length almost 0"));
	if (ft_abs_double(v3_dotpdt(arg->a, arg->b)) > RT_APPROX_0)
		return (handle_fail("set_box : a, b not orthogonal"));
	if (arg->norm_c < RT_APPROX_0)
		return (handle_fail("set_box : c's norm almost 0"));
	return (RT_SUCCESS);
}

static void		set_axis(t_arg_box *arg, t_mat3 *axis_mat)
{
	t_vec3		v;

	v = v3_normalise(arg->a);
	ft_memcpy(axis_mat->arr[0], &v, sizeof(t_vec3));
	v = v3_normalise(arg->b);
	ft_memcpy(axis_mat->arr[1], &v, sizeof(t_vec3));
	v = v3_cross(*(t_vec3 *)(axis_mat->arr[0]), *(t_vec3 *)(axis_mat->arr[1]));
	ft_memcpy(axis_mat->arr[2], &v, sizeof(t_vec3));
}

int				set_box(t_ol *ol, t_arg_box *arg)
{
	t_box		*box;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_box;
	ol->get_normal = &normal_box;
	ol->uv_mapping = NULL;
	ol->translate = &box_translate;
	ol->rotate = &box_rotate;
	box = (t_box *)ol->object;
	box->vmin = arg->vmin;
	box->vmax.x = v3_norm(arg->a);
	box->vmax.y = v3_norm(arg->b);
	box->vmax.z = arg->norm_c;
	set_axis(arg, &ol->axis_mat);
	box->axis_mat = ol->axis_mat;
	return (RT_SUCCESS);
}
