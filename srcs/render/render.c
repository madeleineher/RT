/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:53 by jebae             #+#    #+#             */
/*   Updated: 2019/12/17 20:59:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		erase_buffers(t_env *e)
{
	ft_bzero(e->img_buf, sizeof(unsigned int) * (e->num_pixels / 4));
	ft_bzero(e->data, sizeof(unsigned int) * e->num_pixels);
}

static int		set_filter(t_env *e)
{
	int		(*filter)(unsigned int *, int, int);

	filter = NULL;
	if (e->mask & RT_ENV_MASK_SEPHIA)
		filter = &im_sephia;
	else if (e->mask & RT_ENV_MASK_NEGATIVE)
		filter = &im_negative;
	else if (e->mask & RT_ENV_MASK_GRAY_SCALE)
		filter = &im_gray_scale;
	else if (e->mask & RT_ENV_MASK_GAUSSIAN_BLUR)
		filter = &im_gaussian_blur;
	if (filter == NULL)
		return (RT_SUCCESS);
	if (filter(e->img_buf, e->width / 2, e->height / 2) == IM_FAIL)
		return (handle_fail("filter"));
	return (RT_SUCCESS);
}

int				render_by_sdl(t_env *e)
{
	if (SDL_UpdateTexture(e->sdl.tex, NULL,
		e->img_buf, sizeof(unsigned int) * WIDTH) != 0)
		return (handle_fail("SDL_UpdateTexture"));
	if (SDL_RenderClear(e->sdl.renderer) != 0)
		return (handle_fail("SDL_RenderClear"));
	if (SDL_RenderCopy(e->sdl.renderer, e->sdl.tex, NULL, NULL) != 0)
		return (handle_fail("SDL_RenderCopy"));
	SDL_RenderPresent(e->sdl.renderer);
	return (RT_SUCCESS);
}

int				render(t_env *e)
{
	int		(*render_func)(t_env *);

	erase_buffers(e);
	if ((e->mask & RT_ENV_MASK_CEL_SHADING))
		render_func = &cel_shading;
	else
		render_func = &multi_thread;
	if (render_func(e) == RT_FAIL)
		return (RT_FAIL);
	if (anti_aliasing(e->img_buf, e->data,
		e->width / 2, e->height / 2) == RT_FAIL)
		return (RT_FAIL);
	if (set_filter(e) == RT_FAIL)
		return (RT_FAIL);
	return (render_by_sdl(e));
}
