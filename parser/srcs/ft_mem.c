/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:12:39 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:41:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	*ft_mem(t_mem *mem, size_t size)
{
	void	*p;

	if (mem->tsize < (size + mem->usize))
		return (NULL);
	p = mem->m + mem->usize;
	mem->usize = mem->usize + size + 1;
	return (p);
}
