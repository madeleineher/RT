/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:27 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rectangle_translate(t_vec3 *v_translate, void *object)
{
	t_rectangle		*rect;

	rect = (t_rectangle *)object;
	rect->p = v3_add(rect->p, *v_translate);
	rect->d = v3_dotpdt(rect->p, rect->normal);
}
