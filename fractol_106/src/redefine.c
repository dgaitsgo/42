/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:48:20 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/11/08 15:32:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	redefine_mandel(t_window *window, int event)
{
	t_mandelbrot	*m;

		m = (t_mandelbrot *)window->fractal;
	if (event == SCROLL_DOWN)
	{
		zoom_in_mandel(m);
	}
	if (event == SCROLL_UP)
	{
		zoom_out_mandel(m);
	}
	clear_window(window);
	multi_thread(m);
//	mandelbrot(m);
	put_and_loop(window);
}

void	redefine_julia(t_window *window, int event)
{
	t_julia			*j;

	j = (t_julia *)window->fractal;
	if (event == SCROLL_DOWN)
	{
		zoom_in_julia(j);
	}
	if (event == SCROLL_UP)
	{
		zoom_out_julia(j);
	}
	clear_window(window);
	julia(window, window->width, window->height, *j);
	put_and_loop(window);
}

void	redefine_newton(t_window *window, int event)
{
	t_newton	*n;

	n = (t_newton *)window->fractal;
	if (event == SCROLL_DOWN)
	{
		zoom_in_newton(n);
	}
	if (event == SCROLL_UP)
	{
		zoom_out_newton(n);
	}
	clear_window(window);
	newton(window, window->width, window->height, *n);
	put_and_loop(window);
}

int		redefine(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	if (window->frac == MANDEL)
	{
		redefine_mandel(window, button);
	}
	if (window->frac == JULIA)
	{
		redefine_julia(window, button);
	}
	if (window->frac == NEWTON)
	{
		redefine_newton(window, button);
	}
	return (1);
}
