/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_grid_props.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:56:27 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 11:56:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			set_ray_grid_props(t_env *e)
{
	double		g_x;
	double		g_y;

	g_x = tan(M_PI / 2.0 / 2.0);
	g_y = g_x * e->height / e->width;
	e->dx = v3_scalar(e->cam.right, g_x);
	e->dy = v3_scalar(e->cam.down, g_y);
	e->offset = v3_sub(e->cam.dir, e->dx);
	e->offset = v3_sub(e->offset, e->dy);
	e->dx = v3_scalar(e->dx, 2.0 / (e->width - 1));
	e->dy = v3_scalar(e->dy, 2.0 / (e->height - 1));
}
