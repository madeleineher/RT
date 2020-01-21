/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:52:15 by sabonifa          #+#    #+#             */
/*   Updated: 2019/12/20 16:04:49 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H
# include <math.h>

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

t_vec2			v2_add(t_vec2 u, t_vec2 v);
t_vec3			v3_add(t_vec3 u, t_vec3 v);
t_vec4			v4_add(t_vec4 u, t_vec4 v);
t_vec2			v2_sub(t_vec2 u, t_vec2 v);
t_vec3			v3_sub(t_vec3 u, t_vec3 v);
t_vec4			v4_sub(t_vec4 u, t_vec4 v);
t_vec2			v2_scalar(t_vec2 u, double k);
t_vec3			v3_scalar(t_vec3 u, double k);
t_vec4			v4_scalar(t_vec4 u, double k);
double			v2_dotpdt(t_vec2 u, t_vec2 v);
double			v3_dotpdt(t_vec3 u, t_vec3 v);
double			v4_dotpdt(t_vec4 u, t_vec4 v);
double			v2_norm(t_vec2 u);
double			v3_norm(t_vec3 u);
double			v4_norm(t_vec4 u);
double			v2_norm2(t_vec2 u);
double			v3_norm2(t_vec3 u);
double			v4_norm2(t_vec4 u);
t_vec3			v3_cross(t_vec3 u, t_vec3 v);
t_vec4			v4_cross(t_vec4 u, t_vec4 v);
t_vec2			v2_fromcoord(double x, double y);
t_vec3			v3_fromcoord(double x, double y, double z);
t_vec4			v4_fromcoord(double x, double y, double z, double w);
t_vec2			v2_frompoints(t_vec2 ori, t_vec2 dest);
t_vec3			v3_frompoints(t_vec3 ori, t_vec3 dest);
t_vec4			v4_frompoints(t_vec4 ori, t_vec4 dest);
t_vec2			v2_normalise(t_vec2 u);
t_vec3			v3_normalise(t_vec3 u);
t_vec4			v4_normalise(t_vec4 u);
#endif
