/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:19 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		cyl_translate(t_vec3 *v_translate, void *object)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)object;
	cyl->cen = v3_add(cyl->cen, *v_translate);
}
