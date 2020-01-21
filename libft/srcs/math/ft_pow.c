/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:53:40 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:53:41 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long				ft_powd(long long num, size_t e)
{
	size_t		i;
	long long	res;

	if (e == 0)
		return (1);
	res = num;
	i = 1;
	while (i < e)
	{
		res *= num;
		i++;
	}
	return (res);
}

unsigned long long		ft_powud(unsigned long long num, size_t e)
{
	size_t				i;
	unsigned long long	res;

	if (e == 0)
		return (1);
	res = num;
	i = 1;
	while (i < e)
	{
		res *= num;
		i++;
	}
	return (res);
}
