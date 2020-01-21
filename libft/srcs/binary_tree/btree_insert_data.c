/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:24 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_insert_data(
	t_btree **root,
	void *content,
	size_t content_size,
	int (*cmpf)(void *, void *)
)
{
	if (content == NULL || cmpf == NULL || root == NULL)
		return ;
	if (*root == NULL)
	{
		*root = btree_create_node(content, content_size);
		return ;
	}
	if (cmpf((*root)->content, content) == 0)
		return ;
	else if (cmpf((*root)->content, content) < 0)
	{
		if ((*root)->left == NULL)
			(*root)->left = btree_create_node(content, content_size);
		else
			btree_insert_data(&((*root)->left), content, content_size, cmpf);
	}
	else
	{
		if ((*root)->right == NULL)
			(*root)->right = btree_create_node(content, content_size);
		else
			btree_insert_data(&((*root)->right), content, content_size, cmpf);
	}
}
