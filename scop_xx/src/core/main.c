/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 20:00:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

FILE		*scop_log;

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

/*
	1. Documentation
	2. Defensive coding
		a. custom assert
			i. for error handling
			ii. for abotss
		b. persistence check
	3. Error handling
		c. logs : log(char *message, &adress, __FILE__, __LINE__);
		I should be able to look at an error and
			Know where it happened
			What was the value, but how to keep types?
*/

int			main(int argc, char **argv)
{
	t_scop	scop;
	FILE	*fd;

	scop_log = fopen("log", "w");
	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		assert(fd != NULL);
		init_window(&scop.window, argv[1], (int)WIN_WIDTH, (int)WIN_HEIGHT);	
		printf("Loaded window\n");
		init_model(&scop.model);
		printf("Initialized model\n");
		init_camera(&scop.camera);
		printf("Initialized camera\n");
		load_obj(&scop.model, fd);
		printf("Loaded obj\n");
		load_shaders(&scop.gl);
		printf("Loaded shaders\n");
		init_open_gl(&scop);
		printf("Initialised openGl\n");
		render(&scop);
	}
	else
		usage();
	return (0);
}
