/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:19:47 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:44:41 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_cone *arg)
{
	if ((ft_strcmp(s->word, "center")) == 0)
		handle_3vec_number(s, &arg->cen);
	if ((ft_strcmp(s->word, "axis")) == 0)
		handle_3vec_number(s, &arg->axis);
	if ((ft_strcmp(s->word, "angle")) == 0)
		handle_float_number(s, &arg->angle);
	if ((ft_strcmp(s->word, "upper_height")) == 0)
		handle_float_number(s, &arg->upper_height);
	if ((ft_strcmp(s->word, "lower_height")) == 0)
		handle_float_number(s, &arg->lower_height);
}

void			parse_cone(t_parse *p)
{
	t_arg_cone		arg;
	t_ol			*ob;
	t_str			*s;

	ob = &p->ob[p->index];
	s = &p->str;
	ob->object = ft_mem(&p->mem, sizeof(t_cone));
	ft_bzero(&arg, sizeof(t_arg_cone));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</cone>") != 0)
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
	if (set_cone(ob, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 5);
}
