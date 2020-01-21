/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:29:30 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:29:31 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_t(double *ray_ori, double *ray_dir, double *vmax)
{
	int			i;
	double		tmin[3];
	double		tmax[3];

	i = 0;
	while (i < 3)
	{
		tmin[i] = -ray_ori[i] / ray_dir[i];
		tmax[i] = (vmax[i] - ray_ori[i]) / ray_dir[i];
		if (tmin[i] > tmax[i])
			ft_swap_double(&(tmin[i]), &(tmax[i]));
		if (tmin[0] > tmax[i] || tmax[0] < tmin[i])
			return (FAR);
		tmin[0] = (tmin[0] < tmin[i]) ? tmin[i] : tmin[0];
		tmax[0] = (tmax[0] > tmax[i]) ? tmax[i] : tmax[0];
		i++;
	}
	if (tmin[0] > 0.0)
		return (tmin[0]);
	else if (tmax[0] > 0.0)
		return (tmax[0]);
	return (FAR);
}

static void		set_ray_to_box_coordinate(t_box *box, t_ray *ray)
{
	ray->ori = v3_sub(ray->ori, box->vmin);
	ray->ori = m_mult(box->axis_mat, ray->ori);
	ray->dir = m_mult(box->axis_mat, ray->dir);
}

double			v_intersect_box(t_ray ray, void *object)
{
	t_box		*box;

	box = (t_box *)object;
	set_ray_to_box_coordinate(box, &ray);
	return (get_t(
		(double *)&ray.ori, (double *)&ray.dir, (double *)&box->vmax));
}

static int		pick_max_normal(t_vec3 *n, int *sign)
{
	int			i;
	int			j;
	double		max;
	double		*p_n;

	p_n = (double *)n;
	max = ft_abs_double(p_n[0]);
	j = 0;
	i = 1;
	while (i < 3)
	{
		if (max < ft_abs_double(p_n[i]))
		{
			max = ft_abs_double(p_n[i]);
			j = i;
		}
		i++;
	}
	*sign = (p_n[j] > 0) ? 1 : -1;
	return (j);
}

t_vec3			normal_box(t_ray ray, void *object)
{
	int			sign;
	int			pick;
	t_vec3		cp;
	t_vec3		n;
	t_box		*box;

	box = (t_box *)object;
	set_ray_to_box_coordinate(box, &ray);
	cp = v3_sub(find_point_from_ray(ray), v3_scalar(box->vmax, 0.5));
	n.x = cp.x / ft_abs_double(box->vmax.x);
	n.y = cp.y / ft_abs_double(box->vmax.y);
	n.z = cp.z / ft_abs_double(box->vmax.z);
	pick = pick_max_normal(&n, &sign);
	ft_memcpy(&n, box->axis_mat.arr[pick], sizeof(t_vec3));
	n = v3_scalar(n, sign);
	return (n);
}
