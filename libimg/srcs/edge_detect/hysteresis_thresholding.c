/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hysteresis_thresholding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:07:01 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:12:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void		horizontal_visit(
	size_t i,
	float magnitude,
	t_im_buffer_info *buf_info,
	float *t
)
{
	int					det;
	t_im_edge_gradient	*grad_buf;
	char				*visit_buf;

	grad_buf = (t_im_edge_gradient *)buf_info->buf[0];
	visit_buf = (char *)buf_info->buf[1];
	det = i % buf_info->width;
	if (det != 0 &&
		grad_buf[i - 1].magnitude >= t[0] && grad_buf[i - 1].magnitude <= t[1])
		visit(i - 1, magnitude, buf_info, t);
	if (grad_buf[i].magnitude >= t[0] && grad_buf[i].magnitude <= t[1])
		visit(i, magnitude, buf_info, t);
	if (det != buf_info->width - 1 &&
		grad_buf[i + 1].magnitude >= t[0] && grad_buf[i + 1].magnitude <= t[1])
		visit(i + 1, magnitude, buf_info, t);
}

void			visit(
	size_t i,
	float magnitude,
	t_im_buffer_info *buf_info,
	float *t
)
{
	int					det;
	t_im_edge_gradient	*grad_buf;
	char				*visit_buf;

	grad_buf = (t_im_edge_gradient *)buf_info->buf[0];
	visit_buf = (char *)buf_info->buf[1];
	visit_buf[i] = IM_TRUE;
	grad_buf[i].magnitude = magnitude;
	det = i / buf_info->width;
	if (det != 0)
		horizontal_visit(i - buf_info->width, magnitude, buf_info, t);
	horizontal_visit(i, magnitude, buf_info, t);
	if (det != buf_info->height - 1)
		horizontal_visit(i + buf_info->width, magnitude, buf_info, t);
}

static void		traverse(t_im_buffer_info *buf_info, float *t)
{
	int					i;
	int					j;
	size_t				index;
	t_im_edge_gradient	*grad_buf;
	char				*visit_buf;

	grad_buf = (t_im_edge_gradient *)buf_info->buf[0];
	visit_buf = (char *)buf_info->buf[1];
	i = -1;
	while (++i < buf_info->height)
	{
		j = -1;
		while (++j < buf_info->width)
		{
			index = i * buf_info->width + j;
			if (visit_buf[index])
				continue ;
			visit_buf[index] = IM_TRUE;
			if (grad_buf[index].magnitude < t[0])
				grad_buf[index].magnitude = 0.0f;
			else if (grad_buf[index].magnitude > t[1])
				visit(index, grad_buf[index].magnitude, buf_info, t);
		}
	}
}

static void		clean_weak_edge(void *arg_void)
{
	unsigned int		i;
	float				t;
	t_im_arg_th			*arg;
	t_im_edge_gradient	*grad_buf;

	arg = (t_im_arg_th *)arg_void;
	grad_buf = (t_im_edge_gradient *)arg->buf[0] + arg->offset;
	t = *((float *)arg->buf[1]);
	i = 0;
	while (i < arg->worksize)
	{
		if (grad_buf[i].magnitude < t)
			grad_buf[i].magnitude = 0.0f;
		i++;
	}
}

int				im_hysteresis_thresholding(
	t_im_edge_gradient *grad_buf,
	int width,
	int height,
	float *gmax
)
{
	float				t[2];
	t_im_buffer_info	buf_info;

	if (width < 3 || height < 3)
		return (im_handle_err("Image is too small to hysteresis thresholding"));
	if (im_max_gradient(grad_buf, gmax, width, height) == IM_FAIL)
		return (IM_FAIL);
	if ((buf_info.buf[1] = ft_memalloc(sizeof(char) * width * height)) == NULL)
		return (im_handle_err("Fail to malloc buf[1]"));
	t[1] = *gmax * 0.2f;
	t[0] = t[1] * 0.5f;
	im_set_buffer_info(width, height, &buf_info);
	buf_info.buf[0] = (unsigned char *)grad_buf;
	traverse(&buf_info, (float *)t);
	ft_memdel((void **)&buf_info.buf[1]);
	buf_info.buf[1] = (unsigned char *)&t[1];
	if (im_for_each_pixel(&buf_info, clean_weak_edge) == IM_FAIL)
		return (IM_FAIL);
	return (IM_SUCCESS);
}
