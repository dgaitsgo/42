/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:01:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/18 11:37:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_pixel(t_window *window, int x, int y, t_vector *color)
{
	int i;

	i = (x * window->bits_per_pixel >> 3) + y * window->line_size;
	window->pixel_buffer[i] = ft_abs((int)(color->x * 255.0f + 0.5f));
	window->pixel_buffer[i + 1] = ft_abs((int)(color->y * 255.0f + 0.5f));
	window->pixel_buffer[i + 2] = ft_abs((int)(color->z * 255.0f + 0.5f));
}
