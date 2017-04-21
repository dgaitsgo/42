/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:26:44 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/20 23:34:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		valid_key(int key)
{
	if (key == 124 || key == 126 || key == 123)
		return (1);
	if (key == 12 || key == 13 || key == 14 || key == 0 || key == 1 || key == 2)
		return (1);
	if (key == 17 || key == 16 || key == 5 || key == 4 ||
	key == 32 || key == 38)
		return (1);
	if (key == 18 || key == 19 || key == 20 || key == 21 ||
		key == 23 || key == 22 || key == 26 || key == 28 || key == 25)
		return (1);
	return (0);
}

void	kill_vertices(t_mesh *model)
{
	int i;

	i = 0;
	while (i < model->vindexes)
	{
		free(model->vertex[i]);
		i++;
	}
}

void	destroy_event(void **env)
{
	t_window	*window;
	t_mesh		*model;
	t_trans		*transf;
	t_matrix	trans;

	window = (t_window *)env[0];
	transf = (t_trans *)env[1];
	trans = (t_matrix)env[2];
	model = (t_mesh *)env[3];
	mlx_clear_window(window->mlx, window->window);
	mlx_destroy_image(window->mlx, window->image);
	kill_vertices(model);
	free(model->vertex);
	free(model->index_arr);
	free(model);
	free(trans);
	free(window->z_buffer);
	exit(0);
}

void	redraw_routine(void **env)
{
	t_window	*window;
	t_mesh		*model;
	t_trans		*transf;
	t_matrix	trans;

	window = (t_window *)env[0];
	transf = (t_trans *)env[1];
	trans = (t_matrix)env[2];
	model = (t_mesh *)env[3];
	clear_window(window);
	ft_clear_depth_buffer(window->z_buffer, malloc_size(window->pixel_buffer));
	trans = build_transform(window, transf);
	fill_mesh(window, model, trans, transf);
	put_and_loop(window, env);
}

int		key_to_event(int keycode, void **env)
{
	if (valid_key(keycode))
	{
		select_modify(keycode, env);
		redraw_routine(env);
	}
	if (keycode == 53)
	{
		destroy_event(env);
	}
	return (0);
}
