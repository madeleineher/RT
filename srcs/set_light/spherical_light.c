/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherical_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:58 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 07:33:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			set_spherical_light(t_ll *ll, t_arg_spherical_light *arg)
{
	t_spherical_light		*sl;

	sl = (t_spherical_light *)ll->light;
	sl->pos = arg->pos;
	ll->get_dir = &spherical_light_dir;
	ll->get_distance = &spherical_light_distance;
	return (RT_SUCCESS);
}
