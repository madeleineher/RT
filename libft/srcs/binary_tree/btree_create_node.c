/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:02 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*btree_create_node(void *content, size_t content_size)
{
	t_btree		*node;

	if (content == NULL)
		return (NULL);
	node = (t_btree *)ft_memalloc(sizeof(t_btree));
	node->left = NULL;
	node->right = NULL;
	node->content = ft_memalloc(content_size);
	ft_memcpy(node->content, content, content_size);
	return (node);
}
