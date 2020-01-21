/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_inf_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:53:25 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:53:29 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_inf_l(long double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_ldouble(num, &exponent, &mantissa);
	if (exponent != 0x7fff)
		return (0);
	if (mantissa == 0 || mantissa == 0x8000000000000000)
		return (1);
	return (0);
}
