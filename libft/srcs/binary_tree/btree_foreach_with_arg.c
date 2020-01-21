/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_foreach_with_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:18 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_foreach_with_arg(
	t_btree *root,
	void *arg,
	void (*f)(void *content, void *arg)
)
{
	if (root == NULL)
		return ;
	btree_foreach_with_arg(root->left, arg, f);
	f(root->content, arg);
	btree_foreach_with_arg(root->right, arg, f);
}
