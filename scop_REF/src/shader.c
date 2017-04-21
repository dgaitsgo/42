#include "scop.h"

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
	init_shader_lst(&scop->gl);
	load_shaders(scop->gl);
	/*	Also, gets first shader running*/
	gl->shdr_program = glCreateProgram();
	bind_shader(gl->shdr_program, gl->root_frag_shdr->ref, gl->root_frag_shdr->ref);
}

