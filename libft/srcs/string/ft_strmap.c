/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:48:19 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 17:57:49 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char ch))
{
	char		*new_str;
	size_t		len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)ft_memalloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[len] = '\0';
	while (len-- > 0)
		new_str[len] = (*f)(s[len]);
	return (new_str);
}
