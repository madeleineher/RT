/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer2img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:33:01 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:33:02 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			buffer2img(unsigned int *buf, int width, int height)
{
	static char			*output_dir = "outputs";
	struct stat			st;
	t_im_buffer_info	buf_info;

	if (stat(output_dir, &st) != 0 || !S_ISDIR(st.st_mode))
		mkdir(output_dir, 0700);
	im_set_buffer_info(width, height, &buf_info);
	buf_info.buf[0] = (unsigned char *)buf;
	if (im_buffer2jpg("outputs/rt.jpg", &buf_info) == IM_FAIL)
		return (handle_fail("buffer2img : im_buffer2jpg"));
	return (IM_SUCCESS);
}
