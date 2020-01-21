/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:28:26 by jebae             #+#    #+#             */
/*   Updated: 2019/12/18 16:28:31 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ellipsoid_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	t_ellipsoid		*ellipsoid;

	ellipsoid = (t_ellipsoid *)object;
	rotate_object_axis(q, axis_mat);
	ft_memcpy(&ellipsoid->axis, axis_mat->arr[1], sizeof(t_vec3));
}
