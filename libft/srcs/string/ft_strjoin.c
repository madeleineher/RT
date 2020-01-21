/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:30:54 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 17:57:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned long	len;
	char			*joined;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	joined = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s2) + len + 1));
	if (joined == NULL)
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strcpy(joined + len, s2);
	return (joined);
}
