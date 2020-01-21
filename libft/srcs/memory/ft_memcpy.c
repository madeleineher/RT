/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:18:07 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:15:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL || src == NULL)
		return (dst);
	while (n-- > 0)
		((unsigned char *)dst)[n] = ((const unsigned char *)src)[n];
	return (dst);
}
