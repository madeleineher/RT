/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:45:48 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:21:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*p_dst;

	if (dst == NULL || src == NULL)
		return (dst);
	p_dst = dst;
	while (*src != '\0')
		*(p_dst++) = *(src++);
	*p_dst = *src;
	return (dst);
}
