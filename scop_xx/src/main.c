/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/01 20:55:14 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

t_model		*init_display_mem(void)
{
	t_model *model;

	model = malloc(sizeof(t_model));
	model->root_group = new_group();
	model->curr_group = model->root_group;
	return (model);
}

t_gl		*init_gl_mem(void)
{
	t_gl	*gl;

	gl = malloc(sizeof(t_gl));
	gl->root_frag_shdr = new_shader(FRAG);
	gl->root_vert_shdr = new_shader(VERT);
	gl->curr_frag_shdr = gl->root_frag_shdr;
	gl->curr_vert_shdr = gl->root_vert_shdr;
	gl->vao = malloc(sizeof(GLuint));
	return (gl);
}

int			get_extension(const char *file_name)
{
	char	*file_extension;

	file_extension = ft_strrchr(file_name, '.');
	if (file_extension)
	{
		if (ft_strncmp(file_extension, ".frag", 4) == 0)
			return (FRAG);
		if (ft_strncmp(file_extension, ".vert", 4) == 0)
			return (VERT);
	}
	return (NONE);
}

char	*file_to_string(const char *path, const char *file)
{
	FILE	*fd;
	long	size;
	char	buff[512];
	char	*dst;

	sprintf(buff, "%s/%s", path, file);
	if (!(fd = fopen(buff, "r")))
		exit(1);
	fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	dst = malloc(size);
	if (dst)
	{
		fread(dst, 1, size + 1, fd);
		dst[size] = '\0';
	}
	fclose(fd);
	return (dst);
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
		if (ext == FRAG)
		{
			gl->curr_frag_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_frag_shdr->next = new_shader(FRAG);
			gl->curr_frag_shdr = gl->curr_frag_shdr->next;
		}
		else if (ext == VERT)
		{
			gl->curr_vert_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_vert_shdr->next = new_shader(VERT);
			gl->curr_vert_shdr = gl->curr_vert_shdr->next;
		}
	}
}

int			main(int argc, char **argv)
{
	t_scop	display;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 2)
			exit(1);
		display.model = init_display_mem();
		display.gl = init_gl_mem();
		load_shaders(display.gl);
		load_obj(display.model, fd);
		init_window(&display.window, argv[1], 400, 400);
		init_open_gl();
		put_image(&display);
	}
	else
		usage();
	return (0);
}
