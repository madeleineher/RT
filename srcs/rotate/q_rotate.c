/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:21 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:30:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec4		rotate_q(t_vec3 *n, float theta)
{
	t_vec4		q;
	double		s;

	s = sin(theta * 0.5);
	q.x = s * n->x;
	q.y = s * n->y;
	q.z = s * n->z;
	q.w = cos(theta * 0.5);
	return (q);
}

t_vec3		rotate(t_vec4 *q, t_vec3 *v, t_vec4 *q_i)
{
	t_vec4		res;

	ft_memcpy(&res, v, sizeof(t_vec3));
	res.w = 0.0;
	res = q_mul_q(q, &res);
	res = q_mul_q(&res, q_i);
	return ((t_vec3){res.x, res.y, res.z});
}
