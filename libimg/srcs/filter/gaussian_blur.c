/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaussian_blur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:47 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static t_im_rgb		horizontal_convolution(unsigned int *buf, int *coeffs)
{
	int			i;
	t_im_rgb	rgb_pixel;
	t_im_rgb	res;

	ft_bzero(&res, sizeof(t_im_rgb));
	i = 0;
	while (i < 7)
	{
		rgb_pixel = im_hex2rgb(buf[i]);
		res.arr[0] += coeffs[i] * rgb_pixel.arr[0];
		res.arr[1] += coeffs[i] * rgb_pixel.arr[1];
		res.arr[2] += coeffs[i] * rgb_pixel.arr[2];
		i++;
	}
	return (res);
}

static t_im_rgb		convolution(unsigned int *buf, int width)
{
	static int		coeffs[7] = {1, 6, 15, 20, 15, 6, 1};
	int				i;
	t_im_rgb		conv[7];
	t_im_rgb		res;

	ft_bzero(&res, sizeof(t_im_rgb));
	i = 0;
	while (i < 7)
	{
		conv[i] = horizontal_convolution(buf, (int *)coeffs);
		buf += width;
		i++;
	}
	i = 0;
	while (i < 7)
	{
		res.arr[0] += coeffs[i] * conv[i].arr[0];
		res.arr[1] += coeffs[i] * conv[i].arr[1];
		res.arr[2] += coeffs[i] * conv[i].arr[2];
		i++;
	}
	res.arr[0] /= 4096;
	res.arr[1] /= 4096;
	res.arr[2] /= 4096;
	return (res);
}

static void			blur(void *arg_void)
{
	unsigned int		i;
	t_im_rgb			rgb;
	unsigned int		*buf[2];
	t_im_arg_th			*arg;

	arg = (t_im_arg_th *)arg_void;
	buf[0] = (unsigned int *)arg->buf[0] + arg->offset;
	buf[1] = (unsigned int *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		rgb = convolution(buf[1] + i, arg->width);
		buf[0][i + arg->width * 3 + 3] = im_rgb2hex(&rgb);
		if (i % arg->width >= arg->width - 7)
			i += 7;
		else
			i++;
	}
}

int					im_gaussian_blur(
	unsigned int *buffer,
	int width,
	int height
)
{
	size_t				buf_size;
	t_im_buffer_info	buf_info;

	if (width < 7 || height < 7)
		return (im_handle_err("Image is too small to gaussian blur"));
	buf_size = sizeof(unsigned int) * width * height;
	if ((buf_info.buf[1] = ft_memalloc(buf_size)) == NULL)
		return (im_handle_err("Fail to malloc buf[1]"));
	ft_memcpy(buf_info.buf[1], buffer, buf_size);
	buf_info.buf[0] = (unsigned char *)buffer;
	im_set_buffer_info(width, height - 6, &buf_info);
	if (im_for_each_pixel(&buf_info, (void *)&blur) == IM_FAIL)
	{
		ft_memdel((void **)&buf_info.buf[1]);
		return (IM_FAIL);
	}
	ft_memdel((void **)&buf_info.buf[1]);
	return (IM_SUCCESS);
}
