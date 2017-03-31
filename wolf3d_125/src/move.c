/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:31:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:32:12 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	strafe_left(int **world_map, t_raycast *wolf)
{
	int displace_x;
	int displace_y;

	displace_x = intify(wolf->pos_x - wolf->plane_x);
	displace_y = intify(wolf->pos_y - wolf->plane_y);
	if (displace_x >= 0 && displace_x < 24 &&
	world_map[displace_x][(int)wolf->pos_y] == 0)
	{
		wolf->pos_x -= wolf->plane_x * 0.1;
	}
	if (displace_y >= 0 && displace_y < 24 &&
	world_map[(int)wolf->pos_x][displace_y] == 0)
	{
		wolf->pos_y -= wolf->plane_y * 0.1;
	}
}

void	strafe_right(int **world_map, t_raycast *wolf)
{
	int	displace_x;
	int displace_y;

	displace_x = intify(wolf->pos_x + wolf->plane_x);
	displace_y = intify(wolf->pos_y + wolf->plane_y);
	if (displace_x < 24 && displace_x >= 0 &&
	world_map[displace_x][(int)wolf->pos_y] == 0)
	{
		wolf->pos_x += wolf->plane_x * 0.1;
	}
	if (displace_y < 24 && displace_y >= 0 &&
	world_map[(int)wolf->pos_x][displace_y] == 0)
	{
		wolf->pos_y += wolf->plane_y * 0.1;
	}
}

void	move_up(int **world_map, t_raycast *wolf)
{
	int displace_x;
	int displace_y;

	displace_x = intify(wolf->pos_x + wolf->dir_x);
	displace_y = intify(wolf->pos_y + wolf->dir_y);
	if (displace_x < 24 && displace_x >= 0 &&
	world_map[displace_x][(int)wolf->pos_y] == 0)
	{
		wolf->pos_x += wolf->dir_x * 0.1;
	}
	if (displace_y < 24 && displace_y >= 0 &&
	world_map[(int)wolf->pos_x][displace_y] == 0)
	{
		wolf->pos_y += wolf->dir_y * 0.1;
	}
}

void	move_down(int **world_map, t_raycast *wolf)
{
	int displace_x;
	int displace_y;

	displace_x = intify(wolf->pos_x - wolf->dir_x);
	displace_y = intify(wolf->pos_y - wolf->dir_y);
	if (displace_x >= 0 && displace_x < 24 &&
	world_map[displace_x][(int)wolf->pos_y] == 0)
	{
		wolf->pos_x -= wolf->dir_x * 0.1;
	}
	if (displace_y >= 0 && displace_y < 24 &&
	world_map[(int)wolf->pos_x][displace_y] == 0)
	{
		wolf->pos_y -= wolf->dir_y * 0.1;
	}
}
