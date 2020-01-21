/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:47:36 by jebae             #+#    #+#             */
/*   Updated: 2019/04/07 17:47:36 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*cur;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = (*f)(lst);
	map = ft_lstnew(temp->content, temp->content_size);
	cur = map;
	lst = lst->next;
	while (lst)
	{
		temp = (*f)(lst);
		cur->next = ft_lstnew(temp->content, temp->content_size);
		lst = lst->next;
		cur = cur->next;
	}
	return (map);
}
