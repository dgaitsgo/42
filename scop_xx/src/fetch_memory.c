/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:37:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/03 20:44:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_model		*init_model_mem(void)
{
	t_model *model;

	model = malloc_if(sizeof(t_model), 1);
	model->root_group = new_group();
	model->n_groups = 1;
	return (model);
}

t_gl		*init_gl_mem(void)
{
	t_gl	*gl;

	gl = malloc_if(sizeof(t_gl), 1);
	gl->root_frag_shdr = new_shader(FRAG);
	gl->root_vert_shdr = new_shader(VERT);
	gl->curr_frag_shdr = gl->root_frag_shdr;
	gl->curr_vert_shdr = gl->root_vert_shdr;
	gl->vao = malloc_if(sizeof(GLuint), 1);
	return (gl);
}
/*
void	init_array_memory(t_model *m)
{
	t_group_lst		*group;
	int				i;
	
	i = 0;
	group = m->root_group;
	m->arr_groups = malloc(sizeof(t_array_group) * (m->n_groups + 1));
	while (i < m->n_groups)
	{
		m->arr_groups[i].vertices = malloc_if(sizeof(float), 3 * group->n_vertices);
		m->arr_groups[i].text_coords = malloc_if(sizeof(float), 3 * group->n_text_coords);
		m->arr_groups[i].normals = malloc_if(sizeof(float), 3 * group->n_normals);
		m->arr_groups[i].vert_indexes = malloc_if(sizeof(int), 3 * group->n_faces);
		m->arr_groups[i].text_indexes = malloc_if(sizeof(int), 3 * group->n_faces);
		m->arr_groups[i].norm_indexes = malloc_if(sizeof(int), 3 * group->n_faces);
		m->arr_groups[i].n_vertices = group->n_vertices;
		m->arr_groups[i].n_text_coords = group->n_text_coords;
		m->arr_groups[i].n_normals = group->n_normals;
		m->arr_groups[i].n_faces = group->n_faces;
		i++;
		group = group->next;
	}
}
*/
