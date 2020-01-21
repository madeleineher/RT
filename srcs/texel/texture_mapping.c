/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:55 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 01:27:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			get_texel_color(t_vec2 *uv, t_texels *texels)
{
	int				i;
	unsigned int	texel;
	t_vec3			color;

	i = uv_to_texel_index(uv, texels);
	if (i < 0 || i >= texels->width * texels->height)
		i = 0;
	texel = texels->buffer[i];
	color.x = texel & 0x000000ff;
	texel >>= 8;
	color.y = texel & 0x000000ff;
	texel >>= 8;
	color.z = texel & 0x000000ff;
	return (color);
}
