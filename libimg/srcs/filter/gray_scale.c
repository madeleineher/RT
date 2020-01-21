/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gray_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:49 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void			filter(void *arg_void)
{
	unsigned int	i;
	unsigned int	hex;
	t_im_rgb		rgb;
	unsigned int	*buf;
	t_im_arg_th		*arg;

	arg = (t_im_arg_th *)arg_void;
	buf = (unsigned int *)arg->buf[0] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		rgb = im_hex2rgb(buf[i]);
		hex = rgb.arr[0] * 0.21 + rgb.arr[1] * 0.72 + rgb.arr[2] * 0.07;
		hex = (hex > 0xff) ? 0xff : hex;
		buf[i] = 0;
		buf[i] += hex;
		buf[i] <<= 8;
		buf[i] += hex;
		buf[i] <<= 8;
		buf[i] += hex;
		i++;
	}
}

int					im_gray_scale(
	unsigned int *buffer,
	int width,
	int height
)
{
	t_im_buffer_info	buf_info;

	buf_info.buf[0] = (unsigned char *)buffer;
	im_set_buffer_info(width, height, &buf_info);
	return (im_for_each_pixel(&buf_info, (void *)&filter));
}
