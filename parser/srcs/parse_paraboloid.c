/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:13:00 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:45:51 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_paraboloid *arg)
{
	if ((ft_strcmp(s->word, "center")) == 0)
		handle_3vec_number(s, &arg->cen);
	if ((ft_strcmp(s->word, "axis")) == 0)
		handle_3vec_number(s, &arg->axis);
	if ((ft_strcmp(s->word, "k")) == 0)
		handle_float_number(s, &arg->k);
	if ((ft_strcmp(s->word, "min")) == 0)
		handle_float_number(s, &arg->min);
	if ((ft_strcmp(s->word, "max")) == 0)
		handle_float_number(s, &arg->max);
}

void			parse_paraboloid(t_parse *p)
{
	t_ol				*ob;
	t_arg_paraboloid	arg;
	t_str				*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_paraboloid));
	ft_bzero(&arg, sizeof(t_arg_paraboloid));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</paraboloid>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		parse_arg(s, &arg);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		if (*s->buf != '\0')
			s->buf++;
	}
	p->flag &= ~(1UL << 16);
	if (set_paraboloid(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
}
