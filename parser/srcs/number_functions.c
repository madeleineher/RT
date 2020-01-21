/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 01:32:01 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 14:27:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		handle_int_number(t_str *s, int nb)
{
	ft_cpynumbers(s->line, s->number);
	while (*s->number != '\0')
	{
		ft_cpyonenbr(s->sub_number, s->number);
		if (check_sub_number(s->sub_number))
			return (0);
		else
			nb = ft_atoi(s->sub_number);
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		s->number++;
	}
	return (nb);
}

void	handle_float_number(t_str *s, double *nb)
{
	ft_cpynumbers(s->line, s->number);
	while (*s->number != '\0')
	{
		ft_cpyonenbr(s->sub_number, s->number);
		if (check_sub_number(s->sub_number))
			*nb = ft_atof(s->sub_number);
		else
			*nb = ft_atoi(s->sub_number);
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		s->number++;
	}
}

void	handle_3vec_number(t_str *s, t_vec3 *vec)
{
	int i;

	i = 0;
	ft_cpynumbers(s->line, s->number);
	while (*s->number != '\0')
	{
		ft_cpyonenbr(s->sub_number, s->number);
		if (check_sub_number(s->sub_number))
			handle_float_vec(vec, s->sub_number, i);
		else
			handle_int_vec(vec, s->sub_number, i);
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		if (*s->number == ',' && i < 3 && *s->number)
			i++;
		s->number++;
	}
}
