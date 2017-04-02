/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unordered_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 21:37:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/03 00:42:59 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void						fill_verts(float *unordered_verts,
							t_group_lst *group)
{
	t_vertex_lst			*vert;
	int						i;

	i = 0;
	vert = group->root_vertex;
	while (vert != NULL)
	{
		unordered_verts[i] = vert->vertex.x;
		unordered_verts[i + 1] = vert->vertex.y;
		unordered_verts[i + 2] = vert->vertex.z;
		vert = vert->next;
		i += 3;
	}
}

void						fill_texts(float *unordered_texts,
							t_group_lst *group)
{
	t_text_coord_lst		*text;
	int						i;

	i = 0;
	text = group->root_text_coord;
	while (text != NULL)
	{
		unordered_texts[i] = text->text_coord.x;
		unordered_texts[i + 1] = text->text_coord.y;
		unordered_texts[i + 2] = text->text_coord.z;
		text = text->next;
		i += 3;
	}
}

void						fill_norms(float *unordered_norms,
							t_group_lst *group)
{
	t_normal_lst			*norm;
	int						i;

	i = 0;
	norm = group->root_normal;
	while (norm != NULL)
	{
		unordered_norms[i] = norm->normal.x;
		unordered_norms[i + 1] = norm->normal.y;
		unordered_norms[i + 2] = norm->normal.z;
		norm = norm->next;
		i += 3;
	}
}

void		order_data(float *unordered, float *ordered, int *indexes, int n)
{
	int		i;
	int		j;

	j = 0;		
	i = 0;
	while (i < n)
	{
		ordered[j + 0] = unordered[indexes[i]];
		ordered[j + 1] = unordered[indexes[i + 1]];
		ordered[j + 2] = unordered[indexes[i + 2]];
		i += 3;
		j += 3;
		j++;
	}
}

/*
	there were too many errors with free
	so this thing leaks like a motherfucker.
*/

void		fill_model_arrays(t_model *model)
{
	int				i_group;
	t_group_lst		*group;
	float			*unordered_verts;
	float			*unordered_texts;
	float			*unordered_norms;	

	i_group = 0;
	group = model->root_group;
	while (group != NULL)
	{
		unordered_verts = malloc_if(sizeof(float), 3 * group->n_vertices);
		unordered_texts = malloc_if(sizeof(float), 3 * group->n_text_coords);
		unordered_norms = malloc_if(sizeof(float), 3 * group->n_normals);
		fill_verts(unordered_verts, group);
		fill_texts(unordered_texts, group);
		fill_norms(unordered_norms, group);
		order_data(unordered_verts, model->arr_groups[i_group].vertices, model->arr_groups[i_group].vert_indexes, 3 * group->n_vertices);
		order_data(unordered_verts, model->arr_groups[i_group].text_coords, model->arr_groups[i_group].text_indexes, 3 * group->n_vertices);
		order_data(unordered_verts, model->arr_groups[i_group].normals, model->arr_groups[i_group].norm_indexes, 3 * group->n_vertices);
		i_group++;
		group = group->next;
	}
}
