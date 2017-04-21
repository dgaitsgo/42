/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/21 03:09:19 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

int			main(int argc, char **argv)
{
	t_scop	scop;
	FILE	*fd;

	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd == NULL)
			exit(1);
		init_model(&scop.model);
		init_camera(&scop.camera);
		load_obj(&scop.model, fd);
		load_shaders(&scop.gl);
		init_window(&scop.window, argv[1], (int)WIN_WIDTH, (int)WIN_HEIGHT);	
		init_open_gl(&scop);
		put_image(&scop);
	}
	else
		usage();
	return (0);
}
