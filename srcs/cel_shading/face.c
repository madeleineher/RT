/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:15 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		round_n_dot_l(double n_dot_l)
{
	static double		cos_60 = 0.5;
	static double		cos_75 = 0.25881904510252074;

	if (n_dot_l <= 0.0)
		return (0.0);
	else if (n_dot_l > cos_60)
		return (1.0);
	else if (n_dot_l > cos_75)
		return (cos_60);
	else
		return (cos_75);
}
