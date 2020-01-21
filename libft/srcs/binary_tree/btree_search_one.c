/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:34 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*btree_search_one(
	t_btree *root,
	void *p_data,
	int (*cmpf)(void *, void *)
)
{
	void	*res;

	if (root == NULL || p_data == NULL || cmpf == NULL)
		return (NULL);
	res = btree_search_one(root->left, p_data, cmpf);
	if (res != NULL)
		return (res);
	if (cmpf(root->content, p_data) == 1)
		return (root->content);
	return (btree_search_one(root->right, p_data, cmpf));
}
