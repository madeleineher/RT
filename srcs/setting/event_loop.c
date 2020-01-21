/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:33 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 06:40:44 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		handle_hotreload(t_env *e, t_parse *p, char *filename)
{
	(void)e;
	p->mask = 0;
	parse(p, filename);
	if (p->mask & RT_ENV_MASK_PARSE_FAIL)
		return ;
	if (p->mask & RT_ENV_MASK_PARSE_RELOAD)
	{
		e->num_objs = p->index;
		e->num_lights = p->l_ind;
		e->mask = p->mask;
		set_ray_grid_props(e);
		render(e);
	}
}

void			run_event_loop(t_env *e, t_parse *p, char *filename)
{
	SDL_Event	*event;

	event = &e->sdl.event;
	while (1)
	{
		if (p && filename)
			handle_hotreload(e, p, filename);
		while (SDL_PollEvent(event))
		{
			if (event->type == SDL_QUIT)
			{
				clear_env(e);
				clear_parse(p);
				SDL_Quit();
				return ;
			}
			if (event->type == SDL_KEYDOWN)
				key_input(event->key.keysym.sym, e, p);
		}
	}
}
