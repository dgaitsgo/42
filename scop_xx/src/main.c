/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/31 16:30:14 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

t_model		*init_mem(void)
{
	t_model *model;

	model = malloc(sizeof(t_model));
	model->root_group = new_group();
	model->curr_group = model->root_group;
	return (model);
}

int			main(int argc, char **argv)
{
	t_scop	display;
	int		fd;

	if (argc == 2)
	{
		display.model = init_mem();
		fd = open(argv[1], O_RDONLY);
		if (fd < 2)
			exit(1);
		load_obj(display.model, fd);
		init_window(&display.window, argv[1], 400, 400);
		init_open_gl();
		put_image(&display);
	}
	else
		usage();
	return (0);
}
