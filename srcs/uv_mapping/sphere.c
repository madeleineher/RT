/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:53 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:56 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec2			sphere_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
)
{
	t_vec2		uv;
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	point = v3_sub(point, sphere->cen);
	point = m_mult(*axis_mat, point);
	uv.x = atan2(point.z, point.x) / (2.0 * M_PI) * texels->repeat;
	uv.y = acos(point.y / sphere->radius) / M_PI * texels->repeat;
	return (uv);
}
