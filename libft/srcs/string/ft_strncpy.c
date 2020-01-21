/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:34:28 by jebae             #+#    #+#             */
/*   Updated: 2019/04/05 21:39:01 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p_dst;

	p_dst = dst;
	while (len > 0 && *src != '\0')
	{
		*(p_dst++) = *(src++);
		len--;
	}
	while (len-- > 0)
		*(p_dst++) = '\0';
	return (dst);
}
