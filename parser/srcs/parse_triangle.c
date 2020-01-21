/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:24:32 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:46:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			parse_arg(t_str *s, t_arg_triangle *arg)
{
	if ((ft_strcmp(s->word, "a")) == 0)
		handle_3vec_number(s, &arg->a);
	if ((ft_strcmp(s->word, "ab")) == 0)
		handle_3vec_number(s, &arg->ab);
	if ((ft_strcmp(s->word, "ac")) == 0)
		handle_3vec_number(s, &arg->ac);
}

void				parse_triangle(t_parse *p)
{
	t_arg_triangle	arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_triangle));
	ft_bzero(&arg, sizeof(t_arg_triangle));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</triangle>") != 0)
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
	if (set_triangle(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 10);
}
