/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:58 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 00:49:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray			cast_ray(int x, int y, t_env *e)
{
	t_ray		ray;

	ray.ori = e->cam.pos;
	ray.dir = v3_add(e->offset, v3_scalar(e->dx, x));
	ray.dir = v3_add(ray.dir, v3_scalar(e->dy, y));
	ray.dir = v3_normalise(ray.dir);
	ray.t = FAR;
	return (ray);
}
