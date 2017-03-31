/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:23:01 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 08:03:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	move_mandel(int key, t_window *window)
{
	t_mandelbrot *m;

	m = (t_mandelbrot *)window->fractal;
	if (valid_key(key))
	{
		if (key == RIGHT_ARROW)
			m->move_x += 0.3 / m->zoom;
		if (key == LEFT_ARROW)
			m->move_x -= 0.3 / m->zoom;
		if (key == UP_ARROW)
			m->move_y -= 0.3 / m->zoom;
		if (key == DOWN_ARROW)
			m->move_y += 0.3 / m->zoom;
		if (key == NUM_PAD_PLUS)
			zoom_in_mandel(m);
		if (key == NUM_PAD_MINUS)
			zoom_out_mandel(m);
		clear_window(window);
		multi_thread(m);
		put_and_loop(window);
	}
}

void	move_julia(int key, t_window *window)
{
	t_julia		*j;

	j = (t_julia *)window->fractal;
	if (valid_key(key))
	{
		if (key == RIGHT_ARROW)
			j->move_x += 0.3 / j->zoom;
		if (key == LEFT_ARROW)
			j->move_x -= 0.3 / j->zoom;
		if (key == UP_ARROW)
			j->move_y -= 0.3 / j->zoom;
		if (key == DOWN_ARROW)
			j->move_y += 0.3 / j->zoom;
		if (key == NUM_PAD_PLUS)
			zoom_in_julia(j);
		if (key == NUM_PAD_MINUS)
			zoom_out_julia(j);
		clear_window(window);
		julia(window, window->width, window->height, *j);
		put_and_loop(window);
	}
}

void	move_newton(int key, t_window *window)
{
	t_newton		*n;

	n = (t_newton *)window->fractal;
	if (valid_key(key))
	{
		if (key == RIGHT_ARROW)
			n->move_x += 0.3 / n->zoom;
		if (key == LEFT_ARROW)
			n->move_x -= 0.3 / n->zoom;
		if (key == UP_ARROW)
			n->move_y -= 0.3 / n->zoom;
		if (key == DOWN_ARROW)
			n->move_y += 0.3 / n->zoom;
		if (key == NUM_PAD_PLUS)
			zoom_in_newton(n);
		if (key == NUM_PAD_MINUS)
			zoom_out_newton(n);
		clear_window(window);
		newton(window, window->width, window->height, *n);
		put_and_loop(window);
	}
}

int		move_fractal(int key, t_window *window)
{
	if (key == 53)
		death_to_fractal(window);
	if (window->frac == MANDEL)
		move_mandel(key, window);
	if (window->frac == JULIA)
		move_julia(key, window);
	if (window->frac == NEWTON)
		move_newton(key, window);
	return (0);
}
