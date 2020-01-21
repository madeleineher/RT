/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:51 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:31:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec2	get_bump(t_vec2 *uv, t_texels *texels)
{
	int			index;
	int			texel;
	t_vec2		bump;

	index = uv_to_texel_index(uv, texels);
	texel = texels->buffer[index] & 0xff;
	if (index % texels->width == texels->width - 1)
		bump.x = 0.0;
	else
		bump.x = (int)(texels->buffer[index + 1] & 0xff) - texel;
	if (index / texels->width == texels->width - 1)
		bump.y = 0.0;
	else
		bump.y = (int)(texels->buffer[index + texels->width] & 0xff)
			- texel;
	bump.x *= 0.02;
	bump.y *= 0.02;
	return (bump);
}

t_vec3			get_bumped_normal(
	t_vec2 *uv,
	t_texels *texels,
	t_vec3 *normal,
	t_mat3 *axis_mat
)
{
	t_vec2		bump;
	t_vec3		tangents[2];
	t_vec3		res;

	bump = get_bump(uv, texels);
	if (ft_abs_double(v3_dotpdt(*normal, *(t_vec3 *)(axis_mat->arr[1]))) >= 1.0)
	{
		tangents[0] = *(t_vec3 *)(axis_mat->arr[0]);
		tangents[1] = *(t_vec3 *)(axis_mat->arr[2]);
	}
	else
	{
		tangents[0] = v3_cross(*normal, *(t_vec3 *)(axis_mat->arr[1]));
		tangents[0] = v3_normalise(tangents[0]);
		tangents[1] = v3_cross(*normal, tangents[0]);
	}
	res = v3_sub(*normal,
		v3_add(v3_scalar(tangents[0], bump.x), v3_scalar(tangents[1], bump.y)));
	return (v3_normalise(res));
}
