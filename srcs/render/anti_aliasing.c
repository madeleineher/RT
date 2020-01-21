/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:47 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static unsigned int		average_hex(unsigned int *p, int width)
{
	int				i;
	unsigned int	hex;
	t_im_rgb		rgb[4];

	rgb[0] = im_hex2rgb(*p);
	rgb[1] = im_hex2rgb(*(p + 1));
	rgb[2] = im_hex2rgb(*(p + width));
	rgb[3] = im_hex2rgb(*(p + width + 1));
	hex = 0;
	i = 0;
	while (i < 2)
	{
		hex += (rgb[0].arr[i] + rgb[1].arr[i] +
			rgb[2].arr[i] + rgb[3].arr[i]) / 4;
		hex <<= 8;
		i++;
	}
	hex += (rgb[0].arr[i] + rgb[1].arr[i] +
		rgb[2].arr[i] + rgb[3].arr[i]) / 4;
	return (hex);
}

static void				average(void *arg_void)
{
	unsigned int	i;
	unsigned int	*after;
	unsigned int	*before;
	t_im_arg_th		*arg;

	arg = (t_im_arg_th *)arg_void;
	after = (unsigned int *)arg->buf[0] + arg->offset;
	before = (unsigned int *)arg->buf[1] + arg->offset * 4;
	i = 0;
	while (i < arg->worksize)
	{
		after[i] = average_hex(before + (i % arg->width) * 2, arg->width * 2);
		if (i % arg->width == arg->width - 1)
			before += arg->width * 4;
		i++;
	}
}

int						anti_aliasing(
	unsigned int *after,
	unsigned int *before,
	int width,
	int height
)
{
	t_im_buffer_info	buf_info;

	im_set_buffer_info(width, height, &buf_info);
	buf_info.buf[0] = (unsigned char *)after;
	buf_info.buf[1] = (unsigned char *)before;
	if (im_for_each_pixel(&buf_info, &average) == IM_FAIL)
		return (handle_fail("anti_aliasing : average"));
	return (RT_SUCCESS);
}
