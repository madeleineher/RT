/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:25:49 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 17:06:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "rt_struct.h"

/*
** Setting functions
*/
int			init_env(t_env *e);
void		clear_env(t_env *e);
void		clear_texels_buffers(t_ol *ol);
void		key_input(SDL_Keycode sym, t_env *e, t_parse *p);
void		run_event_loop(t_env *e, t_parse *p, char *filename);
int			handle_fail(const char *msg);
int			set_camera(t_arg_camera *arg, t_camera *cam);
int			set_ambient(t_vec3 *amb);
void		set_ray_grid_props(t_env *e);

/*
** Matrix operations
*/
t_vec3		m_mult(t_mat3 m, t_vec3 v);

/*
** Trace functions
*/
int			raytrace(t_env *e);
void		set_origin_trace_record(t_env *e, t_trace_record *rec);
void		set_trace_record(t_trace_record *rec);
int			intersect(t_env *e, t_trace_record *rec);
t_ray		cast_ray(int x, int y, t_env *e);

/*
** Shading functions
*/
t_col		diffuse_specular(
	t_vec3 light_dir,
	t_ll *ll,
	t_trace_record *rec,
	t_env *e
);
t_col		calc_shade(t_env *e, t_trace_record *rec, double coeff);
double		send_shadow_ray(t_trace_record *rec, t_vec3 light_dir, t_env *e);
t_col		reflection_shade(
	t_env *e,
	t_trace_record *prev,
	double coeff
);
t_col		refraction_shade(
	t_env *e,
	t_trace_record *prev,
	double coeff
);
double		get_transmittance(
	t_trace_record *rec,
	t_vec3 light_dir,
	double light_dist,
	t_env *e
);

/*
** Render functions
*/
int			render(t_env *e);
int			render_by_sdl(t_env *e);
int			multi_thread(t_env *e);

/*
** Set light functions
*/
int			set_distant_light(t_ll *ll, t_arg_distant_light *arg);
int			set_spherical_light(t_ll *ll, t_arg_spherical_light *arg);

/*
** Light
*/
t_vec3		distant_light_dir(t_vec3 *point, void *light);
t_vec3		spherical_light_dir(t_vec3 *point, void *light);
double		distant_light_distance(t_vec3 *point, void *light);
double		spherical_light_distance(t_vec3 *point, void *light);

/*
** Set object functions
*/
void		pick_axis_from_plane(t_vec3 *normal, t_mat3 *axis_mat);
int			validate_commons(t_ol *ol);
int			set_sphere(t_ol *ol, t_arg_sphere *arg);
int			set_cone(t_ol *ol, t_arg_cone *arg);
int			set_cyl(t_ol *ol, t_arg_cyl *arg);
int			set_plane(t_ol *ol, t_arg_plane *arg);
int			set_rectangle(t_ol *ol, t_arg_rectangle *arg);
int			set_box(t_ol *ol, t_arg_box *arg);
int			set_triangle(t_ol *ol, t_arg_triangle *arg);
int			set_pyramid(t_ol *ol, t_arg_pyramid *arg);
int			set_ring(t_ol *ol, t_arg_ring *arg);
int			set_paraboloid(t_ol *ol, t_arg_paraboloid *arg);
int			set_ellipsoid(t_ol *ol, t_arg_ellipsoid *arg);

/*
** Intersection functions
*/
double		v_intersect_sp(t_vec3 ray, t_ol *ol);
double		v_intersect_pl(t_ray ray, void *object);
double		v_intersect_cy(t_ray ray, void *object);
double		v_intersect_co(t_ray ray, void *object);
double		v_intersect_sp2(t_ray ray, void *object);
double		v_intersect_rectangle(t_ray ray, void *object);
double		v_intersect_box(t_ray ray, void *object);
double		v_intersect_triangle(t_ray ray, void *object);
double		v_intersect_pyramid(t_ray ray, void *object);
double		v_intersect_ring(t_ray ray, void *object);
double		v_intersect_paraboloid(t_ray ray, void *object);
double		v_intersect_ellipsoid(t_ray ray, void *object);
double		intersection(t_ray ray, t_ol *ol);
double		find_closest_intersection(double a, double b, double c);
t_vec3		find_point_from_ray(t_ray ray);

