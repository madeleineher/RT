/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:47:36 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 15:50:53 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec2		v2_sub(t_vec2 u, t_vec2 v)
{
	t_vec2	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	return (w);
}

t_vec3		v3_sub(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vec4		v4_sub(t_vec4 u, t_vec4 v)
{
	t_vec4	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	w.w = 0;
	return (w);
}
