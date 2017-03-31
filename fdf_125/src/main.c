/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:02:20 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/04 01:15:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_trans		init_trans(void)
{
	t_trans trans;

	trans.y_rot = 0.0f;
	trans.z_rot = 0.0f;
	trans.x_rot = 0.0f;
	trans.x_trad = -1.0f;
	trans.y_trad = 0.0f;
	trans.z_trad = 3.0f;
	trans.x_scale = 1.0f;
	trans.y_scale = 1.0f;
	trans.z_scale = 1.0f;
	trans.a_r_col = 0.4f;
	trans.a_g_col = 0.4f;
	trans.a_b_col = 0.4f;
	trans.b_r_col = 0.4f;
	trans.b_g_col = 0.1f;
	trans.b_b_col = 0.2f;
	trans.c_r_col = 0.3f;
	trans.c_g_col = 0.4f;
	trans.c_b_col = 0.1f;
	return (trans);
}

int			main(int argc, char **argv)
{
	t_window		window;
	t_mesh			*model;
	t_trans			transform;
	t_matrix		trans_matrix;
	void			**env;

	if (argc == 2)
	{
		init_window(&window, 800, 600, argv[1]);
		transform = init_trans();
		trans_matrix = build_transform(&window, &transform);
		model = load_mesh(argv[1]);
		if (model != NULL)
		{
			fill_mesh(&window, model, trans_matrix, &transform);
		}
		env = (void **)malloc(sizeof(void *) * MODULES);
		env[0] = &window;
		env[1] = &transform;
		env[2] = trans_matrix;
		env[3] = model;
		put_and_loop(&window, env);
	}
	return (0);
}
