/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:40:51 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:47:50 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_weapon_data(t_weapon_data *w,
		t_sdlwindow *window, t_texture *texture)
{
	w->gun_height = 200;
	w->gun_width = 200;
	w->screen_x = SDL_WIDTH / 2 - texture->wall_width / 2;
	w->pixels = WEAPON[STATUS]->pixels;
	w->bpp = WEAPON[STATUS]->format->BitsPerPixel;
	w->line_size = WEAPON[STATUS]->pitch;
	w->draw_x_start = -w->gun_height / 2 + w->screen_x;
}

void	find_where_to_start_drawing_weapon(t_weapon_data *w,
		t_sdlwindow *window)
{
	if (w->draw_x_start < 0)
		w->draw_x_start = 0;
	w->draw_x_end = w->gun_height / 2 + w->screen_x;
	if (w->draw_x_end >= SDL_WIDTH)
		w->draw_x_end = SDL_WIDTH - 1;
	w->draw_y_start = -w->gun_height / 2 + SDL_HEIGHT / 2;
	if (w->draw_y_start < 0)
	{
		w->draw_y_start = 0;
	}
	w->draw_y_end = SDL_HEIGHT - 2;
	if (w->draw_y_end >= SDL_WIDTH)
		w->draw_y_end = w->gun_height / 2 + SDL_HEIGHT / 2;
}

t_color	calculate_weapon_color(t_weapon_data *w, t_texture *texture,
		t_sdlwindow *window, int y)
{
	t_color color;

	w->d = y * 256 - SDL_HEIGHT * 128 + w->gun_height * 128;
	w->tex_y = ((w->d * texture->wall_height) / w->gun_height / 256);
	color.b = w->pixels[(w->tex_x * w->bpp >> 3) + w->tex_y * w->line_size];
	color.g = w->pixels[(w->tex_x * w->bpp >> 3) + w->tex_y * w->line_size + 1];
	color.r = w->pixels[(w->tex_x * w->bpp >> 3) + w->tex_y * w->line_size + 2];
	return (color);
}

void	blit_weapon_data_texture(t_weapon_data *w,
		t_sdlwindow *window, t_texture *texture)
{
	int		x;
	int		y;
	t_color color;

	x = w->draw_x_start;
	while (x < w->draw_x_end)
	{
		w->tex_x = intify(256 * (x - (-w->gun_width / 2 + w->screen_x)) *
		texture->wall_width / w->gun_width) / 256;
		y = w->draw_y_start;
		while (y < w->draw_y_end)
		{
			color = calculate_weapon_color(w, texture, window, y);
			if (!(color.b == -104 && color.g == 0 && color.r == -120) &&
			(x + w->gun_width / 4 < SDL_WIDTH &&
			y + w->gun_height < SDL_HEIGHT))
				draw_pixel(window, color,
				x + w->gun_width / 4, y + w->gun_height);
			y++;
		}
		x++;
	}
}

void	draw_weapon(t_sdlwindow *window, t_texture *texture)
{
	t_weapon_data	w;

	init_weapon_data(&w, window, texture);
	find_where_to_start_drawing_weapon(&w, window);
	blit_weapon_data_texture(&w, window, texture);
}
