/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/13 01:03:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

void				load_shaders(t_gl *gl)
{
	DIR				*dir;
	struct dirent	*file;		
	int				fd;
	int				ext;

	/*Should check flags if at least one of each type of shader is present*/
	if (!(dir = opendir(SHADER_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		ext = get_extension(file->d_name);
		if (ext == FRAG_SHDR)
		{
			gl->curr_frag_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_frag_shdr->previous = gl->curr_frag_shdr;
			gl->curr_frag_shdr->next = new_shader(FRAG_SHDR);
			gl->curr_frag_shdr = gl->curr_frag_shdr->next;
		}
		else if (ext == VERT_SHDR)
		{
			gl->curr_vert_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_vert_shdr->previous = gl->curr_vert_shdr;
			gl->curr_vert_shdr->next = new_shader(VERT_SHDR);
			gl->curr_vert_shdr = gl->curr_vert_shdr->next;
		}
	}
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
		scop.model = init_model_mem();
		scop.gl = init_gl_mem();
		load_shaders(scop.gl);
		load_obj(scop.model, fd);
		init_window(&scop.window, argv[1], 1000, 600);
		init_open_gl();
		put_image(&scop);
	}
	else
		usage();
	return (0);
}
