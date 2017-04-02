/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:37:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 03:38:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_model		*init_display_mem(void)
{
	t_model *model;

	model = malloc(sizeof(t_model));
	model->root_group = new_group();
	model->curr_group = model->root_group;
	return (model);
}

t_gl		*init_gl_mem(void)
{
	t_gl	*gl;

	gl = malloc(sizeof(t_gl));
	gl->root_frag_shdr = new_shader(FRAG);
	gl->root_vert_shdr = new_shader(VERT);
	gl->curr_frag_shdr = gl->root_frag_shdr;
	gl->curr_vert_shdr = gl->root_vert_shdr;
	gl->vao = malloc(sizeof(GLuint));
	return (gl);
}
