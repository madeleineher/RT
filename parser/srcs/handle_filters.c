/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_filters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:33:19 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 10:38:15 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		flag_on(t_parse *p, int filter_mask)
{
	if (!(p->flag & 1UL << 18))
	{
		p->mask |= filter_mask;
		p->flag |= 1UL << 18;
	}
}

void			parse_filters(t_parse *p)
{
	t_str *s;

	s = &p->str;
	if ((ft_strcmp(s->word, "filter")) == 0)
	{
		ft_cpymiddleword(s->word3, s->line);
		if (ft_strcmp(s->word3, "blur") == 0)
			flag_on(p, RT_ENV_MASK_GAUSSIAN_BLUR);
		if (ft_strcmp(s->word3, "sephia") == 0)
			flag_on(p, RT_ENV_MASK_SEPHIA);
		if (ft_strcmp(s->word3, "gray") == 0)
			flag_on(p, RT_ENV_MASK_GRAY_SCALE);
		if (ft_strcmp(s->word3, "negative") == 0)
			flag_on(p, RT_ENV_MASK_NEGATIVE);
	}
}

void			handle_cel_shading(t_parse *p)
{
	t_str *s;

	s = &p->str;
	if ((ft_strcmp(s->word, "cel_shading")) == 0)
	{
		ft_cpymiddleword(s->word3, s->line);
		if ((ft_strcmp(s->word, "cel_shading")) == 0)
		{
			if (!(p->flag & 1UL << 17))
			{
				p->mask |= RT_ENV_MASK_CEL_SHADING;
				p->flag |= 1UL << 17;
			}
		}
	}
}
