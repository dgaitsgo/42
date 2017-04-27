/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openGL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:36:43 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/27 17:55:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

//			this should be more general to take a color and  a flag
void		clear_open_gl(t_vector color)
{
	rgb_to_normal(&color);
	glClearColor(color.x, color.y, color.z, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void		generate_vbo(GLuint *ref, int n_faces, GLfloat *vertices)
{
	glGenBuffers(1, ref);
	glBindBuffer(GL_ARRAY_BUFFER, *ref);
	glBufferData(GL_ARRAY_BUFFER,
	sizeof(GLfloat) * n_faces, vertices, GL_STATIC_DRAW);
	status_gl("Added VBO", __LINE__, __FILE__);
}

void		generate_vao(GLuint *ref)
{
	glGenVertexArrays(1, ref);
	glBindVertexArray(*ref);
	status_gl("Added VAO", __LINE__, __FILE__);
}

void		default_vertex_attributes(void)
{	
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	status_gl("Default vertex Attributes", __LINE__, __FILE__);
}

void		init_open_gl(t_scop *scop)
{
	int i;

	i = 0;
	scop->gl.vbo = ft_memalloc(sizeof(GLuint) * scop->model.n_groups);
	while (i < scop->model.n_groups)
	{
		generate_vbo(	&scop->gl.vbo[i],
						scop->model.vertex_tables[i].i_pos,
						scop->model.vertex_tables[i].positions);
		i++;
	}
	generate_vao(&scop->gl.vao);
	default_vertex_attributes();
}
