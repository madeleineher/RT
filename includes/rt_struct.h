/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:25:21 by jebae             #+#    #+#             */
/*   Updated: 2019/12/20 08:58:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# include "libvector.h"
# include "libimg.h"
# include "SDL2/SDL.h"

# define WIDTH						1600
# define HEIGHT 					1200
# define FAR						2000000.0
# define RT_SUCCESS					0
# define RT_FAIL					1
# define RT_APPROX_0				1e-6
# define RT_MAX_THREAD				50
# define RT_TRUE					1
# define RT_FALSE					0
# define RT_BIAS					1e-3f
# define RT_MAX_TRACE_DEPTH			5
# define RT_NUM_THREADS				50
# define RT_MAX_NUM_OBJECTS			20
# define RT_MAX_NUM_LIGHTS			5

/*
** ray type
*/
# define RT_RAY_TYPE_NONE			0
# define RT_RAY_TYPE_ORIGIN			1
# define RT_RAY_TYPE_REFLECTION		2
# define RT_RAY_TYPE_REFRACTION		3

/*
** t_env bit mask
*/
# define RT_ENV_MASK_CEL_SHADING	0x00000001
# define RT_ENV_MASK_NO_SHADOW		0x00000002
# define RT_ENV_MASK_NO_SPECULAR	0x00000004
# define RT_ENV_MASK_ROUND_N_DOT_L	0x00000008
# define RT_ENV_MASK_SEPHIA			0x00000010
# define RT_ENV_MASK_NEGATIVE		0x00000020
# define RT_ENV_MASK_GRAY_SCALE		0x00000040
# define RT_ENV_MASK_GAUSSIAN_BLUR	0x00000080
# define RT_ENV_MASK_PARSE_FAIL		0x00000100
# define RT_ENV_MASK_PARSE_RELOAD	0x00000200

/*
** Renderer struct
*/
typedef struct		s_mat3
{
	double			arr[3][3];
}					t_mat3;

typedef struct		s_ray
{
	int				type;
	t_vec3			ori;
	t_vec3			dir;
	double			t;
	double			ior;
}					t_ray;

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

typedef struct		s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			*tra;
	t_vec3			*rot;
	t_vec3			right;
	t_vec3			down;
}					t_camera;

typedef struct		s_arg_camera
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			right;
}					t_arg_camera;

typedef struct		s_ll
{
	void			*light;
	t_vec3			its;
	t_vec3			(*get_dir)(t_vec3 *point, void *light);
	double			(*get_distance)(t_vec3 *point, void *light);
}					t_ll;

/*
** lights
*/
typedef struct		s_spherical_light
{
	t_vec3			pos;
}					t_spherical_light;

typedef struct		s_distant_light
{
	t_vec3			dir;
}					t_distant_light;

/*
** set_light_args
*/
typedef struct		s_arg_distant_light
{
	t_vec3			dir;
}					t_arg_distant_light;

typedef struct		s_arg_spherical_light
{
	t_vec3			pos;
}					t_arg_spherical_light;

typedef struct		s_texels
{
	int				width;
	int				height;
	int				repeat;
	unsigned int	*buffer;
}					t_texels;

typedef struct		s_ol
{
	void			*object;
	int				specpower;
	int				specvalue;
	double			reflectivity;
	double			transparency;
	double			ior;
	t_vec3			dif;
	t_texels		texture;
	t_texels		bump_map;
	t_mat3			axis_mat;
	double			(*intersect)(t_ray ray, void *object);
	t_vec3			(*get_normal)(t_ray ray, void *object);
	t_vec2			(*uv_mapping)(
		t_vec3 point,
		t_mat3 *axis_mat,
		t_texels *texels,
		void *object);
	void			(*translate)(t_vec3 *v_translate, void *object);
	void			(*rotate)(t_vec4 *q, t_mat3 *axis_mat, void *object);
}					t_ol;

typedef struct		s_trace_record
{
	int						depth;
	t_ray					ray;
	t_vec3					normal;
	t_vec3					point;
	t_vec3					color;
	t_ol					*obj;
	struct s_trace_record	*prev;
}					t_trace_record;

typedef struct		s_sphere
{
	t_vec3			cen;
	double			radius;
}					t_sphere;

typedef struct		s_cone
{
	t_vec3			cen;
	t_vec3			axis;
	double			angle;
	double			upper_height;
	double			lower_height;
}					t_cone;

typedef struct		s_ellipsoid
{
	t_vec3			cen;
	t_vec3			axis;
	double			d;
	double			sum;
}					t_ellipsoid;

typedef struct		s_paraboloid
{
	t_vec3			cen;
	t_vec3			axis;
	double			k;
	double			min;
	double			max;
}					t_paraboloid;

