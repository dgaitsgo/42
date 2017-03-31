/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bmps_convert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:43:40 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 15:58:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		weapon_bmps_to_surfaces(t_texture *texture)
{
	SDL_Surface *temp_ready;
	SDL_Surface *temp_aim;
	SDL_Surface *temp_fire;

	temp_ready = SDL_LoadBMP("textures/weapons/ready.bmp");
	temp_aim = SDL_LoadBMP("textures/weapons/aim.bmp");
	temp_fire = SDL_LoadBMP("textures/weapons/fire.bmp");
	WEAPON[READY] =
	SDL_ConvertSurfaceFormat(temp_ready, SDL_PIXELFORMAT_RGB24, 0);
	WEAPON[AIM] =
	SDL_ConvertSurfaceFormat(temp_aim, SDL_PIXELFORMAT_RGB24, 0);
	WEAPON[FIRE] =
	SDL_ConvertSurfaceFormat(temp_fire, SDL_PIXELFORMAT_RGB24, 0);
	STATUS = READY;
	SDL_FreeSurface(temp_ready);
	SDL_FreeSurface(temp_aim);
	SDL_FreeSurface(temp_fire);
}
