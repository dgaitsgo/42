/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 06:17:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 07:07:19 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_mandelbrot	*dispatch_mandelbrot(t_window *window)
{
	t_mandelbrot	*m;

	m = malloc(sizeof(t_mandelbrot));
	init_mandel(m, window);
	m->width = window->width;
	m->height = window->height;
	m->window = window;
//	mandelbrot(*m);
	multi_thread(m);
	return (m);
}

t_newton		*dispatch_newton(t_window *window)
{
	t_newton	*n;

	n = malloc(sizeof(t_newton));
	init_newton(n);
	newton(window, window->width, window->height, *n);
	return (n);
}

t_julia			*dispatch_julia(t_window *window)
{
	t_julia		*j;

	j = malloc(sizeof(t_julia));
	init_julia(j);
	julia(window, window->width, window->height, *j);
	return (j);
}

void			dispatch(t_window *window, int f)
{
	if (f == 0)
		dispatch_mandelbrot(window);
	if (f == 1)
		dispatch_julia(window);
	if (f == 2)
		dispatch_newton(window);
}
