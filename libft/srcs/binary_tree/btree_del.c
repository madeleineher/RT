/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:05 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:06 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_del(t_btree **root, void (*del)(void *content))
{
	if (root == NULL || *root == NULL)
		return ;
	btree_del(&((*root)->left), del);
	btree_del(&((*root)->right), del);
	btree_delone(root, del);
}
