/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joystick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:36:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/01 16:09:21 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_joystick_pos(t_joystick *j, t_sdlwindow *window)
{
	j->x_move = SDL_JoystickGetAxis(window->joystick, 0);
	j->y_move = SDL_JoystickGetAxis(window->joystick, 1);
	j->y_look = SDL_JoystickGetAxis(window->joystick, 2);
	j->aim = SDL_JoystickGetButton(window->joystick, 6);
	j->fire = SDL_JoystickGetButton(window->joystick, 7);
}

void	apply_action(t_joystick *j, int **world_map,
t_raycast *wolf, t_texture *texture)
{
	if ((j->x_move > 120 && j->x_move < 130) && (j->y_move < -30000))
		move_up(world_map, wolf);
	if ((j->x_move > 120 && j->x_move < 130) && (j->y_move > 30000))
		move_down(world_map, wolf);
	if ((j->x_move < -30000) && (j->y_move > 120 && j->y_move < 130))
		strafe_left(world_map, wolf);
	if ((j->x_move > 30000) && (j->y_move > 120 && j->y_move < 130))
		strafe_right(world_map, wolf);
	if (j->y_look < -25000 && j->y_look > -31000)
		look_right(wolf);
	if (j->y_look > 25000 && j->y_look < 31000)
		look_left(wolf);
	if (j->aim && (!j->fire))
		STATUS = AIM;
	if (j->aim && j->fire)
		STATUS = FIRE;
	if (!j->aim)
		STATUS = READY;
}

void	joystick(t_sdlwindow *window, t_raycast *wolf,
int **world_map, t_texture *texture)
{
	t_joystick j;

	SDL_JoystickUpdate();
	get_joystick_pos(&j, window);
	apply_action(&j, world_map, wolf, texture);
}
