/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:58 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		box_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_box		*box;

	box = (t_box *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&box->axis_mat, axis_mat, sizeof(t_mat3));
}
