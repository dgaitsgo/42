/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:34:47 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 09:05:05 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calc_sprite(t_sprite_calc_cont *sc,
t_sdlwindow *window, t_texture *texture, t_raycast *wolf)
{
	sc->sprite_x =
	texture->sprite[texture->sprite_order[sc->i]].x - wolf->pos_x;
	sc->sprite_y =
	texture->sprite[texture->sprite_order[sc->i]].y - wolf->pos_y;
	sc->inv_dot =
	1.0 / (wolf->plane_x * wolf->dir_y - wolf->dir_x * wolf->plane_y);
	sc->trans_x =
	sc->inv_dot * (wolf->dir_y * sc->sprite_x - wolf->dir_x * sc->sprite_y);
	sc->trans_y =
	sc->inv_dot *
	(-(wolf->plane_y) * sc->sprite_x + wolf->plane_x * sc->sprite_y);
	sc->sprite_screen_x =
	intify((SDL_WIDTH / 2) * (1 + sc->trans_x / sc->trans_y));
}

void	calc_sprite_height(t_sprite_calc_cont *sc, t_sdlwindow *window)
{
	sc->sprite_height = abs(intify(SDL_HEIGHT / sc->trans_y));
	sc->draw_y_start = -sc->sprite_height / 2 + SDL_HEIGHT / 2;
	if (sc->draw_y_start < 0)
		sc->draw_y_start = 0;
	sc->draw_y_end = sc->sprite_height / 2 + SDL_HEIGHT / 2;
	if (sc->draw_y_end >= SDL_HEIGHT)
		sc->draw_y_end = SDL_HEIGHT - 1;
}

void	calc_sprite_width(t_sprite_calc_cont *sc, t_sdlwindow *window)
{
	sc->sprite_width = abs(intify(SDL_HEIGHT / sc->trans_y));
	sc->draw_x_start = -sc->sprite_width / 2 + sc->sprite_screen_x;
	if (sc->draw_x_start < 0)
		sc->draw_x_start = 0;
	sc->draw_x_end = sc->sprite_width / 2 + sc->sprite_screen_x;
	if (sc->draw_x_end >= SDL_WIDTH)
		sc->draw_x_end = SDL_WIDTH - 1;
}

void	place_sprite(t_sprite *sprite, double x, double y, int texture)
{
	sprite->x = x;
	sprite->y = y;
	sprite->texture = texture;
}

void	init_sprites(t_texture *texture, t_sdlwindow *window)
{
	int i;

	i = 0;
	texture->sprite = malloc(sizeof(t_sprite) * MAX_SPRITES);
	texture->sprite_txtr = malloc(sizeof(SDL_Surface *) * 2);
	texture->sprite_order = malloc(sizeof(int) * TOTAL_SPRITES);
	texture->sprite_distance = malloc(sizeof(double) * TOTAL_SPRITES);
	texture->sprite_txtr[0] = SDL_LoadBMP("textures/sprites/barrel.bmp");
	texture->z_buffer = malloc(sizeof(int) * SDL_WIDTH);
	while (i < MAX_SPRITES)
	{
		place_sprite(&texture->sprite[i],
		random_double(X_MAX),
		random_double(Y_MAX), 0);
		i++;
	}
}
