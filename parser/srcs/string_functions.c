/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 01:19:22 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:18:50 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_cpynline(char *dest, char *src)
{
	ft_bzero(dest, ft_strlen(dest));
	while (*src != '\n' && *src != '\0')
	{
		if (!(ft_iswhitespace(*src)))
			*dest++ = *src;
		src++;
	}
	*dest = '\0';
}

void	ft_cpynumbers(char *line, char *numbers)
{
	int flag;

	flag = 0;
	ft_bzero(numbers, ft_strlen(numbers));
	while (*line != '\0')
	{
		if (*line == '>')
			flag |= 1UL;
		if (*line == '/')
			flag |= 1UL << 1;
		if (ft_is_good_number(*line) && (flag & 1UL) && !(flag & 1UL << 1))
			*numbers++ = *line++;
		else
			line++;
	}
	*numbers = '\0';
}

void	ft_cpyonenbr(char *dest, char *src)
{
	ft_bzero(dest, ft_strlen(dest));
	while (*src != '\0' && ft_isalpha(*src))
		src++;
	while (*src != '\0' && *src != ',')
		*dest++ = *src++;
	*dest = '\0';
}
