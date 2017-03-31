/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:32:53 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:33:53 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calc_ray_vectors(t_raycast *wolf, int width)
{
	wolf->camera_x = 2 * wolf->iterator / (double)width - 1;
	wolf->ray_pos_x = wolf->pos_x;
	wolf->ray_pos_y = wolf->pos_y;
	wolf->ray_dir_x = wolf->dir_x + wolf->plane_x * wolf->camera_x;
	wolf->ray_dir_y = wolf->dir_y + wolf->plane_y * wolf->camera_x;
	wolf->map_x = (int)wolf->ray_pos_x;
	wolf->map_y = (int)wolf->ray_pos_y;
	wolf->hyp_x_displacement = sqrt(1 + (wolf->ray_dir_y * wolf->ray_dir_y) /
	(wolf->ray_dir_x * wolf->ray_dir_x));
	wolf->hyp_y_displacement = sqrt(1 + (wolf->ray_dir_x * wolf->ray_dir_x) /
	(wolf->ray_dir_y * wolf->ray_dir_y));
}

void	cast_rays(void **env, int **world_map,
t_raycast *wolf, t_sdlwindow *window)
{
	wolf->iterator = 0;
	while (wolf->iterator < SDL_WIDTH)
	{
		calc_ray_vectors(wolf, SDL_WIDTH);
		find_intersections(wolf);
		digital_differential_analysis(wolf, world_map);
		calc_wall_distance(wolf, env[E_TEXTURE]);
		calc_pixels_to_draw(wolf, window);
		lookup_texture(world_map, env[E_TEXTURE], wolf);
		write_in_texture(window, wolf, env[E_TEXTURE]);
		wolf->iterator++;
	}
}
