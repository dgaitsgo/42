/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_gl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:12:10 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/27 17:15:44 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPEN_GL_H
# define __OPEN_GL_H

#include <OpenGL/gl3.h>
#include "model.h"
#include "transform.h"

# define SHADER_PATH	"./shaders"

enum					e_SHADER_TYPES
{
	INVALID,
	VERT_SHDR,
	GEOM_SHDR,
	FRAG_SHDR,
};

enum					e_TRANSFORM_TYPES
{
	MODEL,
	OFFSET,
	VIEW,
	PROJECTION,
};

typedef struct			s_shader_lst
{
	short				type;
	GLuint				ref;
	struct s_shader_lst	*next;
	struct s_shader_lst	*previous;
}						t_shader_lst;

typedef struct			s_array_group
{	
	GLuint				vbo;
	t_texture			texture;
	GLfloat				*vertices;
	GLfloat				*normals;
	GLfloat				*text_coords;
	GLint				*vert_indexes;
	GLint				*norm_indexes;
	GLint				*text_indexes;
	int					n_text_coords;
	int					n_normals;
	int					n_vertices;
	int					n_faces;
}						t_array_group;

typedef struct			s_gl
{
	int					flags;

	t_shader_lst		*root_vert_shdr;
	t_shader_lst		*root_geom_shdr;
	t_shader_lst		*root_frag_shdr;

	t_shader_lst		*curr_vert_shdr;
	t_shader_lst		*curr_geom_shdr;
	t_shader_lst		*curr_frag_shdr;

	int					n_vert_shdrs;
	int					n_frag_shdrs;
	int					n_geom_shdrs;

	GLuint				uniform_refs[4];
	GLuint				shdr_program;
	GLint				pos_attrib;
	GLuint				vao;
	GLuint				*vbo;
}						t_gl;


void					check_shader_compile(GLuint shader_name);
void					status_gl(const char *message, int line, char *file);
void					set_standard_shader_uniforms(t_gl *gl);
void					set_buffer_refs();
void					clear_open_gl(t_vector color);
struct s_shader_lst		*new_shader(short type);
void					load_shaders(t_gl *gl);
void					get_active_uniforms(GLuint program, GLuint n_uniforms);
void					check_open_gl_program(GLuint program);
void					associate_standard_uniforms(t_gl *gl,
										t_matrix model,
										t_matrix view,
										t_matrix projection);
#endif
