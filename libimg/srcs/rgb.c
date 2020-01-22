/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:43 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:15:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

t_im_rgb		im_hex2rgb(unsigned int hex)
{
	unsigned int	i;
	t_im_rgb		rgb;

	i = 2;
	while (i >= 1)
	{
		rgb.arr[i] = hex & 0xff;
		hex >>= 8;
		i--;
	}
	rgb.arr[0] = hex & 0xff;
	return (rgb);
}

unsigned int	im_rgb2hex(t_im_rgb *rgb)
{
	unsigned int	i;
	unsigned int	hex;

	hex = 0;
	i = 0;
	while (i < 2)
	{
		hex += rgb->arr[i];
		hex <<= 8;
		i++;
	}
	hex += rgb->arr[2];
	return (hex);
}

unsigned int	im_reverse_hex_color(unsigned int hex)
{
	unsigned int	res;

	res = 0;
	res += (hex & 0xff0000) >> 16;
	res += (hex & 0x00ff00);
	res += (hex & 0x0000ff) << 16;
	return (res);
}

void			im_reverse_color_pixels(void *arg_void)
{
	unsigned int	i;
	unsigned int	*buf;
	t_im_arg_th		*arg;

	arg = (t_im_arg_th *)arg_void;
	buf = (unsigned int *)arg->buf[0] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		buf[i] = im_reverse_hex_color(buf[i]);
		i++;
	}
}
