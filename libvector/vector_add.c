/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:46:43 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 15:46:51 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec2		v2_add(t_vec2 u, t_vec2 v)
{
	t_vec2	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	return (w);
}

t_vec3		v3_add(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vec4		v4_add(t_vec4 u, t_vec4 v)
{
	t_vec4	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	w.w = 0;
	return (w);
}
