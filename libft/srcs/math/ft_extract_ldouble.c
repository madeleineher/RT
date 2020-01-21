/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_ldouble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:53:17 by jebae             #+#    #+#             */
/*   Updated: 2019/10/24 15:53:18 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_extract_ldouble(
	long double num,
	short *exponent,
	unsigned long long *mantissa
)
{
	char		*ptr;

	if (exponent == NULL || mantissa == NULL)
		return ;
	ptr = (char *)&num;
	ft_memcpy(mantissa, ptr, 8);
	ft_memcpy(exponent, ptr + 8, 2);
	*exponent &= 0x7fff;
}
