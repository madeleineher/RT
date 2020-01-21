/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:32:31 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 13:44:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_arg(t_str *s, t_arg_camera *arg)
{
	if ((ft_strcmp(s->word, "pos")) == 0)
		handle_3vec_number(s, &arg->pos);
	if ((ft_strcmp(s->word, "dir")) == 0)
		handle_3vec_number(s, &arg->dir);
	if ((ft_strcmp(s->word, "right")) == 0)
		handle_3vec_number(s, &arg->right);
}

void			parse_camera(t_parse *p, t_str *s, unsigned int *flag)
{
	t_arg_camera	arg;

	if ((ft_strcmp(s->word, "camera")) == 0)
	{
		*flag |= 1UL << 3;
		ft_bzero(&arg, sizeof(t_arg_camera));
		while (*s->buf != '\0' && ft_strcmp(s->line, "</camera>") != 0)
		{
			if (*s->buf != '\n')
				ft_cpynline(s->line, s->buf);
			ft_cpyword(s->line, s->word);
			while (*s->buf != '\n' && *s->buf)
				s->buf++;
			parse_arg(s, &arg);
			if (*s->buf != '\0')
				s->buf++;
		}
		*flag &= ~(1UL << 3);
		if (set_camera(&arg, p->cam) == RT_FAIL)
			p->mask |= RT_ENV_MASK_PARSE_FAIL;
	}
}
