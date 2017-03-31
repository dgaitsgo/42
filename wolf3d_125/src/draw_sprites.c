/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:22:58 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 08:48:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	order_sprites(t_texture *texture, t_raycast *wolf)
{
	int i;

	i = 0;
	while (i < TOTAL_SPRITES)
	{
		texture->sprite_order[i] = i;
		texture->sprite_distance[i] =
		((wolf->pos_x - texture->sprite[i].x) *
		(wolf->pos_x - texture->sprite[i].x) +
		(wolf->pos_y - texture->sprite[i].y) *
		(wolf->pos_y - texture->sprite[i].y));
		i++;
	}
	comb_sort(texture->sprite_order, texture->sprite_distance, 0, 0);
}

void	lookup_sprite_color(t_sprite_calc_cont *sc,
t_sdlwindow *window, t_texture *texture)
{
	t_color color;
	int		bpp;
	int		line_size;
	char	*pixels;

	pixels = texture->sprite_txtr[0]->pixels;
	bpp = texture->sprite_txtr[0]->format->BitsPerPixel;
	line_size = texture->sprite_txtr[0]->pitch;
	sc->y = sc->draw_y_start;
	while (sc->y < sc->draw_y_end)
	{
		sc->d = sc->y * 256 - SDL_HEIGHT * 128 + sc->sprite_height * 128;
		sc->tex_y =
		((sc->d * texture->wall_height) / sc->sprite_height / 256);
		color.r = pixels[(sc->tex_x * bpp >> 3) + sc->tex_y * line_size];
		color.g = pixels[(sc->tex_x * bpp >> 3) + sc->tex_y * line_size + 1];
		color.b = pixels[(sc->tex_x * bpp >> 3) + sc->tex_y * line_size + 2];
		if (color.r != 0 && color.g != 0 && color.b != 0)
			draw_pixel(window, color, sc->stripe, sc->y);
		sc->y++;
	}
}

void	draw_stripe(t_sprite_calc_cont *sc,
t_sdlwindow *window, t_texture *texture)
{
	sc->stripe = sc->draw_x_start;
	while (sc->stripe < sc->draw_x_end)
	{
		sc->tex_x =
		intify(256 * (sc->stripe - (-sc->sprite_width / 2 +
		sc->sprite_screen_x)) * texture->wall_width / sc->sprite_width) / 256;
		if (sc->trans_y > 0 && sc->stripe > 0 &&
		sc->stripe < SDL_WIDTH && sc->trans_y < texture->z_buffer[sc->stripe])
		{
			lookup_sprite_color(sc, window, texture);
		}
		sc->stripe++;
	}
}

void	project_sprites(t_sdlwindow *window,
t_texture *texture, t_raycast *wolf)
{
	t_sprite_calc_cont	sc;

	sc.i = 0;
	while (sc.i < TOTAL_SPRITES)
	{
		calc_sprite(&sc, window, texture, wolf);
		calc_sprite_height(&sc, window);
		calc_sprite_width(&sc, window);
		draw_stripe(&sc, window, texture);
		sc.i++;
	}
}

void	draw_sprites(t_sdlwindow *window, t_texture *texture, t_raycast *wolf)
{
	order_sprites(texture, wolf);
	project_sprites(window, texture, wolf);
}
