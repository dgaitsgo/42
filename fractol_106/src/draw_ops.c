/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 02:48:18 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/24 22:16:11 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_rgb	calc_color(int r, int g, int b)
{
	t_rgb	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

void	draw_pixel(t_window *window, int x, int y, t_rgb color)
{
	int i;

	i = (x * window->bits_per_pixel >> 3) + y * window->line_size;
	window->pixel_buffer[i] = color.r;
	window->pixel_buffer[i + 1] = color.g;
	window->pixel_buffer[i + 2] = color.b;
}
