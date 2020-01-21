/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:03 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:30:04 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cyl_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_cyl		*cyl;

	cyl = (t_cyl *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&cyl->axis, axis_mat->arr[1], sizeof(t_vec3));
}
