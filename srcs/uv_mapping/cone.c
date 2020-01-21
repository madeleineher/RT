/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:41 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec2			cone_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
)
{
	double		height;
	t_vec2		uv;
	t_cone		*cone;

	cone = (t_cone *)object;
	point = v3_sub(point, cone->cen);
	point = m_mult(*axis_mat, point);
	height = (cone->upper_height > cone->lower_height)
		? cone->upper_height
		: cone->lower_height;
	uv.x = atan2(point.z, point.x) / (2 * M_PI) * texels->repeat;
	if (ft_is_inf(height))
		uv.y = point.y / (texels->height * 2.0 * M_PI / texels->width)
			* texels->repeat;
	else
		uv.y = point.y / height * texels->repeat;
	if (uv.y < 0.0)
		uv.y = -uv.y;
	return (uv);
}
