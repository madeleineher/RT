/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_with_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:45:19 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:45:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_with_arg(t_list *lst,\
	void (*f)(t_list *elem, void *arg), void *arg)
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		(*f)(lst, arg);
		lst = lst->next;
	}
}
