/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_foreach_with_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:56:24 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:56:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		set_foreach_with_arg(
	t_set *set,
	void *arg,
	void (*f)(void *content, void *arg)
)
{
	btree_foreach_with_arg(set->tree, arg, f);
}
