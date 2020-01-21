/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:35 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:32:36 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		translate_object(t_env *e, t_vec3 v_translate)
{
	t_ol		*obj;

	obj = e->ll_obj + e->current_obj_index;
	obj->translate(&v_translate, obj->object);
}
