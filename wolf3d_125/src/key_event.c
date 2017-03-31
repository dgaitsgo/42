/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:28:28 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:28:36 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_to_event(t_sdlwindow *window, int **world_map, t_raycast *wolf)
{
	if (KEY == SDLK_w)
		move_up(world_map, wolf);
	if (KEY == SDLK_s)
		move_down(world_map, wolf);
	if (KEY == SDLK_a)
		strafe_left(world_map, wolf);
	if (KEY == SDLK_d)
		strafe_right(world_map, wolf);
	if (KEY == SDLK_RIGHT)
		look_right(wolf);
	if (KEY == SDLK_LEFT)
		look_left(wolf);
	if (KEY == SDLK_ESCAPE)
		return (0);
	return (1);
}

void	keyboard_event_loop(void **env)
{
	int			quit;
	t_sdlwindow	*window;
	t_raycast	*wolf;
	int			**world_map;

	window = env[E_WINDOW];
	wolf = env[E_RAYCAST];
	world_map = env[E_MAP];
	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&SDL_EVENT))
		{
			if ((!key_to_event(window, world_map, wolf)) ||
			(SDL_EVENT.type == SDL_QUIT))
			{
				quit = 1;
				break ;
			}
			render(env);
			put_image(window);
		}
	}
}
