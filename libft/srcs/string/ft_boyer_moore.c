/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boyer_moore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:58:15 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 14:23:56 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			make_bc_table(size_t *table, const char *pat, size_t len)
{
	size_t		i;

	i = 0;
	while (i < FT_CHARACTER_TABLE_SIZE)
		table[i++] = len;
	i = 0;
	while (i < len)
	{
		table[(size_t)(pat[i])] = i;
		i++;
	}
}

static void			make_gs_table(
	size_t *shift_table,
	const char *pat,
	size_t len
)
{
	size_t		pos_table[len];
	size_t		i;
	size_t		j;

	i = len;
	j = i + 1;
	pos_table[i] = j;
	while (i > 0)
	{
		while (j <= len && pat[i - 1] != pat[j - 1])
		{
			if (shift_table[j] == 0)
				shift_table[j] = j - i;
			j = pos_table[j];
		}
		pos_table[--i] = --j;
	}
	j = pos_table[0];
	while (i <= len)
	{
		if (shift_table[i] == 0)
			shift_table[i] = j;
		if (i++ == j)
			j = pos_table[j];
	}
}

static void			preprocess(
	size_t *bc_table,
	size_t *shift_table,
	const char *pat,
	size_t len
)
{
	make_bc_table(bc_table, pat, len);
	make_gs_table(shift_table, pat, len);
}

static char			*search(
	const char *text,
	const char *pat,
	size_t *bc_table,
	size_t *shift_table
)
{
	size_t		i;
	size_t		j;
	size_t		text_len;
	size_t		pat_len;

	text_len = ft_strlen(text);
	pat_len = ft_strlen(pat);
	i = 0;
	if (text_len < pat_len)
		return (NULL);
	while (i <= text_len - pat_len)
	{
		j = pat_len;
		while (j > 0 && pat[j - 1] == text[i + (j - 1)])
			j--;
		if (j == 0)
			return ((char *)text + i);
		if (bc_table[(size_t)(text[i + j])] != pat_len)
			i += (shift_table[j] > j - bc_table[(size_t)(text[i + j])])
				? shift_table[j] : j - bc_table[(size_t)(text[i + j])];
		else
			i += (j > shift_table[j]) ? j : shift_table[j];
	}
	return (NULL);
}

char				*ft_boyer_moore(const char *text, const char *pat)
{
	size_t		pat_len;
	size_t		bc_table[FT_CHARACTER_TABLE_SIZE];
	size_t		*shift_table;
	char		*loc;

	loc = NULL;
	pat_len = ft_strlen(pat);
	shift_table = ft_memalloc(sizeof(size_t) * (pat_len + 1));
	if (shift_table == NULL)
		return (NULL);
	preprocess(bc_table, shift_table, pat, pat_len);
	loc = search(text, pat, bc_table, shift_table);
	ft_memdel((void **)&shift_table);
	return (loc);
}
