/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:10 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:11 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_delone(t_btree **node, void (*del)(void *content))
{
	if (node == NULL || *node == NULL)
		return ;
	if ((*node)->content != NULL && del != NULL)
		del((*node)->content);
	ft_memdel((void **)node);
}
