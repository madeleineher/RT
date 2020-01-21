/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:56:32 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:56:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *content, void *arg)
{
	content = NULL;
	*((size_t *)arg) += 1;
}

size_t			set_length(t_set *set)
{
	size_t		len;

	len = 0;
	btree_foreach_with_arg(set->tree, &len, &f);
	return (len);
}
