/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:21 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:05:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_ring *arg)
{
	if (arg->r1 < 0.0)
		return (handle_fail("set_ring : r1 below 0"));
	if (arg->r2 < RT_APPROX_0)
		return (handle_fail("set_ring : r2 below or almost 0"));
	if (arg->r1 >= arg->r2)
		return (handle_fail("set_ring : r1 bigger than r2 or same"));
	if (v3_norm2(arg->normal) < RT_APPROX_0)
		return (handle_fail("set_ring : normal's length almost 0"));
	return (RT_SUCCESS);
}

int				set_ring(t_ol *ol, t_arg_ring *arg)
{
	t_ring	*ring;

	if (validate(arg) == RT_FAIL || validate_commons(ol) == RT_FAIL)
		return (RT_FAIL);
	ol->intersect = &v_intersect_ring;
	ol->get_normal = &normal_ring;
	ol->uv_mapping = NULL;
	ol->translate = &ring_translate;
	ol->rotate = &ring_rotate;
	ring = (t_ring *)ol->object;
	ring->center = arg->center;
	ring->normal = v3_normalise(arg->normal);
	ring->r1 = arg->r1;
	ring->r2 = arg->r2;
	ring->d = v3_dotpdt(ring->center, ring->normal);
	pick_axis_from_plane(&ring->normal, &ol->axis_mat);
	return (RT_SUCCESS);
}
