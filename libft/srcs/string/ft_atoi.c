/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:59:48 by jebae             #+#    #+#             */
/*   Updated: 2019/06/18 17:51:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long		res;
	char				neg;

	res = 0;
	neg = 0;
	while (*str != '\0' && ft_iswhitespace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res / 10 > FT_LONG_LIMIT / 10 ||
		(res / 10 == FT_LONG_LIMIT / 10 && res % 10 > FT_LONG_LIMIT % 10))
		return (neg ? 0 : -1);
	return ((int)res * (neg ? neg : 1));
}
