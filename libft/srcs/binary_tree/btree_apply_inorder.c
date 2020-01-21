/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:54:26 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:54:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_inorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_inorder(root->left, applyf);
	applyf(root->content);
	btree_apply_inorder(root->right, applyf);
}
