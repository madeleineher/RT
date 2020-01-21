/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 01:24:32 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:18:04 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_check_line_for_numbers(char *line)
{
	while (*line != '\0')
	{
		if (ft_isdigit(*line))
			return (1);
		line++;
	}
	return (0);
}

int		ft_is_good_number(char c)
{
	if (ft_isdigit(c) || c == ',' || c == 'f' || c == '.' || c == '-')
		return (1);
	return (0);
}

int		check_sub_number(char *sub)
{
	while (*sub != '\0')
	{
		if (*sub == '.' || *sub == 'f')
			return (1);
		sub++;
	}
	return (0);
}