/*
** Coloring functions
*/
void		color_pixel(int x, int y, t_col sh, t_env *e);
t_col		color_add(t_col c1, t_col c2);
t_col		color_scalar(t_col c, double scalar);

/*
** Normal related functions
*/
t_vec3		normal_sphere(t_ray ray, void *object);
t_vec3		normal_cylinder(t_ray ray, void *object);
t_vec3		normal_cone(t_ray ray, void *object);
t_vec3		normal_plane(t_ray ray, void *object);
t_vec3		normal_rectangle(t_ray ray, void *object);
t_vec3		normal_box(t_ray ray, void *object);
t_vec3		normal_triangle(t_ray ray, void *object);
t_vec3		normal_pyramid(t_ray ray, void *object);
t_vec3		normal_ring(t_ray ray, void *object);
t_vec3		normal_paraboloid(t_ray ray, void *object);
t_vec3		normal_ellipsoid(t_ray ray, void *object);
t_vec3		get_normal(t_ray ray, t_ol *ol);

/*
** UV mapping functions
*/
t_vec2		sphere_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
);
t_vec2		cyl_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
);
t_vec2		cone_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
);
t_vec2		rectangle_uv_mapping(
	t_vec3 point,
	t_mat3 *axis_mat,
	t_texels *texels,
	void *object
);

/*
** Texel functions
*/
int			has_texel(t_ol *ol);
int			uv_to_texel_index(t_vec2 *uv, t_texels *texels);
t_vec3		get_texel_color(t_vec2 *uv, t_texels *texels);
t_vec3		get_bumped_normal(
	t_vec2 *uv,
	t_texels *texels,
	t_vec3 *normal,
	t_mat3 *axis_mat
);
int			set_texels(
	const char *filename,
	int repeat,
	t_texels *texels
);

/*
** Translate functions
*/
void		translate_object(t_env *e, t_vec3 v_translate);
void		sphere_translate(t_vec3 *v_translate, void *object);
void		cone_translate(t_vec3 *v_translate, void *object);
void		cyl_translate(t_vec3 *v_translate, void *object);
void		plane_translate(t_vec3 *v_translate, void *object);
void		rectangle_translate(t_vec3 *v_translate, void *object);
void		box_translate(t_vec3 *v_translate, void *object);
void		triangle_translate(t_vec3 *v_translate, void *object);
void		pyramid_translate(t_vec3 *v_translate, void *object);
void		ring_translate(t_vec3 *v_translate, void *object);
void		ellipsoid_translate(t_vec3 *v_translate, void *object);
void		paraboloid_translate(t_vec3 *v_translate, void *object);

/*
** Rotate functions
*/
t_vec4		q_mul_q(t_vec4 *q1, t_vec4 *q2);
t_vec4		inverse_q(t_vec4 *q);
t_vec4		rotate_q(t_vec3 *n, float theta);
t_vec3		rotate(t_vec4 *q, t_vec3 *v, t_vec4 *q_i);
void		rotate_object(t_env *e, double theta);
void		rotate_object_axis(t_vec4 *q, t_mat3 *axis_mat);
void		sphere_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		box_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		rectangle_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		cone_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		cyl_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		plane_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		pyramid_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		ring_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		triangle_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		ellipsoid_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);
void		paraboloid_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
);

/*
** Cel shading functions
*/
double		round_n_dot_l(double n_dot_l);
int			cel_shading(t_env *e);

/*
** Anti-aliasing functions
*/
int			anti_aliasing(
	unsigned int *after,
	unsigned int *before,
	int width,
	int height
);

/*
** Object manipulation functions
*/
t_vec3		translation(t_vec3 pos, t_vec3 trans);
t_vec3		rotation(t_vec3 axis, t_vec3 rotx, t_vec3 roty, t_vec3 rotz);
int			is_vector_empty(t_vec3 vec);
int			is_matrix_empty(t_vec3 x, t_vec3 y, t_vec3 z);
t_ol		*apply_extra(t_ol *ll_obj);
float		m3_det(t_vec3 x, t_vec3 y, t_vec3 z);

/*
** Print scene as img file
*/
int			buffer2img(unsigned int *buf, int width, int height);

#endif
