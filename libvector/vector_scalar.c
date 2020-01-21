/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:47:58 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 15:48:08 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec2		v2_scalar(t_vec2 u, double k)
{
	t_vec2	w;

	w.x = k * u.x;
	w.y = k * u.y;
	return (w);
}

t_vec3		v3_scalar(t_vec3 u, double k)
{
	t_vec3	w;

	w.x = k * u.x;
	w.y = k * u.y;
	w.z = k * u.z;
	return (w);
}

t_vec4		v4_scalar(t_vec4 u, double k)
{
	t_vec4	w;

	w.x = k * u.x;
	w.y = k * u.y;
	w.z = k * u.z;
	w.w = 0;
	return (w);
}
