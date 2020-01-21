/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:37 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		triangle_translate(t_vec3 *v_translate, void *object)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)object;
	triangle->a = v3_add(triangle->a, *v_translate);
}
