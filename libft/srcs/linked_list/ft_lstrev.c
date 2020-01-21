/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:42:23 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:42:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*pre;
	t_list	*cur;
	t_list	*temp;

	pre = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	*alst = pre;
}
