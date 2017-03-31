/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:42:19 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 15:58:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_window(t_sdlwindow *window)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO);
	SDL_WINDOW = SDL_CreateWindow("WÜLF!", 0, 0,
	SDL_WIDTH, SDL_HEIGHT, 0);
	SDL_SCREEN = SDL_GetWindowSurface(SDL_WINDOW);
	SDL_FRAME_BUFFER = malloc(sizeof(char) * (SDL_WIDTH * SDL_HEIGHT * 4));
	SDL_IMAGE = SDL_CreateRGBSurfaceFrom(SDL_FRAME_BUFFER,
	SDL_WIDTH, SDL_HEIGHT, SDL_DEPTH, SDL_BPL, 0, 0, 0, 0);
}

void	init_textures(t_texture *texture, t_sdlwindow *window)
{
	TXTR = malloc(sizeof(SDL_Surface *) * 7);
	texture->weapons = malloc(sizeof(t_weapon));
	texture->weapons->weapon = malloc(sizeof(SDL_Surface *) * 3);
	texture->wall_width = 64;
	texture->wall_height = 64;
	texture->tex_num = 0;
	TXTR[0] = SDL_LoadBMP("textures/walls/bluestone.bmp");
	TXTR[1] = SDL_LoadBMP("textures/walls/colorstone.bmp");
	TXTR[2] = SDL_LoadBMP("textures/walls/eagle.bmp");
	TXTR[3] = SDL_LoadBMP("textures/walls/greystone.bmp");
	TXTR[4] = SDL_LoadBMP("textures/walls/mossy.bmp");
	TXTR[5] = SDL_LoadBMP("textures/walls/redbrick.bmp");
	TXTR[6] = SDL_LoadBMP("textures/walls/wood.bmp");
	texture->skybox = SDL_LoadBMP("textures/sky/skybox.bmp");
	weapon_bmps_to_surfaces(texture);
	init_sprites(texture, window);
}

void	init_window_consts(t_sdlwindow *window)
{
	SDL_WIDTH = 800;
	SDL_HEIGHT = 600;
	SDL_DEPTH = 32;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / 8);
}

void	init_joystick(t_sdlwindow *window)
{
	SDL_JoystickEventState(SDL_ENABLE);
	window->joystick = SDL_JoystickOpen(0);
}

void	initialize_program(void **env)
{
	init_window_consts(env[E_WINDOW]);
	init_window(env[E_WINDOW]);
	init_joystick(env[E_WINDOW]);
	init_raycast(env[E_RAYCAST]);
	init_textures(env[E_TEXTURE], env[E_WINDOW]);
	init_map(env[E_MAP], env[E_TEXTURE]);
}
