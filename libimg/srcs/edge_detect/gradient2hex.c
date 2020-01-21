/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient2hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:59 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:07:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void		gradient2ratio(void *arg_void)
{
	unsigned int		i;
	float				*gmax;
	t_im_edge_gradient	*grad_buf;
	t_im_arg_th			*arg;

	arg = (t_im_arg_th *)arg_void;
	grad_buf = (t_im_edge_gradient *)arg->buf[0] + arg->offset;
	gmax = (float *)arg->buf[1];
	i = 0;
	if (*gmax == 0.0f)
	{
		while (i < arg->worksize)
		{
			grad_buf[i].magnitude = 0.0f;
			i++;
		}
	}
	else
	{
		while (i < arg->worksize)
		{
			grad_buf[i].magnitude /= *gmax;
			i++;
		}
	}
}

int				im_gradient2ratio(
	t_im_edge_gradient *grad_buf,
	int width,
	int height,
	float gmax
)
{
	t_im_buffer_info	buf_info;

	im_set_buffer_info(width, height, &buf_info);
	buf_info.buf[0] = (unsigned char *)grad_buf;
	buf_info.buf[1] = (unsigned char *)&gmax;
	return (im_for_each_pixel(&buf_info, gradient2ratio));
}
