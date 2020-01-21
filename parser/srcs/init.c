/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:20 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 16:52:30 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		init_strings(t_parse *p)
{
	t_mem *mem;
	t_str *s;

	mem = &p->mem;
	s = &p->str;
	if (!(p->flag & 1UL))
	{
		if ((s->time = (char *)ft_memalloc(sizeof(char) * 1024 * 2)) == NULL)
			return (0);
	}
	s->line = (char *)ft_mem(mem, sizeof(char) * 1024 * 2);
	s->number = (char *)ft_mem(mem, sizeof(char) * 1024 * 2);
	s->sub_number = (char *)ft_mem(mem, sizeof(char) * 1024 * 2);
	s->word = (char *)ft_mem(mem, sizeof(char) * 1024 * 2);
	s->word2 = (char *)ft_mem(mem, sizeof(char) * 1024 * 2);
	s->word3 = (char *)ft_mem(mem, sizeof(char) * 1024 * 2);
	s->buf = (char *)ft_mem(mem, sizeof(char) * 1024 * 12);
	ft_putendl("Strings are initialized");
	return (1);
}

int		init_mem(t_parse *p)
{
	t_mem	*mem;
	int		size;

	mem = &p->mem;
	size = 1024 * 1024 * 2;
	if ((mem->m = ft_memalloc(size)) == NULL)
		return (0);
	mem->tsize = size;
	mem->usize = 0;
	ft_putendl("Memory is initialized");
	return (1);
}

int		init_everything(t_parse *p, char *path)
{
	if (p->flag & 1UL)
	{
		free(p->mem.m);
		close(p->fd);
	}
	p->index = 0;
	p->l_ind = 0;
	p->size = 0;
	p->flag &= ~(1UL << 17);
	p->flag &= ~(1UL << 18);
	if (init_mem(p) == 0 || init_strings(p) == 0)
		return (0);
	if ((p->fd = open(path, O_RDONLY)) < 0)
	{
		ft_putendl("Failed to open file :(");
		return (0);
	}
	if (!(p->flag & 1UL))
	{
		p->flag = 0;
		p->flag |= 1UL;
	}
	return (1);
}
