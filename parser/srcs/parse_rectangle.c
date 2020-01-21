/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:22:50 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:43:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_rectangle *arg)
{
	if ((ft_strcmp(s->word, "p")) == 0)
		handle_3vec_number(s, &arg->p);
	if ((ft_strcmp(s->word, "a")) == 0)
		handle_3vec_number(s, &arg->a);
	if ((ft_strcmp(s->word, "b")) == 0)
		handle_3vec_number(s, &arg->b);
}

void			parse_rectangle(t_parse *p)
{
	t_arg_rectangle		arg;
	t_ol				*ob;
	t_str				*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_rectangle));
	ft_bzero(&arg, sizeof(t_arg_rectangle));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</rectangle>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		parse_arg(s, &arg);
		if ((ft_strcmp(s->word, "optional")) == 0)
			handle_optional_vaules(p);
		handle_texels(s, p);
		if (*s->buf != '\0')
			s->buf++;
	}
	if (set_rectangle(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 8);
}
