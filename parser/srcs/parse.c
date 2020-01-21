/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:55:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 16:49:29 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					parse(t_parse *p, char *path)
{
	struct stat		*att;
	t_str			*s;

	att = &p->att;
	s = &p->str;
	if (stat(path, att) != 0)
	{
		handle_fail("parse : open file");
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
		return (1);
	}
	if (!(p->flag & 1UL))
	{
		if (init_everything(p, path) == 0)
			return (0);
		ft_strcpy(s->time, ctime(&att->st_mtime));
	}
	check_time(p, att, &p->flag, path);
	return (1);
}
