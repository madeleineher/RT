/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img2buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:39 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"

int				im_img2buffer_info(
	const char *filename,
	t_im_buffer_info *buf_info
)
{
	buf_info->buf[0] = stbi_load(
		filename, &buf_info->width, &buf_info->height, NULL, STBI_rgb_alpha);
	if (buf_info->buf[0] == NULL)
		return (im_handle_err("Fail to load image"));
	im_set_buffer_info(buf_info->width, buf_info->height, buf_info);
	if (im_for_each_pixel(buf_info, &im_reverse_color_pixels) == IM_FAIL)
		return (IM_FAIL);
	return (IM_SUCCESS);
}
