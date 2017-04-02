/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_gl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:12:10 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 03:57:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPEN_GL_H
# define __OPEN_GL_H

#include <OpenGL/gl3.h>

# define SHADER_PATH	"./shaders"

enum					e_SHADER_TYPES
{
	NONE,
	FRAG,
	VERT,
};

typedef struct			s_shader_lst
{
	short				type;
	char				*source;
	GLuint				id;
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
	GLint				*vert_index;
	GLint				*norm_indexes;
	GLint				*text_indexes;
}						t_array_group;

typedef struct			s_gl
{
	int					flags;
	t_shader_lst		*root_frag_shdr;
	t_shader_lst		*root_vert_shdr;
	t_shader_lst		*curr_frag_shdr;
	t_shader_lst		*curr_vert_shdr;
	GLuint				shader_program;
	GLint				pos_attrib;
	GLuint				*vao;
	t_array_group		*arr_groups;
}						t_gl;

void					init_open_gl();
struct s_shader_lst		*new_shader(short type);
#endif
