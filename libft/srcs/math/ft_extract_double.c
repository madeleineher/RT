/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:53:14 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:53:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_extract_double(
	double num,
	short *exponent,
	unsigned long long *mantissa
)
{
	if (exponent == NULL || mantissa == NULL)
		return ;
	*mantissa = *((unsigned long long *)&num);
	*exponent = (*mantissa >> 52) & 0x7ff;
	*mantissa &= 0xfffffffffffff;
}
