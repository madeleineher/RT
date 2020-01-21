/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:13 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_foreach(
	t_btree *root,
	void (*f)(void *content)
)
{
	if (root == NULL)
		return ;
	btree_foreach(root->left, f);
	f(root->content);
	btree_foreach(root->right, f);
}
