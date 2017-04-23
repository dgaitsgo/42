/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 04:39:38 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 18:22:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
int		calls_to_function = 0;
void		set_standard_shader_uniforms(t_gl *gl)
{
	printf("Calls to function : %d\n", calls_to_function++);

	gl->uniform_refs[MODEL] =
		glGetUniformLocation(gl->shdr_program, "model");
	gl->uniform_refs[VIEW] =
		glGetUniformLocation(gl->shdr_program, "view");
	gl->uniform_refs[PROJECTION] =
		glGetUniformLocation(gl->shdr_program, "proj");
	status_gl("Uniforms bound", __LINE__, __FILE__);
}

//should just take a generic table instead of "t_gl *gl"
void		associate_standard_uniforms(t_gl *gl,
										t_matrix model,
										t_matrix view,
										t_matrix projection)
{
	glUniformMatrix4fv(gl->uniform_refs[MODEL],
		1, GL_TRUE, &model[0][0]);
	glUniformMatrix4fv(gl->uniform_refs[VIEW],
		1, GL_TRUE, &view[0][0]);
	glUniformMatrix4fv(gl->uniform_refs[PROJECTION],
		1, GL_FALSE, &projection[0][0]);
}

void		bind_shader(GLuint program, GLuint vert_ref, GLuint frag_ref)
{
	glAttachShader(program, vert_ref);
	status_gl("Attatched vert", __LINE__, __FILE__);
	glAttachShader(program, frag_ref);
	status_gl("Attatched frag", __LINE__, __FILE__);
	glLinkProgram(program);
	status_gl("Linked Program", __LINE__, __FILE__);
	check_open_gl_program(program);
}

void		load_shader(GLenum type, unsigned int *ref, const char *file_name)
{
	GLchar 	*shader_source;

	*ref = glCreateShader(type);
	shader_source = file_to_string(SHADER_PATH, file_name);
	//my_assert(shader_source != NULL);
	glShaderSource(*ref, 1, (const GLchar *const *)&shader_source, NULL);
	status_gl("Asking for sources", __LINE__, __FILE__);
	glCompileShader(*ref);
	status_gl("Compile shader", __LINE__, __FILE__);
	//free(shader_source)
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
}