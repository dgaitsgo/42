/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openGL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:36:43 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/18 18:33:24 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		clear_open_gl(void)
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void	set_buffer_refs(t_scop *scop)
{
	t_gl		*gl;
	GLfloat 	*vertices;
	int			n_faces;

	gl = scop->gl;
	n_faces = scop->model->vertex_tables->i_pos;
	vertices = scop->model->vertex_tables->position;

	/* Gen VAOs*/
	glGenVertexArrays(1, &gl->vao);
	glBindVertexArray(gl->vao);
	status_gl("Got some vbaos", __LINE__, __FILE__);

	/* Generate VBOs */
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * n_faces, vertices, GL_STATIC_DRAW);
	status_gl("Got some vaos", __LINE__, __FILE__);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	status_gl("Got some vbos", __LINE__, __FILE__);
}

void		init_open_gl(t_scop *scop)
{
	set_buffer_refs(scop);
}
