/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:55 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 07:33:53 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_distant_light *arg)
{
	if (v3_norm(arg->dir) < RT_APPROX_0)
		return (handle_fail("set_distant_light : dir's length almost 0"));
	return (RT_SUCCESS);
}

int				set_distant_light(t_ll *ll, t_arg_distant_light *arg)
{
	t_distant_light		*dl;

	dl = (t_distant_light *)ll->light;
	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	dl->dir = v3_normalise(arg->dir);
	ll->get_dir = &distant_light_dir;
	ll->get_distance = &distant_light_distance;
	return (RT_SUCCESS);
}
