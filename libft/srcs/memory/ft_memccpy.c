/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:51:02 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:15:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (dst == NULL || src == NULL)
		return (dst);
	while (n-- > 0)
	{
		if (*((const unsigned char *)src) == (unsigned char)c)
		{
			*((unsigned char *)dst++) = (unsigned char)c;
			return (dst);
		}
		*((unsigned char *)dst++) = *((const unsigned char *)src++);
	}
	return (NULL);
}
