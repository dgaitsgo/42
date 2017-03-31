/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:51:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 09:49:33 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_raycast(t_raycast *wolf)
{
	wolf->rot_amt = 1;
	wolf->pos_x = INITIAL_X;
	wolf->pos_y = INITIAL_Y;
	wolf->dir_x = -1;
	wolf->dir_y = 0;
	wolf->plane_x = 0;
	wolf->plane_y = 0.66;
}

void	exit_routine(t_sdlwindow *window)
{
	SDL_FreeSurface(window->image);
	SDL_FreeSurface(window->screen);
	SDL_DestroyWindow(SDL_WINDOW);
	SDL_Quit();
	exit(0);
}

void	fetch_initial_memory(void **env)
{
	t_sdlwindow	*window;
	t_raycast	*wolf;
	t_time		*time;
	t_texture	*texture;
	int			**map;

	window = malloc(sizeof(t_sdlwindow));
	wolf = malloc(sizeof(t_raycast));
	time = malloc(sizeof(t_time));
	texture = malloc(sizeof(t_texture));
	map = malloc_world_map();
	env[E_WINDOW] = window;
	env[E_RAYCAST] = wolf;
	env[E_TIME] = time;
	env[E_TEXTURE] = texture;
	env[E_MAP] = map;
}

int		main(int argc, char **argv)
{
	void		**env;

	env = malloc(sizeof(void *) * 10);
	fetch_initial_memory(env);
	initialize_program(env);
	render(env);
	if (argc > 1 && !ft_strcmp("--joystick", argv[1]))
		joystick_event_loop(env);
	else
		keyboard_event_loop(env);
	exit_routine(env[E_WINDOW]);
	return (0);
}
