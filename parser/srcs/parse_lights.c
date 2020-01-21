/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:41:54 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:45:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_distant_light(t_parse *p)
{
	t_arg_distant_light		arg;
	t_ll					*li;
	t_str					*s;

	li = &p->li[p->l_ind];
	s = &p->str;
	li->light = ft_mem(&p->mem, sizeof(t_distant_light));
	ft_bzero(&arg, sizeof(t_arg_distant_light));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</distant>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "dir")) == 0)
			handle_3vec_number(s, &arg.dir);
		if ((ft_strcmp(s->word, "its")) == 0)
			handle_3vec_number(s, &li->its);
		if (*s->buf != '\0')
			s->buf++;
	}
	if (set_distant_light(li, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 14);
}

static void		parse_spherical_light(t_parse *p)
{
	t_arg_spherical_light	arg;
	t_ll					*li;
	t_str					*s;

	li = &p->li[p->l_ind];
	s = &p->str;
	li->light = ft_mem(&p->mem, sizeof(t_spherical_light));
	ft_bzero(&arg, sizeof(t_arg_spherical_light));
	while (*s->buf != '\0' && ft_strcmp(s->line, "</spherical>") != 0)
	{
		if (*s->buf != '\n')
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		if ((ft_strcmp(s->word, "pos")) == 0)
			handle_3vec_number(s, &arg.pos);
		if ((ft_strcmp(s->word, "its")) == 0)
			handle_3vec_number(s, &li->its);
		if (*s->buf != '\0')
			s->buf++;
	}
	if (set_spherical_light(li, &arg) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
	p->flag &= ~(1UL << 13);
}

static void		parse_light(
	unsigned long flag,
	void (*parse_func)(t_parse *),
	t_parse *p
)
{
	p->flag |= flag;
	parse_func(p);
	p->l_ind++;
}

void			parse_lights(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	if (p->l_ind >= 5)
	{
		ft_putendl("Too many lights");
		return ;
	}
	if ((ft_strcmp(s->word, "spherical") == 0))
		parse_light(1UL << 13, &parse_spherical_light, p);
	if ((ft_strcmp(s->word, "distant") == 0))
		parse_light(1UL << 14, &parse_distant_light, p);
}
