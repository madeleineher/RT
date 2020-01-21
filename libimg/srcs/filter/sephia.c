/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sephia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:54 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:54 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void			adjust_color(t_im_rgb *rgb)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (rgb->arr[i] > 0xff)
			rgb->arr[i] = 0xff;
		i++;
	}
}

static void			filter(void *arg_void)
{
	unsigned int			i;
	t_im_rgb				rgb;
	t_im_rgb				temp;
	unsigned int			*buf;
	t_im_arg_th				*arg;

	arg = (t_im_arg_th *)arg_void;
	buf = (unsigned int *)arg->buf[0] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		rgb = im_hex2rgb(buf[i]);
		temp = rgb;
		rgb.arr[0] =
			0.393 * temp.arr[0] + 0.769 * temp.arr[1] + 0.189 * temp.arr[2];
		rgb.arr[1] =
			0.349 * temp.arr[0] + 0.686 * temp.arr[1] + 0.168 * temp.arr[2];
		rgb.arr[2] =
			0.272 * temp.arr[0] + 0.534 * temp.arr[1] + 0.131 * temp.arr[2];
		adjust_color(&rgb);
		buf[i] = im_rgb2hex(&rgb);
		i++;
	}
}

int					im_sephia(
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
