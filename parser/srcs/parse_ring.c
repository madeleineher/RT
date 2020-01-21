/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:26:05 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:46:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			parse_arg(t_str *s, t_arg_ring *arg)
{
	if ((ft_strcmp(s->word, "center")) == 0)
		handle_3vec_number(s, &arg->center);
	if ((ft_strcmp(s->word, "normal")) == 0)
		handle_3vec_number(s, &arg->normal);
	if ((ft_strcmp(s->word, "r_one")) == 0)
		handle_float_number(s, &arg->r1);
	if ((ft_strcmp(s->word, "r_two")) == 0)
		handle_float_number(s, &arg->r2);
}

void				parse_ring(t_parse *p)
{
	t_arg_ring		arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_ring));
	ft_bzero(&arg, sizeof(t_arg_ring));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</ring>") != 0)
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
	if (set_ring(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 12);
}
