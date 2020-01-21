/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:35:08 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 17:21:06 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		usage(void)
{
	ft_putendl("usage : ./rt [filename]");
}

static int		init(t_env *e, t_parse *p, char *filename)
{
	ft_bzero(p, sizeof(t_parse));
	if (init_env(e) == RT_FAIL)
		return (RT_FAIL);
	p->ob = e->ll_obj;
	p->li = e->ll_lit;
	p->cam = &e->cam;
	p->amb = &e->amb;
	parse(p, filename);
	if (p->mask & RT_ENV_MASK_PARSE_FAIL)
		return (RT_FAIL);
	e->num_objs = p->index;
	e->num_lights = p->l_ind;
	e->mask = p->mask;
	set_ray_grid_props(e);
	return (RT_SUCCESS);
}

int				main(int argc, char **argv)
{
	t_env		e;
	t_parse		p;

	if (argc != 2)
	{
		usage();
		return (1);
	}
	if (init(&e, &p, argv[1]) == RT_FAIL)
	{
		clear_env(&e);
		clear_parse(&p);
		return (1);
	}
	if (render(&e) == RT_SUCCESS)
		run_event_loop(&e, &p, argv[1]);
	return (0);
}
