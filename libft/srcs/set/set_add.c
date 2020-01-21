/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:56:10 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:56:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		set_add(
	t_set *set,
	void *content,
	size_t content_size
)
{
	if (set == NULL || content == NULL)
		return ;
	btree_insert_data(&(set->tree), content, content_size, set->cmpf);
}
