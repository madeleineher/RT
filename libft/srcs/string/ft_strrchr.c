/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:08:25 by jebae             #+#    #+#             */
/*   Updated: 2019/04/04 18:08:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	if ((char)c != '\0')
		return (res);
	else
		return ((char *)s);
}
