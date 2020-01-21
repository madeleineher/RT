/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:49:18 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 15:49:22 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vec2		v2_normalise(t_vec2 u)
{
	return (v2_scalar(u, 1 / v2_norm(u)));
}

t_vec3		v3_normalise(t_vec3 u)
{
	return (v3_scalar(u, 1 / v3_norm(u)));
}

t_vec4		v4_normalise(t_vec4 u)
{
	return (v4_scalar(u, 1 / v4_norm(u)));
}
