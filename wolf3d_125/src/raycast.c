/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:32:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:32:47 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	find_intersections(t_raycast *wolf)
{
	if (wolf->ray_dir_x < 0)
	{
		wolf->x_step = -1;
		wolf->vertical_poi =
		(wolf->ray_pos_x - wolf->map_x) * wolf->hyp_x_displacement;
	}
	else
	{
		wolf->x_step = 1;
		wolf->vertical_poi =
		(wolf->map_x + 1.0 - wolf->ray_pos_x) * wolf->hyp_x_displacement;
	}
	if (wolf->ray_dir_y < 0)
	{
		wolf->y_step = -1;
		wolf->horizontal_poi =
		(wolf->ray_pos_y - wolf->map_y) * wolf->hyp_y_displacement;
	}
	else
	{
		wolf->y_step = 1;
		wolf->horizontal_poi =
		(wolf->map_y + 1.0 - wolf->ray_pos_y) * wolf->hyp_y_displacement;
	}
}

void	digital_differential_analysis(t_raycast *wolf, int **world_map)
{
	int ray_hit_a_wall;

	ray_hit_a_wall = FALSE;
	while (ray_hit_a_wall == FALSE)
	{
		if (wolf->vertical_poi < wolf->horizontal_poi)
		{
			wolf->vertical_poi += wolf->hyp_x_displacement;
			wolf->map_x += wolf->x_step;
			wolf->intersection = VERTICAL;
		}
		else
		{
			wolf->horizontal_poi += wolf->hyp_y_displacement;
			wolf->map_y += wolf->y_step;
			wolf->intersection = HORIZONTAL;
		}
		if (world_map[wolf->map_x][wolf->map_y] > 0)
			ray_hit_a_wall = TRUE;
	}
}

void	calc_wall_distance(t_raycast *wolf, t_texture *texture)
{
	if (wolf->intersection == VERTICAL)
	{
		wolf->perp_wall_distance = fabs((wolf->map_x - wolf->ray_pos_x +
		(1 - wolf->x_step) / 2) / wolf->ray_dir_x);
	}
	else
	{
		wolf->perp_wall_distance = fabs((wolf->map_y - wolf->ray_pos_y +
		(1 - wolf->y_step) / 2) / wolf->ray_dir_y);
	}
	texture->z_buffer[wolf->iterator] = wolf->perp_wall_distance;
}

void	calc_pixels_to_draw(t_raycast *wolf, t_sdlwindow *window)
{
	wolf->line_height = abs(intify(SDL_HEIGHT / wolf->perp_wall_distance));
	wolf->draw_start = -(wolf->line_height) / 2 + SDL_HEIGHT / 2;
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	wolf->draw_end = wolf->line_height / 2 + window->height / 2;
	if (wolf->draw_end >= window->height)
	{
		wolf->draw_end = SDL_HEIGHT - 1;
	}
}
