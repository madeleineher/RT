/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:22:04 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:46:02 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_plane *arg)
{
	if ((ft_strcmp(s->word, "normal")) == 0)
		handle_3vec_number(s, &arg->normal);
	if ((ft_strcmp(s->word, "d")) == 0)
		handle_float_number(s, &arg->d);
}

void			parse_plane(t_parse *p)
{
	t_arg_plane		arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_plane));
	ft_bzero(&arg, sizeof(t_arg_plane));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</plane>") != 0)
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
	if (set_plane(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 7);
}
