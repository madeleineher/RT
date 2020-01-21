/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canny_edge_detect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:57 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static int		handle_err(t_im_buffer_info *buf_info)
{
	ft_memdel((void **)&buf_info->buf[1]);
	return (IM_FAIL);
}

static int		preprocess(
	unsigned int *buffer,
	int width,
	int height,
	t_im_buffer_info *buf_info
)
{
	im_set_buffer_info(width, height, buf_info);
	buf_info->buf[0] = (unsigned char *)buffer;
	if (im_gray_scale(
		(unsigned int *)buf_info->buf[0], width, height) == IM_FAIL)
		return (IM_FAIL);
	if (im_gaussian_blur(
		(unsigned int *)buf_info->buf[0], width, height) == IM_FAIL)
		return (IM_FAIL);
	return (IM_SUCCESS);
}

int				im_canny_edge_detect(
	unsigned int *img_buf,
	t_im_edge_gradient *grad_buf,
	int width,
	int height
)
{
	float				gmax;
	t_im_buffer_info	buf_info;

	if (preprocess(img_buf, width, height, &buf_info) == IM_FAIL)
		return (handle_err(&buf_info));
	buf_info.buf[1] = (unsigned char *)grad_buf;
	if (im_sobel((unsigned int *)buf_info.buf[0],
		(t_im_edge_gradient *)buf_info.buf[1],
		width, height) == IM_FAIL)
		return (handle_err(&buf_info));
	if (im_non_maximum_suppression(
		(t_im_edge_gradient *)buf_info.buf[1],
		width, height) == IM_FAIL)
		return (handle_err(&buf_info));
	if (im_hysteresis_thresholding(
		(t_im_edge_gradient *)buf_info.buf[1],
		width, height, &gmax) == IM_FAIL)
		return (handle_err(&buf_info));
	if (im_gradient2ratio(
		(t_im_edge_gradient *)buf_info.buf[1],
		width, height, gmax) == IM_FAIL)
		return (handle_err(&buf_info));
	return (IM_SUCCESS);
}
