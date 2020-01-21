/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:03 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:07:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		pick_axis_from_plane(t_vec3 *normal, t_mat3 *axis_mat)
{
	static t_vec3	xw = (t_vec3){1.0, 0.0, 0.0};
	static t_vec3	yw = (t_vec3){0.0, 1.0, 0.0};
	t_vec3			x;
	t_vec3			z;

	x = v3_cross(*normal, xw);
	if (v3_norm2(x) < RT_APPROX_0)
		x = v3_cross(*normal, yw);
	x = v3_normalise(x);
	z = v3_cross(x, *normal);
	ft_memcpy(axis_mat->arr[0], &x, sizeof(t_vec3));
	ft_memcpy(axis_mat->arr[1], normal, sizeof(t_vec3));
	ft_memcpy(axis_mat->arr[2], &z, sizeof(t_vec3));
}

int			validate_commons(t_ol *ol)
{
	int			i;
	double		*ptr;

	if (ol->reflectivity < 0.0 || ol->reflectivity > 1.0)
		return (handle_fail("check_commons : wrong reflectivity"));
	if (ol->transparency < 0.0 || ol->transparency > 1.0)
		return (handle_fail("check_commons : wrong transparency"));
	if (ol->ior < 1.5 || ol->ior > 2.65)
		return (handle_fail("check_commons : wrong ior"));
	if (ol->specpower < 0.0)
		return (handle_fail("check_commons : wrong specpower"));
	if (ol->specvalue < 0.0)
		return (handle_fail("check_commons : wrong specvalue"));
	ptr = (double *)&ol->dif;
	i = 0;
	while (i < 3)
	{
		if (ptr[i] < 0.0 || ptr[i] > 255.0)
			return (handle_fail("check_commons : wrong dif"));
		i++;
	}
	return (RT_SUCCESS);
}
