/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:30 by jebae             #+#    #+#             */
/*   Updated: 2019/12/19 12:04:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		set_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (handle_fail("init_env : SDL_Init"));
	if ((sdl->window = SDL_CreateWindow(
		"RT", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		return (handle_fail("init_env : SDL_CreateWindow"));
	if ((sdl->renderer = SDL_CreateRenderer(
		sdl->window, -1, 0)) == NULL)
		return (handle_fail("init_env : SDL_CreateRenderer"));
	if ((sdl->tex = SDL_CreateTexture(
		sdl->renderer, SDL_PIXELFORMAT_BGRA32,
		SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)) == NULL)
		return (handle_fail("init_env : SDL_CreateTexture"));
	return (RT_SUCCESS);
}

static void		clear_sdl(t_sdl *sdl)
{
	if (sdl->tex)
		SDL_DestroyTexture(sdl->tex);
	if (sdl->renderer)
		SDL_DestroyRenderer(sdl->renderer);
	if (sdl->window)
		SDL_DestroyWindow(sdl->window);
}

int				init_env(t_env *e)
{
	ft_bzero(e, sizeof(t_env));
	if (set_sdl(&e->sdl) == RT_FAIL)
		return (RT_FAIL);
	e->width = WIDTH * 2;
	e->height = HEIGHT * 2;
	e->num_pixels = e->width * e->height;
	if ((e->img_buf = ft_memalloc(
		sizeof(unsigned int) * WIDTH * HEIGHT)) == NULL)
		return (handle_fail("init_env : malloc env.img_buf"));
	if ((e->data = ft_memalloc(sizeof(unsigned int) * e->num_pixels)) == NULL)
		return (handle_fail("init_env : malloc env.data"));
	return (RT_SUCCESS);
}

void			clear_texels_buffers(t_ol *ol)
{
	int		i;

	i = 0;
	while (i < RT_MAX_NUM_OBJECTS)
	{
		ft_memdel((void **)&ol[i].texture.buffer);
		ft_memdel((void **)&ol[i].bump_map.buffer);
		i++;
	}
}

void			clear_env(t_env *e)
{
	clear_texels_buffers(e->ll_obj);
	ft_memdel((void **)&e->img_buf);
	ft_memdel((void **)&e->data);
	clear_sdl(&e->sdl);
}
