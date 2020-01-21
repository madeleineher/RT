/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:57:01 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:57:02 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap(void *p1, void *p2, size_t size)
{
	void	*temp;

	temp = ft_memalloc(size);
	ft_memcpy(temp, p1, size);
	ft_memcpy(p1, p2, size);
	ft_memcpy(p2, temp, size);
	ft_memdel(&temp);
}
