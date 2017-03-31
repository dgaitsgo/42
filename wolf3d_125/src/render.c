/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:34:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:34:42 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_sky(t_sdlwindow *window, t_texture *texture)
{
	t_color	color;
	int		column;
	int		row;

	row = 0;
	while (row < SDL_HEIGHT / 2)
	{
		column = 0;
		while (column < SDL_WIDTH)
		{
			get_sky_color(&color, texture, row, column);
			draw_pixel(window, color, column, row);
			column++;
		}
		row++;
	}
}

void	draw_ground(t_sdlwindow *window)
{
	t_color	color;
	int		column;
	int		row;

	row = SDL_HEIGHT / 2;
	set_color(&color, 200, 30, 90);
	while (row < SDL_HEIGHT - 1)
	{
		column = 0;
		while (column < SDL_WIDTH)
		{
			draw_pixel(window, color, column, row);
			column++;
		}
		row++;
	}
}

void	render(void **env)
{
	draw_sky(env[E_WINDOW], env[E_TEXTURE]);
	draw_ground(env[E_WINDOW]);
	cast_rays(env, env[E_MAP], env[E_RAYCAST], env[E_WINDOW]);
	draw_sprites(env[E_WINDOW], env[E_TEXTURE], env[E_RAYCAST]);
	draw_weapon(env[E_WINDOW], env[E_TEXTURE]);
}
