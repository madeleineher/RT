/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:43 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 02:15:12 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec2			cyl_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
)
{
	t_vec2		uv;
	t_cyl		*cyl;

	cyl = (t_cyl *)object;
	point = v3_sub(point, cyl->cen);
	point = m_mult(*axis_mat, point);
	uv.x = acos(point.x / cyl->radius) / (2.0 * M_PI) * texels->repeat;
	if (ft_is_inf(cyl->height))
		uv.y = (point.y + cyl->height) /
			(texels->height * 2.0 * M_PI / texels->width)
			* texels->repeat;
	else
		uv.y = (point.y + cyl->height) / (2 * cyl->height * texels->repeat);
	return (uv);
}
