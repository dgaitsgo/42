/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 01:18:20 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/24 23:22:31 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	explain_program(void)
{
	ft_putstr("usage : fractol [mandelbrot | julia | newton]\n");
}

int		valid_arg(char *arg, t_window *window)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
	{
		init_window(window, 600, 400, "mandelbrot");
		window->frac = MANDEL;
		window->fractal = (void *)dispatch_mandelbrot(window);
	}
	if (ft_strcmp(arg, "julia") == 0)
	{
		init_window(window, 600, 400, "julia");
		window->frac = JULIA;
		window->fractal = (void *)dispatch_julia(window);
	}
	if (ft_strcmp(arg, "newton") == 0)
	{
		init_window(window, 600, 400, "newton");
		window->frac = NEWTON;
		window->fractal = (void *)dispatch_newton(window);
	}
	return (window->frac == INVALID ? 0 : 1);
}

int		main(int argc, char **argv)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->frac = INVALID;
	if ((argc != 2) || (!valid_arg(argv[1], window)))
	{
		explain_program();
	}
	else
	{
		put_and_loop(window);
	}
	return (0);
}
