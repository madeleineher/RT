/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:53 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 01:26:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		uv_to_texel_index(t_vec2 *uv, t_texels *texels)
{
	int		img_coord[2];
	double	int_part;

	if (ft_is_nan(uv->x))
		uv->x = 1.0;
	if (ft_is_nan(uv->y))
		uv->y = 1.0;
	uv->x = modf(uv->x, &int_part);
	uv->y = modf(uv->y, &int_part);
	img_coord[0] = uv->x * (texels->width - 1);
	img_coord[1] = uv->y * (texels->height - 1);
	return (img_coord[0] + img_coord[1] * texels->width);
}
