/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:33:24 by jebae             #+#    #+#             */
/*   Updated: 2019/12/18 16:33:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		paraboloid_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_paraboloid		*paraboloid;

	paraboloid = (t_paraboloid *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&paraboloid->axis, axis_mat->arr[1], sizeof(t_vec3));
}
