/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:41:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:41:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "libft.h"

void		usage(void)
{
	ft_putstr("usage : ./ray_trace [example.rtsd]\n");
	exit(0);
}

void		change_objects(int max, t_object *object)
{
	for (int i = 0; i < max; i++)
	{
		if (object[i].type == SPHERE)
			object[i].material.refraction = 0.4; 
		else
			object[i].material.refraction = 0.0;
	}
}

int			main(int argc, char **argv)
{
	t_scene		scene;
	t_vector	*color;

	if (argc != 2 || !argv)
		usage();
	else
	{
		initialize_scene(&scene);
		if (parse(argv[1], &scene))
		{
			initialize_window(&scene.window);
			initialize_camera(&scene.camera, &scene.window);
			change_objects(scene.n_objects, scene.object);
			color = new_vector_ptr(0, 0, 0);
			render(&scene.window, &scene.camera, &scene, color);
		}
	}
	return (0);
}
