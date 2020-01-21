/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:16 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cone_translate(t_vec3 *v_translate, void *object)
{
	t_cone	*cone;

	cone = (t_cone *)object;
	cone->cen = v3_add(cone->cen, *v_translate);
}
