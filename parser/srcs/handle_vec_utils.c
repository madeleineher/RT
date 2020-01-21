/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_vec_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:27:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/11/26 02:27:42 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	handle_float_vec(t_vec3 *vec, char *sub_number, int i)
{
	if (i == 0)
		vec->x = ft_atof(sub_number);
	else if (i == 1)
		vec->y = ft_atof(sub_number);
	else if (i == 2)
		vec->z = ft_atof(sub_number);
}

void	handle_int_vec(t_vec3 *vec, char *sub_number, int i)
{
	if (i == 0)
		vec->x = ft_atoi(sub_number);
	else if (i == 1)
		vec->y = ft_atoi(sub_number);
	else if (i == 2)
		vec->z = ft_atoi(sub_number);
}
