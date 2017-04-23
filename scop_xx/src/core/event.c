/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 23:28:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 04:24:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	keyboard_event(t_window *window, t_transform *t)
{
	if (KEY == SDLK_a)
		t->translation.x += 0.2f;
	if (KEY == SDLK_d)
		t->translation.x -= 0.2f;
	if (KEY == SDLK_DOWN)
		t->translation.y += 0.2f;
	if (KEY == SDLK_UP)
		t->translation.y -= 0.2f;
	if (KEY == SDLK_s)
		t->translation.z += 0.5f;
	if (KEY == SDLK_w)
		t->translation.z -= 0.5f;
}

void	poll_events(t_window *window, t_transform *t)
{
	while (SDL_PollEvent(&SDL_EVENT))
	{
		if (SDL_EVENT.type == SDL_QUIT || KEY == SDLK_ESCAPE)
			kill_sdl(window);
		keyboard_event(window, t);
	}
}
