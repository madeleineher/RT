/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:23:06 by jebae             #+#    #+#             */
/*   Updated: 2019/04/10 17:09:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;
	char		*p_dst;
	const char	*p_src;

	p_dst = dst;
	while (*p_dst != '\0')
		p_dst++;
	len_dst = p_dst - dst;
	if (size < len_dst + 1)
		return (ft_strlen(src) + size);
	size -= len_dst;
	p_src = src;
	while (*p_src != '\0')
	{
		if (size > 1)
		{
			*(p_dst++) = *p_src;
			size--;
		}
		p_src++;
	}
	*p_dst = '\0';
	return (p_src - src + len_dst);
}
