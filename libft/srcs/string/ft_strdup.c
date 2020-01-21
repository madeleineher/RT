/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:16:08 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 17:57:24 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*copy;

	len = 0;
	while (src[len] != '\0')
		len++;
	copy = (char *)ft_memalloc(sizeof(*src) * (len + 1));
	if (copy == NULL)
		return (NULL);
	copy[len] = '\0';
	while (len--)
		copy[len] = src[len];
	return (copy);
}
