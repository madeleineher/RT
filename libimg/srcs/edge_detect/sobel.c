/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sobel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:07:08 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:09:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static float		get_gradient_x(
	unsigned int *buf,
	int width
)
{
	float	gradient;

	gradient = (float)(*(buf + 2) & 0x0000ff) -
		(*buf & 0x0000ff);
	gradient += 2.0 * ((float)(*(buf + width + 2) & 0x0000ff) -
		(*(buf + width) & 0x0000ff));
	gradient += (float)(*(buf + 2 * width + 2) & 0x0000ff) -
		(*(buf + 2 * width) & 0x0000ff);
	return (gradient);
}

static float		get_gradient_y(
	unsigned int *buf,
	int width
)
{
	float	gradient;

	gradient = (float)(*(buf + 2 * width) & 0x0000ff) -
		(*buf & 0x0000ff);
	gradient += 2.0 * ((float)(*(buf + 2 * width + 1) & 0x0000ff) -
		(*(buf + 1) & 0x0000ff));
	gradient += (float)(*(buf + 2 * width + 2) & 0x0000ff) -
		(*(buf + 2) & 0x0000ff);
	return (gradient);
}

static void			filter(void *arg_void)
{
	unsigned int		i;
	float				g[2];
	t_im_arg_th			*arg;
	unsigned int		*img_buf;
	t_im_edge_gradient	*grad_buf;

	arg = (t_im_arg_th *)arg_void;
	grad_buf = (t_im_edge_gradient *)arg->buf[0] + arg->offset;
	img_buf = (unsigned int *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		g[0] = get_gradient_x(&img_buf[i], arg->width);
		g[1] = get_gradient_y(&img_buf[i], arg->width);
		grad_buf[i + arg->width + 1].theta = atan(g[1] / g[0]);
		if (ft_is_nan(grad_buf[i + arg->width + 1].theta))
			grad_buf[i + arg->width + 1].theta = 0.0f;
		grad_buf[i + arg->width + 1].magnitude =
			sqrtf(g[0] * g[0] + g[1] * g[1]);
		if (i % arg->width >= arg->width - 3)
			i += 3;
		else
			i++;
	}
}

int					im_sobel(
	unsigned int *img_buf,
	t_im_edge_gradient *grad_buf,
	int width,
	int height
)
{
	t_im_buffer_info	buf_info;

	if (width < 3 || height < 3)
		return (im_handle_err("Image is too small to sobel filter"));
	buf_info.buf[0] = (unsigned char *)grad_buf;
	ft_bzero(buf_info.buf[0], sizeof(t_im_edge_gradient) * width * height);
	buf_info.buf[1] = (unsigned char *)img_buf;
	im_set_buffer_info(width, height - 2, &buf_info);
	if (im_for_each_pixel(&buf_info, (void *)&filter))
		return (IM_FAIL);
	return (IM_SUCCESS);
}
