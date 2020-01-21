/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer2img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:27 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"
#include "stb_image.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.hpp"

static void		remove_alpha(void *arg_void)
{
	t_im_arg_th		*arg;
	unsigned int	i;
	unsigned int	stride;
	unsigned int	*data_buf;
	unsigned char	*bmp_buf;

	arg = (t_im_arg_th *)arg_void;
	stride = sizeof(unsigned char) * 3;
	data_buf = (unsigned int *)arg->buf[0] + arg->offset;
	bmp_buf = arg->buf[1] + stride * arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		bmp_buf[0] = (data_buf[i] & 0x00ff0000) >> 16;
		bmp_buf[1] = (data_buf[i] & 0x0000ff00) >> 8;
		bmp_buf[2] = data_buf[i] & 0x000000ff;
		bmp_buf += stride;
		i++;
	}
}

int				im_buffer2bmp(
	const char *output_name,
	t_im_buffer_info *buf_info
)
{
	unsigned int	num_pixels;

	num_pixels = buf_info->width * buf_info->height;
	if ((buf_info->buf[1] = malloc(
		sizeof(unsigned char) * 3 * num_pixels)) == NULL)
		return (im_handle_err("Fail to malloc buf[1]"));
	if (im_for_each_pixel(buf_info, &remove_alpha) == IM_FAIL)
	{
		ft_memdel((void **)&buf_info->buf[1]);
		return (IM_FAIL);
	}
	if (stbi_write_bmp(
		output_name, buf_info->width, buf_info->height,
		STBI_rgb, buf_info->buf[1]) == 0)
	{
		ft_memdel((void **)&buf_info->buf[1]);
		return (im_handle_err("Fail to write bmp file"));
	}
	ft_memdel((void **)&buf_info->buf[1]);
	return (IM_SUCCESS);
}

int				im_buffer2jpg(
	const char *output_name,
	t_im_buffer_info *buf_info
)
{
	unsigned int	num_pixels;

	num_pixels = buf_info->width * buf_info->height;
	if (im_for_each_pixel(buf_info, &im_reverse_color_pixels) == IM_FAIL)
		return (IM_FAIL);
	if (stbi_write_jpg(
		output_name, buf_info->width, buf_info->height,
		STBI_rgb_alpha, buf_info->buf[0], 100) == 0)
		return (im_handle_err("Fail to write jpg file"));
	return (IM_SUCCESS);
}
