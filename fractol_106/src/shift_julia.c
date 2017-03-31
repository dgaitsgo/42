/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 07:08:37 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 08:04:42 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double		x_screen_to_image(int x, int width)
{
	double	new_x;

	new_x = ((double)x / (double)width) * (1 - (-2.5)) + (-2.5);
	return (new_x);
}

double		y_screen_to_image(int y, int height)
{
	double	new_y;

	new_y = ((double)y / (double)height) * (1 - (-1)) + (-1);
	return (new_y);
}

int			shift_julia(int x, int y, t_window *window)
{
	t_julia		*j;

	j = (t_julia *)window->fractal;
	j->c_re = x_screen_to_image(x, window->width);
	j->c_im = y_screen_to_image(y, window->height);
	clear_window(window);
	j->y = 0;
	julia(window, window->width, window->height, *j);
	put_and_loop(window);
	return (1);
}
