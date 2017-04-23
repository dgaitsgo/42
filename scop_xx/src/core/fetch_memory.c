/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:37:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/21 02:44:43 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vertex_table	*fetch_vertex_table_mem(t_obj_data **data,
				int n_groups, int flags)
{
	t_vertex_table	*v;
	int				i;
	int				total_points;

	i = 0;
	v = malloc_if(sizeof(t_vertex_table), n_groups);
	while (i < n_groups)
	{
		//printf("N FACES = %d\n", data[i]->n_faces);
		total_points = 3 * data[i]->quads + ((data[i]->n_faces + 4) / 4) * 9;
		//printf("mallocing : = %d\n", total_points);
		v[i].position = malloc_if(sizeof(float), total_points);
		memset(v[i].position, 0, total_points);
		if (BIT_CHECK(flags, TEXT_COORDS_DEFINED))
		{
			v[i].text_coords = malloc_if(sizeof(float), total_points);
			memset(v[i].text_coords, 0, total_points);
		}
		else
			v[i].text_coords = NULL;
		if (BIT_CHECK(flags, NORMALS_DEFINED))
		{
			v[i].normals = malloc_if(sizeof(float), total_points);
			memset(v[i].normals, 0, total_points);
		}
		else
			v[i].normals = NULL;
		set_to_zero3(&v[i].i_pos, &v[i].i_text, &v[i].i_norm);
		i++;
	}
	return (v);
}

t_obj_data	**fetch_obj_data_mem(t_group_lst *group, int n_groups)
{
	t_obj_data **d;
	int			i;

	i = 0;
	d = malloc_if(sizeof(t_obj_data *), n_groups);
	while (i < n_groups)
	{
		d[i] = malloc_if(sizeof(t_obj_data), 1);
		d[i]->vertices = malloc_if(sizeof(t_vector), group->n_vertices);
		d[i]->text_coords = malloc_if(sizeof(t_vector), group->n_text_coords);
		d[i]->normals = malloc_if(sizeof(t_vector), group->n_normals);
		d[i]->vert_indices = malloc_if(sizeof(int), 4 * group->n_faces);
		d[i]->text_indices = malloc_if(sizeof(int), 4 * group->n_faces);
		d[i]->norm_indices = malloc_if(sizeof(int), 4 * group->n_faces);
		memset(d[i]->vert_indices, 0, 4 * group->n_faces);
		memset(d[i]->text_indices, 0, 4 * group->n_faces);
		memset(d[i]->norm_indices, 0, 4 * group->n_faces);
		d[i]->quads = group->quads;
		d[i]->n_faces = -4;
		d[i]->n_vertices = -1;
		d[i]->n_text_coords = -1;
		d[i]->n_normals = -1;
		group = group->next;
		i++;
	}
	return (d);
}
