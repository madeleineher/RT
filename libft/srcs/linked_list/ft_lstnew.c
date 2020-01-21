/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:12:57 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:16:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		if (list->content != NULL)
		{
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
	}
	list->next = NULL;
	return (list);
}
