/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_lstpop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:50:38 by jebae             #+#    #+#             */
/*   Updated: 2019/05/08 13:50:39 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_sorted_lstpop(t_list **alst)
{
	t_list	*to_pop;

	if (alst == NULL)
		return (NULL);
	to_pop = *alst;
	*alst = to_pop->next;
	return (to_pop);
}
