/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:23 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:30:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec4		q_mul_q(t_vec4 *q1, t_vec4 *q2)
{
	t_vec4	q;

	q.w = q1->w * q2->w - v4_dotpdt(*q1, *q2);
	q.x = q1->w * q2->x + q2->w * q1->x +
		q1->y * q2->z - q1->z * q2->y;
	q.y = q1->w * q2->y + q2->w * q1->y +
		q1->z * q2->x - q1->x * q2->z;
	q.z = q1->w * q2->z + q2->w * q1->z +
		q1->x * q2->y - q1->y * q2->x;
	return (q);
}

t_vec4		inverse_q(t_vec4 *q)
{
	t_vec4	q_i;

	q_i.w = q->w;
	q_i.x = -1.0 * q->x;
	q_i.y = -1.0 * q->y;
	q_i.z = -1.0 * q->z;
	return (q_i);
}
