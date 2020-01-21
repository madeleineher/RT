/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:39 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:55:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			get_divider(const char *str, double *res)
{
	double		divider;

	divider = 1.0;
	while (ft_isdigit(*str))
	{
		*res = *res * 10.0 + (*str - '0');
		divider *= 10.0;
		str++;
	}
	return (divider);
}

double			ft_atof(const char *str)
{
	double		res;
	double		divider;
	char		neg;

	res = 0.0;
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
		res = res * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	divider = get_divider(str, &res);
	return ((res / divider) * (neg ? neg : 1));
}
