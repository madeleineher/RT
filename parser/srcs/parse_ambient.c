/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:25:15 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 13:41:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse_ambient(t_parse *p)
{
	t_str		*s;

	s = &p->str;
	if ((ft_strcmp(s->word, "ambient")) == 0)
	{
		if (!(p->flag & 1UL << 19))
		{
			handle_3vec_number(s, p->amb);
			p->flag |= 1UL << 19;
		}
		p->flag &= ~(1UL << 19);
		if (set_ambient(p->amb) == RT_FAIL)
			p->mask |= RT_ENV_MASK_PARSE_FAIL;
	}
}
