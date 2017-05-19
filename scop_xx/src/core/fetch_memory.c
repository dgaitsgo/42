/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:37:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 22:30:38 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vertex_table	*fetch_vertex_table_mem(t_obj_data **data,
										int n_groups,
										int flags)
{
	t_vertex_table	*v;
	int				i;
	int				total_points;

	i = 0;
	v = ft_memalloc(sizeof(t_vertex_table) * n_groups);
	while (i < n_groups)
	{
		total_points = 3 * data[i]->quads + ((data[i]->n_faces + 4) / 4) * 9;
		printf("TOTAL POINTS = %d\n", total_points);
		v[i].positions = ft_memalloc(sizeof(float) * total_points);
		if (BIT_CHECK(flags, TEXT_COORDS_DEFINED))
			v[i].text_coords = ft_memalloc(sizeof(float) * total_points);
		else
			v[i].text_coords = NULL;
		if (BIT_CHECK(flags, NORMALS_DEFINED))
			v[i].normals = ft_memalloc(sizeof(float) * total_points);
		else
			v[i].normals = NULL;
		set_to_zero3(&v[i].i_pos, &v[i].i_text, &v[i].i_norm);
		i++;
	}
	return (v);
}

t_obj_data	**fetch_obj_data_mem(	t_group_lst *group,
									int n_groups)
{
	t_obj_data **d;
	int			i;

	i = 0;
	d = ft_memalloc(sizeof(t_obj_data *) * n_groups);
	while (i < n_groups)
	{
		d[i] = ft_memalloc(sizeof(t_obj_data));
		printf("I'm ASKING FOR THIS MANY VERTICES IN GROUPS ===== %d\n", group->n_vertices);
		d[i]->vertices = ft_memalloc(sizeof(t_vector) * group->n_vertices);
		d[i]->text_coords = ft_memalloc(sizeof(t_vector) * group->n_text_coords);
		d[i]->normals = ft_memalloc(sizeof(t_vector) * group->n_normals);
		d[i]->vert_indices = ft_memalloc(sizeof(int) * 4 * group->n_faces);
		d[i]->text_indices = ft_memalloc(sizeof(int) * 4 * group->n_faces);
		d[i]->norm_indices = ft_memalloc(sizeof(int) * 4 * group->n_faces);
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
