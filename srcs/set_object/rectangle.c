/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:18 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:04:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_rectangle *arg)
{
	if (v3_norm2(arg->a) < RT_APPROX_0)
		return (handle_fail("set_rectangle : a's length almost 0"));
	if (v3_norm2(arg->b) < RT_APPROX_0)
		return (handle_fail("set_rectangle : b's length almost 0"));
	if (ft_abs_double(v3_dotpdt(arg->a, arg->b)) > RT_APPROX_0)
		return (handle_fail("set_rectangle : a, b not orthogonal"));
	return (RT_SUCCESS);
}

static void		set_axis(t_arg_rectangle *arg, t_mat3 *axis_mat)
{
	t_vec3		v;

	v = v3_normalise(arg->a);
	ft_memcpy(axis_mat->arr[0], &v, sizeof(t_vec3));
	v = v3_normalise(arg->b);
	ft_memcpy(axis_mat->arr[2], &v, sizeof(t_vec3));
	v = v3_cross(*(t_vec3 *)(axis_mat->arr[2]), *(t_vec3 *)(axis_mat->arr[0]));
	ft_memcpy(axis_mat->arr[1], &v, sizeof(t_vec3));
}

int				set_rectangle(t_ol *ol, t_arg_rectangle *arg)
{
	t_rectangle		*rect;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_rectangle;
	ol->get_normal = &normal_rectangle;
	ol->uv_mapping = &rectangle_uv_mapping;
	ol->translate = &rectangle_translate;
	ol->rotate = &rectangle_rotate;
	rect = (t_rectangle *)ol->object;
	set_axis(arg, &ol->axis_mat);
	rect->p = arg->p;
	rect->norm_a = v3_norm(arg->a);
	rect->norm_b = v3_norm(arg->b);
	rect->a = *(t_vec3 *)(ol->axis_mat.arr[0]);
	rect->b = *(t_vec3 *)(ol->axis_mat.arr[2]);
	rect->normal = *(t_vec3 *)(ol->axis_mat.arr[1]);
	rect->d = v3_dotpdt(rect->p, rect->normal);
	return (RT_SUCCESS);
}
