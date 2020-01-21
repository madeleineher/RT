/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:32:36 by jebae             #+#    #+#             */
/*   Updated: 2019/12/18 16:32:49 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		paraboloid_translate(t_vec3 *v_translate, void *object)
{
	t_paraboloid		*paraboloid;

	paraboloid = (t_paraboloid *)object;
	paraboloid->cen = v3_add(paraboloid->cen, *v_translate);
}
