/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ellipsoid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:22:38 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:45:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_ellipsoid *arg)
{
	if ((ft_strcmp(s->word, "center")) == 0)
		handle_3vec_number(s, &arg->cen);
	if ((ft_strcmp(s->word, "axis")) == 0)
		handle_3vec_number(s, &arg->axis);
	if ((ft_strcmp(s->word, "d")) == 0)
		handle_float_number(s, &arg->d);
	if ((ft_strcmp(s->word, "sum")) == 0)
		handle_float_number(s, &arg->sum);
}

void			parse_ellipsoid(t_parse *p)
{
	t_arg_ellipsoid		arg;
	t_ol				*ob;
	t_str				*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_ellipsoid));
	ft_bzero(&arg, sizeof(t_arg_ellipsoid));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</ellipsoid>") != 0)
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
	p->flag &= ~(1UL << 15);
	if (set_ellipsoid(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
}
