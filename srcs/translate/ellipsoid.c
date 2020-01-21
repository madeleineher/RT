/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:27:22 by jebae             #+#    #+#             */
/*   Updated: 2019/12/18 16:27:34 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ellipsoid_translate(t_vec3 *v_translate, void *object)
{
	t_ellipsoid		*ellipsoid;

	ellipsoid = (t_ellipsoid *)object;
	ellipsoid->cen = v3_add(ellipsoid->cen, *v_translate);
}
