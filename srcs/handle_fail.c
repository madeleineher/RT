/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:36:30 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:36:31 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		handle_fail(const char *msg)
{
	ft_putstr(KRED);
	ft_putstr("Failed : ");
	ft_putendl(msg);
	ft_putstr(KNRM);
	return (RT_FAIL);
}
