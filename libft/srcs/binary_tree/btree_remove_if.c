/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_remove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:31 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			del(void *content)
{
	ft_memdel((void **)&content);
}

static t_btree		*find_successor(t_btree *to_remove)
{
	t_btree		*succ;
	t_btree		*succ_parent;

	succ = to_remove->right;
	if (succ->left == NULL)
	{
		to_remove->right = succ->right;
		return (succ);
	}
	while (succ->left != NULL)
	{
		succ_parent = succ;
		succ = succ->left;
	}
	succ_parent->left = succ->right;
	return (succ);
}

static void			handle_remove(t_btree **root)
{
	t_btree		*succ;

	if ((*root)->left == NULL)
	{
		succ = (*root)->right;
		btree_delone(root, del);
		*root = succ;
	}
	else if ((*root)->right == NULL)
	{
		succ = (*root)->left;
		btree_delone(root, del);
		*root = succ;
	}
	else
	{
		succ = find_successor(*root);
		del((*root)->content);
		(*root)->content = succ->content;
		btree_delone(&succ, NULL);
	}
}

void				btree_remove_if(
	t_btree **root,
	void *p_data,
	int (*cmpf)(void *, void *)
)
{
	if (root == NULL || *root == NULL || p_data == NULL || cmpf == NULL)
		return ;
	if (cmpf((*root)->content, p_data) == 1)
	{
		handle_remove(root);
		btree_remove_if(root, p_data, cmpf);
		return ;
	}
	if (root != NULL && *root != NULL)
	{
		btree_remove_if(&((*root)->left), p_data, cmpf);
		btree_remove_if(&((*root)->right), p_data, cmpf);
	}
}
