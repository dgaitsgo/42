/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 02:49:20 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 07:50:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		death_to_fractal(t_window *window)
{
	mlx_clear_window(window->mlx, window->window);
	mlx_destroy_image(window->mlx, window->image);
	exit(0);
	return (0);
}

void	clear_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->window);
	mlx_destroy_image(window->mlx, window->image);
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	window->pixel_buffer = mlx_get_data_addr(window->image,
	(int *)&window->bits_per_pixel,
	&window->line_size, (int *)&window->endianess);
}

void	put_and_loop(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->window,
	window->image, window->left_offset, window->right_offset);
	mlx_hook(window->window, 2, 0, move_fractal, window);
	mlx_hook(window->window, 4, 0, redefine, window);
	if (window->frac == JULIA)
		mlx_hook(window->window, 6, 0, shift_julia, window);
	mlx_loop(window->mlx);
}

void	init_window(t_window *window, int width, int height, char *title)
{
	window->width = width;
	window->height = height;
	window->left_offset = 0;
	window->right_offset = 0;
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, window->width,
	window->height, title);
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	window->pixel_buffer = mlx_get_data_addr(window->image,
	(int *)&window->bits_per_pixel,
	&window->line_size, (int *)&window->endianess);
}
