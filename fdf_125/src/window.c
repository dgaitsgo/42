/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:56:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/06 19:28:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	clear_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->window);
	mlx_destroy_image(window->mlx, window->image);
	window->image = mlx_new_image(window->mlx, window->width, window->height);
	window->pixel_buffer = mlx_get_data_addr(window->image,
	(int *)&window->bits_per_pixel,
	&window->line_size, (int *)&window->endianess);
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
	window->z_buffer = malloc(sizeof(int) *
	(malloc_size(window->pixel_buffer)));
	ft_clear_depth_buffer(window->z_buffer,
	malloc_size(window->pixel_buffer));
}

void	put_and_loop(t_window *window, void **env)
{
	mlx_put_image_to_window(window->mlx, window->window,
	window->image, window->left_offset, window->right_offset);
	mlx_hook(window->window, 2, 0, key_to_event, env);
	mlx_loop(window->mlx);
}
