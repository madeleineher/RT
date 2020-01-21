/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_fromcoord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:51:21 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 15:51:49 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec2	v2_fromcoord(double x, double y)
{
	t_vec2	u;

	u.x = x;
	u.y = y;
	return (u);
}

t_vec3	v3_fromcoord(double x, double y, double z)
{
	t_vec3	u;

	u.x = x;
	u.y = y;
	u.z = z;
	return (u);
}

t_vec4	v4_fromcoord(double x, double y, double z, double w)
{
	t_vec4	u;

	u.x = x;
	u.y = y;
	u.z = z;
	u.w = w;
	return (u);
}
