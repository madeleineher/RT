/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libimg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:03:01 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:12:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIMG_H
# define LIBIMG_H

# include "libft.h"
# include <pthread.h>
# include <math.h>

# define IM_NUM_THREADS		1024
# define IM_SUCCESS			0
# define IM_FAIL			1
# define IM_TRUE			1
# define IM_FALSE			0

typedef struct	s_im_rgb
{
	unsigned int	arr[3];
}				t_im_rgb;

typedef struct	s_im_buffer_info
{
	int				width;
	int				height;
	unsigned int	line_per_th;
	unsigned int	line_rest;
	unsigned char	*buf[2];
}				t_im_buffer_info;

typedef struct	s_im_arg_th
{
	unsigned int		width;
	unsigned int		worksize;
	unsigned int		offset;
	unsigned char		*buf[2];
	pthread_mutex_t		*lock;
}				t_im_arg_th;

typedef struct	s_im_th_info
{
	unsigned int		worksize;
	pthread_t			tid[IM_NUM_THREADS];
	pthread_mutex_t		lock;
}				t_im_th_info;

typedef struct	s_im_edge_gradient
{
	float		theta;
	float		magnitude;
}				t_im_edge_gradient;

typedef void	(*t_func_th)(void *arg_void);

int				im_handle_err(const char *msg);

/*
** img buffer
*/
int				im_for_each_pixel(t_im_buffer_info *buf_info, t_func_th func);
void			im_set_buffer_info(
	int width,
	int height,
	t_im_buffer_info *buf_info
);
int				im_img2buffer_info(
	const char *filename,
	t_im_buffer_info *buf_info
);
int				im_buffer2bmp(
	const char *output_name,
	t_im_buffer_info *buf_info
);
int				im_buffer2jpg(
	const char *output_name,
	t_im_buffer_info *buf_info
);

/*
** rgb
*/
t_im_rgb		im_hex2rgb(unsigned int hex);
unsigned int	im_rgb2hex(t_im_rgb *rgb);
unsigned int	im_reverse_hex_color(unsigned int hex);
void			im_reverse_color_pixels(void *arg_void);

/*
** filter
*/
int				im_gaussian_blur(
	unsigned int *buffer,
	int width,
	int height
);
int				im_sephia(
	unsigned int *buffer,
	int width,
	int height
);
int				im_negative(
	unsigned int *buffer,
	int width,
	int height
);
int				im_gray_scale(
	unsigned int *buffer,
	int width,
	int height
);

/*
** edge detect
*/
int				im_sobel(
	unsigned int *img_buf,
	t_im_edge_gradient *grad_buf,
	int width,
	int height
);
int				im_non_maximum_suppression(
	t_im_edge_gradient *grad_buf,
	int width,
	int height
);
int				im_max_gradient(
	t_im_edge_gradient *grad_buf,
	float *gmax,
	int width,
	int height
);
int				im_hysteresis_thresholding(
	t_im_edge_gradient *grad_buf,
	int width,
	int height,
	float *gmax
);
void			visit(
	size_t i,
	float magnitude,
	t_im_buffer_info *buf_info,
	float *t
);
int				im_gradient2ratio(
	t_im_edge_gradient *grad_buf,
	int width,
	int height,
	float gmax
);
int				im_canny_edge_detect(
	unsigned int *img_buf,
	t_im_edge_gradient *grad_buf,
	int width,
	int height
);

#endif
