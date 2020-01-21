/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:37:19 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 14:53:16 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return ((*(unsigned char *)s1 > *(unsigned char *)s2) ? 1 : -1);
		s1++;
		s2++;
	}
	if (*s2 == '\0')
		return (0);
	return ((*(unsigned char *)s1 > *(unsigned char *)s2) ? 1 : -1);
}
