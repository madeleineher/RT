/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:38:35 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 23:38:36 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_vec3 *amb)
{
	int		i;
	double	*ptr;

	ptr = (double *)amb;
	i = 0;
	while (i < 3)
	{
		if (ptr[i] < 0.0 || ptr[i] > 1.0)
			return (handle_fail("set_ambient : out of range 0 ~ 1"));
		i++;
	}
	return (RT_SUCCESS);
}

int				set_ambient(t_vec3 *amb)
{
	if (validate(amb) == RT_FAIL)
		return (RT_FAIL);
	return (RT_SUCCESS);
}
