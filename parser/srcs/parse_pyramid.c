/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pyramid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:25:21 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:46:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_pyramid *arg)
{
	if ((ft_strcmp(s->word, "a")) == 0)
		handle_3vec_number(s, &arg->a);
	if ((ft_strcmp(s->word, "u")) == 0)
		handle_3vec_number(s, &arg->u);
	if ((ft_strcmp(s->word, "v")) == 0)
		handle_3vec_number(s, &arg->v);
	if ((ft_strcmp(s->word, "height")) == 0)
		handle_float_number(s, &arg->height);
}

void			parse_pyramid(t_parse *p)
{
	t_arg_pyramid	arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_pyramid));
	ft_bzero(&arg, sizeof(t_arg_pyramid));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</pyramid>") != 0)
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
	if (set_pyramid(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 11);
}
