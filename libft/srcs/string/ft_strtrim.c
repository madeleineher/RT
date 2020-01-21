/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:04:59 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 17:58:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

char		*ft_strtrim(const char *s)
{
	char	*trim;
	char	*start;
	char	*end;

	if (s == NULL)
		return (NULL);
	while (is_whitespace(*s))
		s++;
	start = (char *)s;
	end = start;
	while (*s != '\0')
	{
		if (!is_whitespace(*s))
			end = (char *)s + 1;
		s++;
	}
	trim = (char *)ft_memalloc(sizeof(char) * (end - start + 1));
	if (trim == NULL)
		return (NULL);
	trim[end - start] = '\0';
	ft_strncpy(trim, start, end - start);
	return (trim);
}
