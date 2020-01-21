/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:32:19 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 17:58:16 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_array_size(const char *s, const char c)
{
	size_t		size;

	size = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s != '\0')
			s++;
		size++;
		if (*s == '\0')
			break ;
		s++;
	}
	return (size);
}

static const char	*split(char **p_str, const char *s, char c)
{
	char		*end;
	size_t		len;

	while (*s == c)
		s++;
	end = (char *)s;
	while (*end != c && *end != '\0')
		end++;
	len = end - s;
	*p_str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (*p_str == NULL)
		return (NULL);
	ft_strncpy(*p_str, s, len);
	(*p_str)[len] = '\0';
	return (end + 1);
}

char				**ft_strsplit(const char *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	i = get_array_size(s, c);
	arr = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (j < i)
		s = split(arr + j++, s, c);
	arr[i] = NULL;
	return (arr);
}
