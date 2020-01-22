/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:07:04 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:07:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static void		func(void *arg_void)
{
	unsigned int			i;
	float					local_gmax;
	float					*gmax;
	t_im_arg_th				*arg;
	t_im_edge_gradient		*grad_buf;

	arg = (t_im_arg_th *)arg_void;
	grad_buf = (t_im_edge_gradient *)arg->buf[0] + arg->offset;
	local_gmax = -INFINITY;
	i = 0;
	while (i < arg->worksize)
	{
		if (grad_buf[i].magnitude > local_gmax)
			local_gmax = grad_buf[i].magnitude;
		i++;
	}
	pthread_mutex_lock(arg->lock);
	gmax = (float *)arg->buf[1];
	if (local_gmax > *gmax)
		*gmax = local_gmax;
	pthread_mutex_unlock(arg->lock);
}

int				im_max_gradient(
	t_im_edge_gradient *grad_buf,
	float *gmax,
	int width,
	int height
)
{
	t_im_buffer_info	buf_info;

	im_set_buffer_info(width, height, &buf_info);
	buf_info.buf[0] = (unsigned char *)grad_buf;
	*gmax = -INFINITY;
	buf_info.buf[1] = (unsigned char *)gmax;
	if (im_for_each_pixel(&buf_info, func) == IM_FAIL)
		return (IM_FAIL);
	return (IM_SUCCESS);
}
