/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:13:58 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:46:49 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_sphere *arg)
{
	if ((ft_strcmp(s->word, "center")) == 0)
		handle_3vec_number(s, &arg->cen);
	if ((ft_strcmp(s->word, "radius")) == 0)
		handle_float_number(s, &arg->radius);
}

void			parse_sphere(t_parse *p)
{
	t_arg_sphere	arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_sphere));
	ft_bzero(&arg, sizeof(t_arg_sphere));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</sphere>") != 0)
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
	p->flag &= ~(1UL << 4);
	if (set_sphere(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
}
