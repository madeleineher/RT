/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:30 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:31 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ring_translate(t_vec3 *v_translate, void *object)
{
	t_ring	*ring;

	ring = (t_ring *)object;
	ring->center = v3_add(ring->center, *v_translate);
	ring->d = v3_dotpdt(ring->center, ring->normal);
}
