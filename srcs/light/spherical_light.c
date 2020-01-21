/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherical_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:44 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		spherical_light_dir(t_vec3 *point, void *light)
{
	t_spherical_light		*sl;

	sl = (t_spherical_light *)light;
	return (v3_normalise(v3_frompoints(*point, sl->pos)));
}

double		spherical_light_distance(t_vec3 *point, void *light)
{
	t_spherical_light		*sl;

	sl = (t_spherical_light *)light;
	return (v3_norm(v3_frompoints(*point, sl->pos)));
}
