/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_inf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:53:22 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:53:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_inf(double num)
{
	short				exponent;
	unsigned long long	mantissa;

	ft_extract_double(num, &exponent, &mantissa);
	if (exponent == 0x7ff && mantissa == 0)
		return (1);
	return (0);
}
