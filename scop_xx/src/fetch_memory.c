/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:37:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/04 19:25:02 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_model		*init_model_mem(void)
{
	t_model *model;

	model = malloc_if(sizeof(t_model), 1);
	model->flags = 0;
	model->root_group = new_group();
	model->n_groups = 1;
	return (model);
}

t_gl		*init_gl_mem(void)
{
	t_gl	*gl;

	gl = malloc_if(sizeof(t_gl), 1);
	gl->root_frag_shdr = new_shader(FRAG_SHDR);
	gl->root_vert_shdr = new_shader(VERT_SHDR);
	gl->curr_frag_shdr = gl->root_frag_shdr;
	gl->curr_vert_shdr = gl->root_vert_shdr;
	gl->vao = malloc_if(sizeof(GLuint), 1);
	return (gl);
}
