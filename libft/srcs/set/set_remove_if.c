/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_remove_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:56:35 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:56:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		set_remove_if(
	t_set *set,
	void *p_data,
	int (*cmpf)(void *, void *)
)
{
	if (set == NULL || p_data == NULL || cmpf == NULL)
		return ;
	btree_remove_if(&(set->tree), p_data, cmpf);
}
