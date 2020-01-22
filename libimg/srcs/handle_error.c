/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:06:37 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:06:37 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

int		im_handle_err(const char *msg)
{
	ft_putstr(KRED);
	ft_putstr("libimg Error : ");
	ft_putendl(msg);
	ft_putstr(KNRM);
	return (IM_FAIL);
}
