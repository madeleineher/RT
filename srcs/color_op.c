/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:32:44 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/16 15:33:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_col		color_add(t_col c1, t_col c2)
{
	t_col	c;

	c.r = (c1.r + c2.r);
	c.g = (c1.g + c2.g);
	c.b = (c1.b + c2.b);
	c.r = c.r > 0xFF ? 0xFF : c.r;
	c.g = c.g > 0xFF ? 0xFF : c.g;
	c.b = c.b > 0xFF ? 0xFF : c.b;
	return (c);
}

t_col		color_scalar(t_col c, double scalar)
{
	c.r *= scalar;
	c.g *= scalar;
	c.b *= scalar;
	return (c);
}

void		color_pixel(int x, int y, t_col sh, t_env *e)
{
	unsigned int	*pixel;

	pixel = e->data + y * e->width + x;
	*pixel = sh.r;
	*pixel <<= 8;
	*pixel += sh.g;
	*pixel <<= 8;
	*pixel += sh.b;
}
