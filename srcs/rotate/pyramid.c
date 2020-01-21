/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:12 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:30:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		rotate_sides(
	t_vec4 *q,
	t_triangle *sides
)
{
	sides[0].ab = rotate(&q[0], &sides[0].ab, &q[1]);
	sides[0].ac = rotate(&q[0], &sides[0].ac, &q[1]);
	sides[0].normal = v3_normalise(v3_cross(sides[0].ab, sides[0].ac));
	sides[1].ab = rotate(&q[0], &sides[1].ab, &q[1]);
	sides[1].ac = rotate(&q[0], &sides[1].ac, &q[1]);
	sides[1].normal = v3_normalise(v3_cross(sides[1].ab, sides[1].ac));
	sides[1].a = v3_add(sides[0].a, sides[0].ab);
	sides[2].ab = rotate(&q[0], &sides[2].ab, &q[1]);
	sides[2].ac = rotate(&q[0], &sides[2].ac, &q[1]);
	sides[2].normal = v3_normalise(v3_cross(sides[2].ab, sides[2].ac));
	sides[3].ab = rotate(&q[0], &sides[3].ab, &q[1]);
	sides[3].ac = rotate(&q[0], &sides[3].ac, &q[1]);
	sides[3].normal = v3_normalise(v3_cross(sides[3].ab, sides[3].ac));
	sides[3].a = v3_add(sides[0].a, sides[2].ab);
}

void			pyramid_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_pyramid	*pyramid;

	pyramid = (t_pyramid *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&pyramid->u, axis_mat->arr[0], sizeof(t_vec3));
	ft_memcpy(&pyramid->v, axis_mat->arr[2], sizeof(t_vec3));
	rotate_sides(q, pyramid->sides);
}
