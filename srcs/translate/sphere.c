/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:33 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sphere_translate(t_vec3 *v_translate, void *object)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	sphere->cen = v3_add(sphere->cen, *v_translate);
}
