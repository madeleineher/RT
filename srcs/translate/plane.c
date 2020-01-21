/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:21 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		plane_translate(t_vec3 *v_translate, void *object)
{
	t_plane	*plane;

	plane = (t_plane *)object;
	plane->d = v3_dotpdt(plane->normal, *v_translate) + plane->d;
}
