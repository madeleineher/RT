/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:54:58 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:54:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_bfs(t_btree *root, void (*f)(void *content))
{
	t_queue		queue;
	t_btree		*poped;

	if (root == NULL)
		return ;
	queue = queue_init();
	queue_push(&queue, root, sizeof(t_btree));
	while (queue.front != NULL)
	{
		poped = queue_pop(&queue);
		queue_push(&queue, poped->left, sizeof(t_btree));
		queue_push(&queue, poped->right, sizeof(t_btree));
		f(poped->content);
		ft_memdel((void **)&poped);
	}
}
