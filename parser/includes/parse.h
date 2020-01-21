/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:48:20 by almoraru          #+#    #+#             */
/*   Updated: 2019/12/20 16:53:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "rt_struct.h"

# define BUFF_SIZE 4096

/*
**	INIT FUNCTIONS
*/
int				init_everything(t_parse *p, char *path);
int				init_mem(t_parse *p);
int				init_strings(t_parse *p);
/*
**	PARSE FUNCTIONS
*/
int				parse(t_parse *p, char *path);
int				update_parser(t_parse *p, char *path);
void			parse_camera(t_parse *p, t_str *s, unsigned int *flag);
void			parse_objects(t_parse *p);
void			parse_sphere(t_parse *p);
void			parse_cone(t_parse *p);
void			parse_cylinder(t_parse *p);
void			parse_plane(t_parse *p);
void			parse_rectangle(t_parse *p);
void			parse_box(t_parse *p);
void			parse_triangle(t_parse *p);
void			parse_pyramid(t_parse *p);
void			parse_ring(t_parse *p);
void			parse_ellipsoid(t_parse *p);
void			parse_paraboloid(t_parse *p);
void			parse_lights(t_parse *p);
void			handle_optional_vaules(t_parse *p);
void			handle_cel_shading(t_parse *p);
void			handle_texels(t_str *s, t_parse *p);
void			parse_filters(t_parse *p);
void			parse_ambient(t_parse *p);
int				ft_brackets(char *line);
int				ft_one_bracket(char *line, int b_ret);

/*
**	CHECK FUNCTONS
*/
void			check_time(
	t_parse *p,
	struct stat *att,
	unsigned int *flag,
	char *path
);

/*
**	MEMORY FUNCTIONS
*/
void			*ft_mem(t_mem *mem, size_t size);
void			is_alloc(void *mem);
void			clear_parse(t_parse *p);

/*
**	STRING FUNCTIONS
*/
void			ft_cpynline(char *dest, char *src);
void			ft_cpynumbers(char *line, char *numbers);
void			ft_cpyonenbr(char *dest, char *src);
void			ft_cpyword(char *line, char *word);
void			ft_second_word(char *line, char *word2);
void			ft_cpymiddleword(char *dest, char *src);
int				ft_check_line_for_numbers(char *line);
int				ft_is_good_number(char c);
int				check_sub_number(char *sub);

/*
**	NUMBER FUNCTOINS
*/
void			handle_3vec_number(t_str *s, t_vec3 *vec);
void			handle_float_number(t_str *s, double *nb);
int				handle_int_number(t_str *s, int nb);

/*
**	UTIL FUNCTIONS
*/
void			handle_float_vec(t_vec3 *vec, char *sub_number, int i);
void			handle_int_vec(t_vec3 *vec, char *sub_number, int i);

#endif
