/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:13:25 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 16:33:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_cpyword(char *line, char *word)
{
	int		flag;

	flag = 0;
	ft_bzero(word, ft_strlen(word));
	while (*line != '\0')
	{
		if (*line == '>')
			flag |= 1UL << 1;
		if (*line == '/')
			flag |= 1UL;
		if (*line != '/' && *line != '<'
			&& !(flag & 1UL) && !(flag & 1UL << 1))
			*word++ = *line;
		line++;
	}
	*word = '\0';
}

void		ft_second_word(char *line, char *word2)
{
	int		fg;

	fg = 0;
	ft_bzero(word2, ft_strlen(word2));
	while (*line != '\0')
	{
		if (*line == '/')
			fg |= 1UL;
		if ((fg & 1UL && ft_isalpha(*line))
			|| ((*line == '_') && (fg & 1UL)))
			*word2++ = *line;
		line++;
	}
	*word2 = '\0';
}

void		ft_cpymiddleword(char *dest, char *src)
{
	int		a;

	a = 0;
	ft_bzero(dest, ft_strlen(dest));
	while (*src != '\0')
	{
		if (*src == '>')
			a |= 1UL;
		if (*src == '/')
			a |= 1UL << 1;
		if (*src != '<' && *src != '>'
				&& (a & 1UL) && !(a & 1UL << 1))
			*dest++ = *src;
		src++;
	}
	*dest = '\0';
}
