/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_maximum_suppression.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:07:06 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:08:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void		get_neighbors(
	t_im_edge_gradient *p,
	int width,
	t_im_edge_gradient **neighbors
)
{
	static float	deg_for_1rad = 180.0 / M_PI;
	float			rounded;

	rounded = round(p->theta * deg_for_1rad / 45.0);
	if ((rounded > -2.1 && rounded < -1.9) ||
		(rounded > 1.9 && rounded < 2.0))
	{
		neighbors[0] = p + width;
		neighbors[1] = p - width;
	}
	else if (rounded > -1.1 && rounded < -0.9)
	{
		neighbors[0] = p - width + 1;
		neighbors[1] = p + width - 1;
	}
	else if (rounded > -0.1 && rounded < 0.1)
	{
		neighbors[0] = p + 1;
		neighbors[1] = p - 1;
	}
	else
	{
		neighbors[0] = p + width + 1;
		neighbors[1] = p - width - 1;
	}
}

static void		suppress(void *arg_void)
{
	unsigned int		i;
	t_im_edge_gradient	*neighbors[2];
	t_im_edge_gradient	*buf[2];
	t_im_edge_gradient	*p;
	t_im_arg_th			*arg;

	arg = (t_im_arg_th *)arg_void;
	buf[0] = (t_im_edge_gradient *)arg->buf[0] + arg->offset;
	buf[1] = (t_im_edge_gradient *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		p = buf[1] + i + arg->width + 1;
		get_neighbors(p, arg->width, (t_im_edge_gradient **)neighbors);
		if (p->magnitude < neighbors[0]->magnitude ||
			p->magnitude < neighbors[1]->magnitude)
			buf[0][i + arg->width + 1].magnitude = 0.0f;
		if (i % arg->width >= arg->width - 3)
			i += 3;
		else
			i++;
	}
}

int				im_non_maximum_suppression(
	t_im_edge_gradient *grad_buf,
	int width,
	int height
)
{
	size_t				buf_size;
	t_im_buffer_info	buf_info;

	if (width < 3 || height < 3)
		return (im_handle_err("Image is too small to non maximum_suppression"));
	buf_size = sizeof(t_im_edge_gradient) * width * height;
	if ((buf_info.buf[1] = ft_memalloc(buf_size)) == NULL)
		return (im_handle_err("Fail to malloc buf[1]"));
	ft_memcpy(buf_info.buf[1], grad_buf, buf_size);
	buf_info.buf[0] = (unsigned char *)grad_buf;
	im_set_buffer_info(width, height - 2, &buf_info);
	if (im_for_each_pixel(&buf_info, (void *)suppress) == IM_FAIL)
	{
		ft_memdel((void **)&buf_info.buf[1]);
		return (IM_FAIL);
	}
	ft_memdel((void **)&buf_info.buf[1]);
	return (IM_SUCCESS);
}
