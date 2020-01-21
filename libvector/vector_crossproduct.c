/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_crossproduct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:47:02 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 15:50:34 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec3		v3_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}

t_vec4		v4_cross(t_vec4 u, t_vec4 v)
{
	t_vec4	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	w.w = 0;
	return (w);
}
