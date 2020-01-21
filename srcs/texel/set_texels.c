/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:36:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 14:06:08 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "stb_image.hpp"

static void		concat_dir(char *dest, const char *filename)
{
	ft_strncat(dest, "contents/", 54);
	ft_strncat(dest, filename, 54);
}

int				set_texels(
	const char *filename,
	int repeat,
	t_texels *texels
)
{
	char	filepath[64];

	ft_bzero(filepath, sizeof(char) * 64);
	if (ft_strlen(filename) > 54)
		return (handle_fail("set_texels : filename too long"));
	concat_dir(filepath, filename);
	texels->buffer = (unsigned int *)stbi_load(
		filepath, &texels->width, &texels->height,
		NULL, STBI_rgb_alpha);
	if (texels->buffer == NULL)
		return (handle_fail("set_texels : wrong file"));
	if (repeat <= 0)
		return (handle_fail("set_texels : repeat 0 or below 0"));
	texels->repeat = repeat;
	return (RT_SUCCESS);
}
