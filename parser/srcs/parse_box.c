/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:23:46 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:47:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_box *arg)
{
	if ((ft_strcmp(s->word, "vmin")) == 0)
		handle_3vec_number(s, &arg->vmin);
	if ((ft_strcmp(s->word, "a")) == 0)
		handle_3vec_number(s, &arg->a);
	if ((ft_strcmp(s->word, "b")) == 0)
		handle_3vec_number(s, &arg->b);
	if ((ft_strcmp(s->word, "norm_c")) == 0)
		handle_float_number(s, &arg->norm_c);
}

void			parse_box(t_parse *p)
{
	t_arg_box	arg;
	t_str		*s;
	t_ol		*ob;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_box));
	ft_bzero(&arg, sizeof(t_arg_box));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</box>") != 0)
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
	if (set_box(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 9);
}
