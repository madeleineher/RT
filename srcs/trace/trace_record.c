/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_record.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:05 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 02:11:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			find_point_from_ray(t_ray ray)
{
	t_vec3		point;

	point.x = ray.ori.x + ray.dir.x * ray.t;
	point.y = ray.ori.y + ray.dir.y * ray.t;
	point.z = ray.ori.z + ray.dir.z * ray.t;
	return (point);
}

void			set_trace_record(t_trace_record *rec)
{
	t_vec2		uv;
	t_ol		*obj;

	obj = rec->obj;
	rec->point = find_point_from_ray(rec->ray);
	rec->normal = obj->get_normal(rec->ray, obj->object);
	if (v3_dotpdt(rec->normal, rec->ray.dir) > 0.0)
		rec->normal = v3_scalar(rec->normal, -1.0);
	rec->color = obj->dif;
	if (obj->uv_mapping == NULL)
		return ;
	if (obj->texture.buffer != NULL)
	{
		uv = obj->uv_mapping(
			rec->point, &obj->axis_mat, &obj->texture, obj->object);
		rec->color = get_texel_color(&uv, &obj->texture);
	}
	if (obj->bump_map.buffer != NULL)
	{
		uv = obj->uv_mapping(
			rec->point, &obj->axis_mat, &obj->bump_map, obj->object);
		rec->normal = get_bumped_normal(
			&uv, &obj->bump_map, &rec->normal, &obj->axis_mat);
	}
}

void			set_origin_trace_record(t_env *e, t_trace_record *rec)
{
	rec->ray = cast_ray(e->x, e->y, e);
	rec->ray.ior = 1.0;
	rec->ray.type = RT_RAY_TYPE_ORIGIN;
	rec->depth = 0;
	rec->prev = NULL;
}
