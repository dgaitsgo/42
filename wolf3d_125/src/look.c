/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:28:57 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:28:58 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	look_right(t_raycast *wolf)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = wolf->dir_x;
	wolf->rot_amt += 0.02;
	if (wolf->rot_amt > 360)
		wolf->rot_amt = 0;
	if (wolf->rot_amt < 0)
		wolf->rot_amt = 360;
	wolf->dir_x = wolf->dir_x * cos(-(arc_to_radians(wolf->rot_amt))) -
	wolf->dir_y * sin(-(arc_to_radians(wolf->rot_amt)));
	wolf->dir_y = old_dir_x * sin(-(arc_to_radians(wolf->rot_amt))) +
	wolf->dir_y * cos(-(arc_to_radians(wolf->rot_amt)));
	old_plane_x = wolf->plane_x;
	wolf->plane_x = wolf->plane_x * cos(-(arc_to_radians(wolf->rot_amt))) -
	wolf->plane_y * sin(-(arc_to_radians(wolf->rot_amt)));
	wolf->plane_y = old_plane_x * sin(-(arc_to_radians(wolf->rot_amt))) +
	wolf->plane_y * cos(-(arc_to_radians(wolf->rot_amt)));
}

void	look_left(t_raycast *wolf)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = wolf->dir_x;
	wolf->rot_amt += 0.02;
	if (wolf->rot_amt < 0)
		wolf->rot_amt = 360;
	if (wolf->rot_amt > 360)
		wolf->rot_amt = 0;
	wolf->dir_x = wolf->dir_x * cos(arc_to_radians(wolf->rot_amt)) -
	wolf->dir_y * sin(arc_to_radians(wolf->rot_amt));
	wolf->dir_y = old_dir_x * sin(arc_to_radians(wolf->rot_amt)) +
	wolf->dir_y * cos(arc_to_radians(wolf->rot_amt));
	old_plane_x = wolf->plane_x;
	wolf->plane_x = wolf->plane_x * cos(arc_to_radians(wolf->rot_amt)) -
	wolf->plane_y * sin(arc_to_radians(wolf->rot_amt));
	wolf->plane_y = old_plane_x * sin(arc_to_radians(wolf->rot_amt)) +
	wolf->plane_y * cos(arc_to_radians(wolf->rot_amt));
}
