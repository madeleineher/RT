/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:04:52 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:15:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (dst == NULL || src == NULL)
		return (dst);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (p_dst + len <= p_src || p_src + len <= p_dst)
		ft_memcpy(dst, src, len);
	else
	{
		buf = (unsigned char *)ft_memalloc(sizeof(unsigned char) * len);
		if (buf == NULL)
			return (dst);
		ft_memcpy(buf, src, len);
		ft_memcpy(dst, buf, len);
		ft_memdel((void **)&buf);
	}
	return (dst);
}
