/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:58:48 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:07:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && n > 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return ((*(unsigned char *)s1 > *(unsigned char *)s2) ? 1 : -1);
		s1++;
		s2++;
		n--;
	}
	if (n == 0 || *s2 == '\0')
		return (0);
	return ((*(unsigned char *)s1 > *(unsigned char *)s2) ? 1 : -1);
}