typedef struct		s_cyl
{
	t_vec3			cen;
	t_vec3			axis;
	double			radius;
	double			height;
}					t_cyl;

typedef struct		s_plane
{
	t_vec3			normal;
	double			d;
}					t_plane;

typedef struct		s_rectangle
{
	t_vec3			p;
	t_vec3			a;
	t_vec3			b;
	t_vec3			normal;
	double			norm_a;
	double			norm_b;
	double			d;
}					t_rectangle;

typedef struct		s_box
{
	t_vec3			vmin;
	t_vec3			vmax;
	t_mat3			axis_mat;
}					t_box;

typedef struct		s_triangle
{
	t_vec3			a;
	t_vec3			ab;
	t_vec3			ac;
	t_vec3			normal;
}					t_triangle;

typedef struct		s_pyramid
{
	t_triangle		sides[4];
	t_vec3			u;
	t_vec3			v;
	double			norm_u;
	double			norm_v;
}					t_pyramid;

typedef struct		s_ring
{
	t_vec3			center;
	t_vec3			normal;
	double			r1;
	double			r2;
	double			d;
}					t_ring;

/*
** set_object args
*/
typedef struct		s_arg_sphere
{
	double			radius;
	t_vec3			cen;
}					t_arg_sphere;

typedef struct		s_arg_plane
{
	double			d;
	t_vec3			normal;
}					t_arg_plane;

typedef struct		s_arg_cone
{
	t_vec3			cen;
	t_vec3			axis;
	double			angle;
	double			upper_height;
	double			lower_height;
}					t_arg_cone;

typedef struct		s_arg_cyl
{
	t_vec3			cen;
	t_vec3			axis;
	double			radius;
	double			height;
}					t_arg_cyl;

typedef struct		s_arg_rectangle
{
	t_vec3			p;
	t_vec3			a;
	t_vec3			b;
}					t_arg_rectangle;

typedef struct		s_arg_box
{
	t_vec3			vmin;
	t_vec3			a;
	t_vec3			b;
	double			norm_c;
}					t_arg_box;

typedef struct		s_arg_triangle
{
	t_vec3			a;
	t_vec3			ab;
	t_vec3			ac;
}					t_arg_triangle;

typedef struct		s_arg_pyramid
{
	t_vec3			a;
	t_vec3			u;
	t_vec3			v;
	double			height;
}					t_arg_pyramid;

typedef struct		s_arg_ring
{
	t_vec3			center;
	t_vec3			normal;
	double			r1;
	double			r2;
}					t_arg_ring;

typedef struct		s_arg_ellipsoid
{
	t_vec3			cen;
	t_vec3			axis;
	double			d;
	double			sum;
}					t_arg_ellipsoid;

typedef struct		s_arg_paraboloid
{
	t_vec3			cen;
	t_vec3			axis;
	double			k;
	double			min;
	double			max;
}					t_arg_paraboloid;

/*
** buffer
*/
typedef struct		s_buffer_info
{
	int				width;
	int				height;
	int				line_per_th;
	int				line_rest;
	void			*buf[2];
}					t_buffer_info;

typedef struct		s_arg_buffer_th_job
{
	int				width;
	int				offset;
	int				work_size;
	void			*buf[2];
}					t_arg_buffer_th_job;

typedef struct		s_creecam
{
	t_vec4			v1;
	t_vec4			v2;
	t_vec4			v3;
}					t_creecam;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*tex;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_env
{
	int				width;
	int				height;
	int				num_pixels;
	int				x;
	int				y;
	int				y_min;
	int				y_max;
	int				num_lights;
	int				num_objs;
	int				current_obj_index;
	int				mask;
	unsigned int	*data;
	unsigned int	*img_buf;
	t_sdl			sdl;
	t_vec3			amb;
	t_vec3			dx;
	t_vec3			dy;
	t_vec3			offset;
	t_camera		cam;
	t_ll			ll_lit[RT_MAX_NUM_LIGHTS];
	t_ol			ll_obj[RT_MAX_NUM_OBJECTS];
}					t_env;

/*
** Parser struct
*/
typedef struct		s_mem
{
	void	*m;
	size_t	usize;
	size_t	tsize;
}					t_mem;

typedef struct		s_str
{
	char		*buf;
	char		*line;
	char		*number;
	char		*sub_number;
	char		*word;
	char		*word2;
	char		*word3;
	char		*time;
	int			op_cl;
}					t_str;

typedef struct		s_parse
{
	t_mem			mem;
	t_camera		*cam;
	t_vec3			*amb;
	t_ol			*ob;
	t_ll			*li;
	t_str			str;
	struct stat		att;
	unsigned int	flag;
	unsigned int	number;
	int				mask;
	int				size;
	int				line;
	int				index;
	int				tex_mode;
	int				l_ind;
	int				fd;
}					t_parse;

#endif
