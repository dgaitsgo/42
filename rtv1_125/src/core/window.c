/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:49:38 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:05:36 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	new_blank_window(t_window *window)
{
	window->mlx = NULL;
	window->image = NULL;
	window->window = NULL;
	window->pixel_buffer = NULL;
}

void	put_pixel(t_window *window, int x, int y, t_vector color)
{
	int i;

	i = (x * window->bits_per_pixel >> 3) + y * window->line_size;
	window->pixel_buffer[i] = (int)color.x;
	window->pixel_buffer[i + 1] = (int)color.y;
	window->pixel_buffer[i + 2] = (int)color.z;
}

void	put_and_loop(t_window *window, void *ptr)
{
	t_scene *scene;

	scene = (t_scene *)ptr;
	mlx_put_image_to_window(window->mlx, window->window,
	window->image, window->left_offset, window->right_offset);
	mlx_hook(window->window, 2, 0, key_to_event, scene);
	mlx_loop(window->mlx);
}
