/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:21:24 by jebae             #+#    #+#             */
/*   Updated: 2019/04/07 16:21:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst,\
		void (*del)(void *content, size_t content_size))
{
	if (alst == NULL || *alst == NULL)
		return ;
	if ((*alst)->content != NULL && del != NULL)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
