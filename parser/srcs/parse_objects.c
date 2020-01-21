/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 02:59:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 08:05:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		parse_object(
	unsigned long flag,
	void (*parse_func)(t_parse *),
	t_parse *p
)
{
	p->flag |= flag;
	parse_func(p);
	p->index++;
}

static void		parse_objects2(t_str *s, t_parse *p)
{
	if ((ft_strcmp(s->word, "pyramid") == 0))
		parse_object(1UL << 11, &parse_pyramid, p);
	if ((ft_strcmp(s->word, "ring") == 0))
		parse_object(1UL << 12, &parse_ring, p);
	if ((ft_strcmp(s->word, "ellipsoid") == 0))
		parse_object(1UL << 15, &parse_ellipsoid, p);
	if ((ft_strcmp(s->word, "paraboloid") == 0))
		parse_object(1UL << 16, &parse_paraboloid, p);
}

void			parse_objects(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	if (p->index >= 20)
	{
		ft_putendl("too many objects!");
		return ;
	}
	if ((ft_strcmp(s->word, "sphere") == 0))
		parse_object(1UL << 4, &parse_sphere, p);
	if ((ft_strcmp(s->word, "cone") == 0))
		parse_object(1UL << 5, &parse_cone, p);
	if ((ft_strcmp(s->word, "cylinder") == 0))
		parse_object(1UL << 6, &parse_cylinder, p);
	if ((ft_strcmp(s->word, "plane") == 0))
		parse_object(1UL << 7, &parse_plane, p);
	if ((ft_strcmp(s->word, "rectangle") == 0))
		parse_object(1UL << 8, &parse_rectangle, p);
	if ((ft_strcmp(s->word, "box") == 0))
		parse_object(1UL << 9, &parse_box, p);
	if ((ft_strcmp(s->word, "triangle") == 0))
		parse_object(1UL << 10, &parse_triangle, p);
	parse_objects2(s, p);
}
