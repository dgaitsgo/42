/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:19:06 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/04/30 15:51:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_GRAPH_H
# define __FT_GRAPH_H

# include <float.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector;

typedef struct	s_vertex
{
	t_vector	col;
	t_vector	pos;
}				t_vertex;

typedef struct	s_window
{
	void	*mlx;
	void	*image;
	void	*window;
	float	*z_buffer;
	char	*pixel_buffer;
	int		line_size;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		endianess;
	int		left_offset;
	int		right_offset;
}				t_window;

typedef struct
{
	float	y_rot;
	float	x_rot;
	float	z_rot;
	float	x_trad;
	float	y_trad;
	float	z_trad;
	float	x_scale;
	float	y_scale;
	float	z_scale;
	float	a_r_col;
	float	a_g_col;
	float	a_b_col;
	float	b_r_col;
	float	b_g_col;
	float	b_b_col;
	float	c_r_col;
	float	c_g_col;
	float	c_b_col;
}			t_trans;

typedef struct
{
	int		x_min;
	int		x_max;
	float	x_pre_step;
	float	x_dist;
	float	one_over_zx_step;
	float	depth_x_step;
	float	one_over_z;
	float	depth;
}			t_scan;

typedef struct
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef	struct
{
	t_vector	color;
	t_vector	color_step;
	float		x;
	float		depth;
	float		depth_step;
	float		x_step;
	float		y_step;
	float		one_over_z;
	float		one_over_z_step;
	int			y_start;
	int			y_end;
	int			side;
}	t_edge;

typedef struct
{
	t_vector	color[3];
	t_vector	color_x_step;
	t_vector	color_y_step;
	float		one_over_z[3];
	float		depth[3];
	float		depth_x_step;
	float		depth_y_step;
	float		one_over_zx_step;
	float		one_over_zy_step;
	int			y_start;
	int			y_end;
}	t_gradient;

typedef struct
{
	t_vertex	**vertex;
	int			*index_arr;
	int			vindexes;
	int			findexes;
}	t_mesh;

typedef struct
{
	int			side;
	t_vertex	min_y_vert;
	t_vertex	mid_y_vert;
	t_vertex	max_y_vert;
}				t_triangle;

void			ft_clear_depth_buffer(float *z_buffer, size_t length);
float			ft_twice_triangle_area(t_vertex *min, t_vertex *max,
t_vertex *mid);
double			ft_calc_fov(float theta);
double			ft_normal_rand();
double			ft_in_radians(double degrees);

#endif
