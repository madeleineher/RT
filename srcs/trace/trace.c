/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:02 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 09:51:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersect(t_env *e, t_trace_record *rec)
{
	int			i;
	double		t;

	rec->ray.t = FAR;
	i = 0;
	while (i < e->num_objs)
	{
		t = e->ll_obj[i].intersect(rec->ray, e->ll_obj[i].object);
		if (t > 0 && t < FAR && t < rec->ray.t)
		{
			rec->ray.t = t;
			rec->obj = &e->ll_obj[i];
		}
		i++;
	}
	if (rec->ray.t == FAR)
		return (RT_FALSE);
	set_trace_record(rec);
	return (RT_TRUE);
}

int				raytrace(t_env *e)
{
	t_col			sh;
	t_trace_record	rec;

	e->x = 0;
	while (e->x < e->width)
	{
		e->y = e->y_min;
		while (e->y < e->y_max)
		{
			set_origin_trace_record(e, &rec);
			if (intersect(e, &rec))
			{
				sh.r = e->amb.x * rec.color.x;
				sh.g = e->amb.y * rec.color.y;
				sh.b = e->amb.z * rec.color.z;
				sh = color_add(sh, calc_shade(e, &rec, 1.0));
				color_pixel(e->x, e->y, sh, e);
			}
			e->y++;
		}
		e->x++;
	}
	return (0);
}
