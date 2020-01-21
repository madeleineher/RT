/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:30:57 by jebae             #+#    #+#             */
/*   Updated: 2019/04/03 20:30:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}
