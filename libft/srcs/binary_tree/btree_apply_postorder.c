/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:54:49 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:54:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_postorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	btree_apply_postorder(root->left, applyf);
	btree_apply_postorder(root->right, applyf);
	applyf(root->content);
}
