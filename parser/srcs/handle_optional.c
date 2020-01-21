/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_optional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:54:10 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 15:37:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		assign_values(t_str *s, t_ol *ob)
{
	if ((ft_strcmp(s->word, "specpower")) == 0)
		ob->specpower = handle_int_number(s, 0);
	if ((ft_strcmp(s->word, "specvalue")) == 0)
		ob->specvalue = handle_int_number(s, 0);
	if ((ft_strcmp(s->word, "ior")) == 0)
		handle_float_number(s, &ob->ior);
	if ((ft_strcmp(s->word, "reflectivity")) == 0)
		handle_float_number(s, &ob->reflectivity);
	if ((ft_strcmp(s->word, "transparency")) == 0)
		handle_float_number(s, &ob->transparency);
	if ((ft_strcmp(s->word, "color")) == 0)
		handle_3vec_number(s, &ob->dif);
}

void			handle_optional_vaules(t_parse *p)
{
	t_ol		*ob;
	t_str		*s;

	ob = &p->ob[p->index];
	s = &p->str;
	while (*s->buf != '\0' && ft_strcmp(s->line, "</optional>") != 0)
	{
		if (*s->buf != '\n' && *s->buf)
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		assign_values(s, ob);
		s->buf++;
	}
}
