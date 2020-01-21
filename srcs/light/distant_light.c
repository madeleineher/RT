/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:42 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		distant_light_dir(t_vec3 *point, void *light)
{
	t_distant_light		*dl;

	(void)point;
	dl = (t_distant_light *)light;
	return (dl->dir);
}

double		distant_light_distance(t_vec3 *point, void *light)
{
	(void)point;
	(void)light;
	return (FAR);
}
