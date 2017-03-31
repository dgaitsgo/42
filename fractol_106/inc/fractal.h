/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:13:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 08:09:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTAL_H
# define __FRACTAL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "events.h"
# include "tile.h"

# define PI 3.14159265359

enum	e_fractal
{
	MANDEL,
	JULIA,
	NEWTON,
	INVALID
};

typedef struct	s_window
{
	void	*mlx;
	void	*image;
	void	*window;
	char	*pixel_buffer;
	int		line_size;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		endianess;
	int		left_offset;
	int		right_offset;
	void	*fractal;
	int		frac;
}				t_window;

typedef	struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_mandelbrot
{
	double	pr;
	double	pi;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	fzoom;
	double	move_x;
	double	move_y;
	double	zoom_x;
	double	zoom_y;
	t_rgb	color;
	t_tile	tile;
	int		x;
	int		y;
	int		max_x;
	int		max_y;
	int		width;
	int		height;
	int		max_iter;
	int		i;
	t_window	*window;
}				t_mandelbrot;

typedef	struct	s_julia
{
	double	c_re;
	double	c_im;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	move_x;
	double	move_y;
	t_rgb	color;
	int		i;
	int		max_iter;
	int		x;
	int		y;
}				t_julia;

typedef	struct	s_newton
{
	t_rgb		color;
	double		temp;
	double		move_x;
	double		move_y;
	double		zoom;
	double		old_re;
	double		old_im;
	double		c_re;
	double		c_im;
	double		new_im;
	double		new_re;
	int			max_iter;
	int			x;
	int			y;
	int			i;
}				t_newton;

typedef struct
{
	t_tile			tile;
	void			*fractal;
}	t_thread_args;

int				shift_julia(int x, int y, t_window *window);
int				move_fractal(int key, t_window *window);
void			*mandelbrot(t_thread_args *args);
//void			*mandelbrot(t_mandelbrot *m);
void			init_mandel(t_mandelbrot *m, t_window *window);
void			init_julia(t_julia *j);
void			julia(t_window *window, int w, int h, t_julia j);
void			init_newton(t_newton *n);
void			newton(t_window *window, int w, int h, t_newton n);
void			init_window(t_window *window, int width,
									int height, char *title);
void			put_and_loop(t_window *window);
void			clear_window(t_window *window);
int				death_to_fractal(t_window *window);
void			draw_pixel(t_window *window, int x, int y, t_rgb color);
t_rgb			calc_color(int r, int g, int b);
t_mandelbrot	*dispatch_mandelbrot(t_window *window);
t_newton		*dispatch_newton(t_window *window);
t_julia			*dispatch_julia(t_window *window);
void			dispatch(t_window *window, int f);
int				ft_strcmp(const char *s1, const char *s2);
int				valid_key(int key);
void			ft_putstr(char *str);
int				redefine(int button, int x, int y, t_window *window);
void			redefine_newton(t_window *window, int event);
void			redefine_julia(t_window *window, int event);
void			redefine_mandel(t_window *window, int event);
void			zoom_out_mandel(t_mandelbrot *m);
void			zoom_out_julia(t_julia *j);
void			zoom_out_newton(t_newton *n);
void			zoom_in_mandel(t_mandelbrot *m);
void			zoom_in_julia(t_julia *j);
void			zoom_in_newton(t_newton *n);

void			multi_thread(t_mandelbrot *m);

#endif
