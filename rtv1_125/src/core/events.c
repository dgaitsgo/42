/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 23:19:00 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 00:37:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

int		key_to_event(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		mlx_clear_window(scene->window.mlx, scene->window.window);
		mlx_destroy_image(scene->window.mlx, scene->window.image);
		exit(0);
	}
	return (0);
}
