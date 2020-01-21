/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:12 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		handle_err(t_im_buffer_info *buf_info)
{
	ft_memdel((void **)&buf_info->buf[1]);
	return (RT_FAIL);
}

static void		draw_edge_on_face(void *arg_void)
{
	unsigned int		i;
	unsigned int		*face_buf;
	t_im_edge_gradient	*edge_buf;
	t_im_arg_th			*arg;

	arg = (t_im_arg_th *)arg_void;
	face_buf = (unsigned int *)arg->buf[0] + arg->offset;
	edge_buf = (t_im_edge_gradient *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->worksize)
	{
		if (edge_buf[i].magnitude > 0.0f)
			face_buf[i] = 0x000000;
		i++;
	}
}

static int		get_edge(
	t_env *e,
	t_im_buffer_info *buf_info
)
{
	e->mask |= RT_ENV_MASK_NO_SHADOW | RT_ENV_MASK_NO_SPECULAR;
	if (multi_thread(e) == RT_FAIL)
		return (RT_FAIL);
	if (im_canny_edge_detect(
		(unsigned int *)e->data, (t_im_edge_gradient *)buf_info->buf[1],
		buf_info->width, buf_info->height) == IM_FAIL)
		return (handle_fail("cel_shading : im_canny_edge_detect"));
	e->mask &= ~(RT_ENV_MASK_NO_SHADOW | RT_ENV_MASK_NO_SPECULAR);
	return (RT_SUCCESS);
}

static int		get_face(t_env *e)
{
	e->mask |= RT_ENV_MASK_ROUND_N_DOT_L;
	if (multi_thread(e) == RT_FAIL)
		return (RT_FAIL);
	e->mask &= ~RT_ENV_MASK_ROUND_N_DOT_L;
	return (RT_SUCCESS);
}

int				cel_shading(t_env *e)
{
	t_im_buffer_info	buf_info;

	im_set_buffer_info(e->width, e->height, &buf_info);
	if ((buf_info.buf[1] = ft_memalloc(
		sizeof(t_im_edge_gradient) * e->num_pixels)) == NULL)
		return (handle_fail("cel_shading : malloc buf_info.buf[1]"));
	if (get_edge(e, &buf_info) == RT_FAIL)
		return (handle_err(&buf_info));
	if (get_face(e) == RT_FAIL)
		return (handle_err(&buf_info));
	buf_info.buf[0] = (unsigned char *)e->data;
	if (im_for_each_pixel(&buf_info, draw_edge_on_face) == IM_FAIL)
	{
		handle_fail("cel_shading : draw_edge_on_face");
		return (handle_err(&buf_info));
	}
	ft_memdel((void **)&buf_info.buf[1]);
	return (RT_SUCCESS);
}
