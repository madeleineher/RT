/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_nan_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:53:32 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:53:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_nan_l(long double num)
{
	char				d;
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_ldouble(num, &exponent, &mantissa);
	if (exponent != 0x7fff)
		return (0);
	d = mantissa >> 62;
	mantissa &= ~0xc000000000000000;
	if (d == 1 || d == 3)
		return (1);
	if (d == 0 && mantissa != 0)
		return (1);
	if (d == 2 && mantissa != 0)
		return (1);
	return (0);
}
