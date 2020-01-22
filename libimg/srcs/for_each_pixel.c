/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:05:58 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static int		handle_thread_err(t_im_th_info *th_info)
{
	unsigned int	i;

	i = 0;
	while (i < IM_NUM_THREADS)
	{
		pthread_cancel(th_info->tid[i]);
		i++;
	}
	pthread_mutex_destroy(&th_info->lock);
	return (IM_FAIL);
}

static void		set_arg_th(
	t_im_buffer_info *buf_info,
	t_im_th_info *th_info,
	unsigned int offset,
	t_im_arg_th *arg
)
{
	ft_memcpy(arg->buf, buf_info->buf, sizeof(unsigned char *) * 2);
	arg->width = buf_info->width;
	arg->worksize = th_info->worksize;
	arg->lock = &th_info->lock;
	arg->offset = offset;
}

static int		distribute_work(
	t_im_buffer_info *buf_info,
	t_im_th_info *th_info,
	t_im_arg_th *arg,
	void *(*func)(void *arg)
)
{
	unsigned int	i;
	unsigned int	offset;

	offset = 0;
	th_info->worksize = buf_info->width * (buf_info->line_per_th + 1);
	i = 0;
	while (i < buf_info->line_rest)
	{
		set_arg_th(buf_info, th_info, offset, arg + i);
		if (pthread_create(th_info->tid + i, NULL, func, arg + i) != 0)
			return (im_handle_err("Fail to create pthread"));
		offset += th_info->worksize;
		i++;
	}
	if ((th_info->worksize -= buf_info->width) == 0)
		return (IM_SUCCESS);
	while (i < IM_NUM_THREADS)
	{
		set_arg_th(buf_info, th_info, offset, arg + i);
		if (pthread_create(th_info->tid + i, NULL, func, arg + i) != 0)
			return (im_handle_err("Fail to create pthread"));
		offset += th_info->worksize;
		i++;
	}
	return (IM_SUCCESS);
}

int				im_for_each_pixel(
	t_im_buffer_info *buf_info,
	t_func_th func
)
{
	int				num_thread;
	t_im_arg_th		arg[IM_NUM_THREADS];
	t_im_th_info	th_info;

	if (buf_info->line_per_th == 0)
		num_thread = buf_info->height;
	else
		num_thread = IM_NUM_THREADS;
	if (pthread_mutex_init(&th_info.lock, NULL) != 0)
		return (im_handle_err("Fail to pthread mutex init"));
	if (distribute_work(buf_info, &th_info, arg, (void *)func) == IM_FAIL)
		return (handle_thread_err(&th_info));
	while (num_thread--)
	{
		if (pthread_join(th_info.tid[num_thread], NULL) != 0)
			return (handle_thread_err(&th_info));
	}
	pthread_mutex_destroy(&th_info.lock);
	return (IM_SUCCESS);
}

void			im_set_buffer_info(
	int width,
	int height,
	t_im_buffer_info *buf_info
)
{
	buf_info->width = width;
	buf_info->height = height;
	buf_info->line_per_th = height / IM_NUM_THREADS;
	buf_info->line_rest = height % IM_NUM_THREADS;
}
