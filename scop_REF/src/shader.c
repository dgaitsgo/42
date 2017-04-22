/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 04:39:38 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 06:45:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				bind_shader(GLuint program, GLuint vert_ref, GLuint frag_ref)
{
	glAttachShader(program, vert_ref);
	status_gl("Bind shader", __LINE__, __FILE__);
	glAttachShader(program, frag_ref);
	status_gl("Bind shader", __LINE__, __FILE__);
	glLinkProgram(program);
}

void		load_shader(GLenum type, unsigned int *ref, const char *file_name)
{
	GLchar 	*shader_source;

	*ref = glCreateShader(GL_VERTEX_SHADER);
	shader_source = file_to_string(SHADER_PATH, file_name);
	//my_assert(shader_source != NULL);
	glShaderSource(*ref, 1, (const GLchar *const *)&shader_source, NULL);
	status_gl("Asking for sources", __LINE__, __FILE__);
	glCompileShader(*ref);
	status_gl("Compile shader", __LINE__, __FILE__);
}

void			next_shader(int type, t_shader_lst *e)
{
	e->previous = e;
	e->next = new_shader(type);
	e = e->next;
}

void				get_shaders_from_directory(t_gl *gl)
{
	DIR				*dir;
	struct dirent	*file;		
	int				ext;
	unsigned int	*ref;
	GLenum			shader_type;

	/*Should check flags if at least one of each type of shader is present*/
	if (!(dir = opendir(SHADER_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		printf("file->d_name = %s\n", file->d_name);
		ext = get_extension(file->d_name);
		if (ext != INVALID)
		{
			if (ext == VERT_SHDR)
			{
				ref = &gl->curr_vert_shdr->ref;
				shader_type = GL_VERTEX_SHADER;	
				gl->n_vert_shdrs++;
			}
			else if (ext == FRAG_SHDR)
			{
				ref = &gl->curr_frag_shdr->ref;
				shader_type = GL_FRAGMENT_SHADER;	
				gl->n_frag_shdrs++;
			}
			load_shader(shader_type, ref, file->d_name);
			check_shader_compile(*ref);
			next_shader(ext, gl->curr_vert_shdr);
		}
	}
}

void		init_shader_lst(t_gl *gl)
{
	gl->root_frag_shdr = new_shader(FRAG_SHDR);
	gl->root_vert_shdr = new_shader(VERT_SHDR);
	gl->curr_frag_shdr = gl->root_frag_shdr;
	gl->curr_vert_shdr = gl->root_vert_shdr;
	gl->n_vert_shdrs = 0;
	gl->n_frag_shdrs = 0;
}

void		load_shaders(t_gl *gl)
{
	init_shader_lst(gl);
	get_shaders_from_directory(gl);
	/*	Also, gets first shader running*/
	gl->shdr_program = glCreateProgram();
	status_gl("Creating program", __LINE__, __FILE__);
	bind_shader(gl->shdr_program, gl->root_vert_shdr->ref, gl->root_frag_shdr->ref);
	printf("After creat : %d\n", gl->shdr_program);
}
