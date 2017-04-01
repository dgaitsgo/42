/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_gl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:12:10 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/01 20:56:07 by dgaitsgo         ###   ########.fr       */
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
}						t_shader_lst;

typedef struct			s_gl
{
	int					flags;
	t_shader_lst		*root_frag_shdr;
	t_shader_lst		*root_vert_shdr;
	t_shader_lst		*curr_frag_shdr;
	t_shader_lst		*curr_vert_shdr;
	GLuint				shader_program;
	GLint				pos_attrib;
	GLuint				vbo;
	GLuint				*vao;
	GLfloat				*vertices;
}						t_gl;

void					init_open_gl();
struct s_shader_lst		*new_shader(short type);
#endif
