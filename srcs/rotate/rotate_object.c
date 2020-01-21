/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:31 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:30:31 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rotate_object_axis(t_vec4 *q, t_mat3 *axis_mat)
{
	int			i;
	t_vec3		*v;

	i = 0;
	while (i < 3)
	{
		v = (t_vec3 *)axis_mat->arr[i];
		*v = rotate(&q[0], v, &q[1]);
		i++;
	}
}

void		rotate_object(t_env *e, double theta)
{
	t_vec4		q[2];
	t_ol		*obj;

	q[0] = rotate_q(&e->cam.dir, theta);
	q[1] = inverse_q(&q[0]);
	obj = e->ll_obj + e->current_obj_index;
	obj->rotate(q, &obj->axis_mat, obj->object);
}
