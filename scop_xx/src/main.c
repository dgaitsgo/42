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

void				bind_shader(GLuint program, GLuint vert_ref, GLuint frag_ref)
{
	glAttachShader(program, vert_ref);
	glAttachShader(program, frag_ref);
	glLinkProgram(program);
}

void				load_shaders(t_gl *gl)
{
	DIR				*dir;
	struct dirent	*file;		
	int				ext;

	/*Should check flags if at least one of each type of shader is present*/
	if (!(dir = opendir(SHADER_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		ext = get_extension(file->d_name);
		if (ext == VERT_SHDR)
		{
			gl->curr_vert_shdr->ref = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(gl->curr_vert_shdr->ref, 1,
			(const GLchar *const *)file_to_string(SHADER_PATH, file->d_name),
				NULL);
			glCompileShader(gl->curr_vert_shdr->ref);
			check_shader_compile(gl->curr_vert_shdr->ref);	
			//gl->curr_vert_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_vert_shdr->previous = gl->curr_vert_shdr;
			gl->curr_vert_shdr->next = new_shader(VERT_SHDR);
			gl->curr_vert_shdr = gl->curr_vert_shdr->next;
			gl->n_vert_shdrs++;
		}
		else if (ext == FRAG_SHDR)
		{
			gl->curr_frag_shdr->ref = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(gl->curr_frag_shdr->ref, 1,
			(const GLchar *const *)file_to_string(SHADER_PATH, file->d_name),
				NULL);
			glCompileShader(gl->curr_frag_shdr->ref);
			check_shader_compile(gl->curr_frag_shdr->ref);	
			//gl->curr_frag_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_frag_shdr->previous = gl->curr_frag_shdr;
			gl->curr_frag_shdr->next = new_shader(FRAG_SHDR);
			gl->curr_frag_shdr = gl->curr_frag_shdr->next;
			gl->n_frag_shdrs++;
		}
	}
	gl->shdr_program = glCreateProgram();
	bind_shader(gl->shdr_program, gl->root_frag_shdr->ref, gl->root_frag_shdr->ref);
}

void	setup_camera(t_camera *camera)
{
	perspective_matrix(camera->perspective);
	set_vector(&camera->forward,0, 0, 1);
	set_vector(&camera->up, 0, 1, 0);
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
		setup_camera(&scop.camera);
		load_shaders(scop.gl);
		printf("%s : Loaded shaders\n", __FILE__);
		load_obj(scop.model, fd);
		printf("%s : Loaded obj\n", __FILE__);
		init_window(&scop.window, argv[1], (int)WIN_WIDTH, (int)WIN_HEIGHT);
		printf("%s : Loaded Window\n", __FILE__);
		init_open_gl();
		put_image(&scop);
	}
	else
		usage();
	return (0);
}
