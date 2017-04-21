/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_gl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:12:10 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/21 02:59:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPEN_GL_H
# define __OPEN_GL_H

#include <OpenGL/gl3.h>
#include "wavefront_obj.h"

# define SHADER_PATH	"./shaders"

enum					e_SHADER_TYPES
{
	NONE,
	FRAG_SHDR,
	VERT_SHDR,
};

typedef struct			s_shader_lst
{
	short				type;
	char				*source;
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
	t_shader_lst		*root_frag_shdr;
	t_shader_lst		*root_vert_shdr;
	t_shader_lst		*curr_frag_shdr;
	t_shader_lst		*curr_vert_shdr;
	int					n_vert_shdrs;
	int					n_frag_shdrs;
	GLuint				shdr_program;
	GLint				pos_attrib;
	GLuint				vao;
	GLuint				vbo;
}						t_gl;

void					init_open_gl();
struct s_shader_lst		*new_shader(short type);
#endif
