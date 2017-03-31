/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:24:06 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:26:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	reset_time(t_time *time)
{
	time->set = TRUE;
	time->start = SDL_GetTicks();
}

void	poll_events(t_sdlwindow *window)
{
	while (SDL_PollEvent(&SDL_EVENT))
		if (SDL_EVENT.type == SDL_QUIT)
			exit_routine(window);
}

void	joystick_event_loop(void **env)
{
	int			quit;
	t_time		*time;
	t_sdlwindow	*window;

	window = env[E_WINDOW];
	time = env[E_TIME];
	quit = 0;
	time->set = 0;
	while (quit != 1)
	{
		if (!time->set)
			reset_time(time);
		time->now = SDL_GetTicks();
		if ((time->now - time->start) > 30)
		{
			time->set = FALSE;
			joystick(env[E_WINDOW], env[E_RAYCAST],
			env[E_MAP], env[E_TEXTURE]);
			render(env);
			put_image(env[E_WINDOW]);
		}
		poll_events(env[E_WINDOW]);
	}
}
