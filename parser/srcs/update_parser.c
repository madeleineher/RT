/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:17:06 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 17:30:19 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse_line(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	parse_camera(p, s, &p->flag);
	parse_ambient(p);
	parse_lights(p);
	parse_objects(p);
	parse_filters(p);
	handle_cel_shading(p);
}

void		check_words(t_str *s)
{
	ft_second_word(s->line, s->word2);
	if (ft_strcmp(s->word, s->word2) != 0)
		ft_putendl("XML TAGS DONT CORRESPOND");
	if (!(ft_brackets(s->line)))
		ft_putendl("WRONG NUMBER OF BRACKETS");
	ft_cpynumbers(s->line, s->number);
}

void		check_values(t_str *s)
{
	if (!(ft_strchr(s->line, '/')))
	{
		if (!(ft_one_bracket(s->line, 1)))
			ft_putendl("WRONG NUMBER OF BRACKETS");
	}
	else
	{
		if (!(ft_one_bracket(s->line, 2)))
			ft_putendl("WRONG NUMBER OF BRACKETS");
	}
}

int			parse_buffer(t_parse *p)
{
	t_str	*s;

	s = &p->str;
	while (*s->buf != '\0')
	{
		if (*s->buf != '\n' && *s->buf != '\0')
			ft_cpynline(s->line, s->buf);
		if (ft_strlen(s->line) > (1024 * 2))
		{
			ft_putendl("line too big!");
			return (0);
		}
		while (*s->buf != '\n' && *s->buf != '\0')
			s->buf++;
		ft_cpyword(s->line, s->word);
		if (ft_check_line_for_numbers(s->line))
			check_words(s);
		else
			check_values(s);
		parse_line(p);
		s->buf++;
	}
	return (1);
}

int			update_parser(t_parse *p, char *path)
{
	t_str	*s;
	int		i;

	s = &p->str;
	i = 0;
	if (p->flag & 1UL << 2)
	{
		i = 0;
		init_everything(p, path);
		ft_putendl("Reopened file!");
	}
	while ((p->size = read(p->fd, &s->buf[i], BUFF_SIZE)) > 0
		&& (i < 1024 * 12))
		i += p->size;
	s->buf[i] = '\0';
	if (s->buf[0] != '<')
		return (0);
	parse_buffer(p);
	return (0);
}
