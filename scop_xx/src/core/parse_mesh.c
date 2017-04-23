/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:23:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 22:26:53 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*

About File

Don't parse yet :
	- assocaited mtls
	- smooth shading coeffs
	- mtls changing up in the middle of the fuckin faces
*/

/*

Face flags :
NEGATIVE_INDEXES	- -3/-30/-20
BARE_FORMAT 		- noseperation 		4 8 2 3
ALL_DEFINED			- many complete		40/30/20/30 19/53/214/30 3592/359/12
TEXT_UNDEFINED 		- texts non defined	40//34 234//234 34/234/21
*/


t_group_lst		*update_group(t_group_lst *group,
								int *n_groups)
{
	group->next = new_group();
	(*n_groups)++;
	return (group->next);	
}

void		check_face_flags(char *line, int *flags)
{
	char	**tokens;
	char	*sub;

	tokens = ft_strsplit(line, ' ');
	if (count_char('/', tokens[1]) == 0)
		BIT_SET(*flags, ONLY_GEOMETRY);
	else
	{
		sub = strsep(&tokens[1], "/");
		if (sub[0] == '-')
			BIT_SET(*flags, NEGATIVE_INDEXES);
		sub = strsep(&tokens[1], "/");
		if (sub[0] != '\0')
			BIT_SET(*flags, TEXT_COORDS_DEFINED);
		sub = strsep(&tokens[1], "/");
		if (sub[0] != '\0')
			BIT_SET(*flags, NORMALS_DEFINED);
		if (BIT_CHECK(*flags, TEXT_COORDS_DEFINED) &&
			BIT_CHECK(*flags, NORMALS_DEFINED))
			BIT_SET(*flags, ALL_VERTS_DEFINED);
	}
}

void		count_group_data(FILE *fd, t_group_lst *group, int *n_groups, int *flags)
{
	t_getline	line;

	init_getline(&line);
	while (getline(&line.s, &line.n, fd) > 0)
	{
		if (line.s[0] == 'g')
			group = update_group(group, n_groups);
		else if (line.s[0] == 'v' && line.s[1] == ' ')
			group->n_vertices++;
		else if (line.s[0] == 'v' && line.s[1] == 't')
			group->n_text_coords++;
		else if (line.s[0] == 'v' && line.s[1] == 'n')
			group->n_normals++;
		else if (line.s[0] == 'f')
		{
			group->n_faces++;
			if (group->n_faces == 1)
				check_face_flags(line.s, flags);
			// means this face is a quad
			if (count_char('/', line.s) > 6)
				group->quads++;
		}
	}
}

void		push_vertex(t_obj_data *data, char *line)
{
	data->n_vertices++;
	sscanf(line, "v %f %f %f", 
	&data->vertices[data->n_vertices].x,
	&data->vertices[data->n_vertices].y,
	&data->vertices[data->n_vertices].z);
}

void		push_text_coord(t_obj_data *data, char *line)
{
	data->n_text_coords++;
	sscanf(line, "vt %f %f %f", 
	&data->text_coords[data->n_text_coords].x,
	&data->text_coords[data->n_text_coords].y,
	&data->text_coords[data->n_text_coords].z);
}

void		push_normal(t_obj_data *data, char *line)
{
	data->n_normals++;
	sscanf(line, "vn %f %f %f", 
	&data->vertices[data->n_vertices].x,
	&data->vertices[data->n_vertices].y,
	&data->vertices[data->n_vertices].z);
}

void		write_in_data(t_obj_data **obj_data, FILE *fd, int flags)
{
	t_getline	line;
	int			i_group;

	i_group = 0;
	init_getline(&line);
	while (getline(&line.s, &line.n, fd) > 0)
	{
		if (line.s[0] == 'g')
			i_group++;
		else if (line.s[0] == 'v' && line.s[1] == ' ')
			push_vertex(obj_data[i_group], line.s);
		else if (line.s[0] == 'v' && line.s[1] == 't')
			push_text_coord(obj_data[i_group], line.s);
		else if (line.s[0] == 'v' && line.s[1] == 'n')
			push_normal(obj_data[i_group], line.s);
		else if (line.s[0] == 'f')
			push_face(obj_data[i_group], line.s, flags);
	}
}

void		check_flags(int flags)
{
	if (BIT_CHECK(flags, ONLY_GEOMETRY))
		ft_putstr("f %d %d %d %d\n");
	if (BIT_CHECK(flags, ALL_VERTS_DEFINED))
		ft_putstr("f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n");
	if (!BIT_CHECK(flags, TEXT_COORDS_DEFINED) &&
		((BIT_CHECK(flags, NORMALS_DEFINED))))
		ft_putstr("f %d//%d %d//%d %d//%d %d//%d\n");
	if (BIT_CHECK(flags, TEXT_COORDS_DEFINED) &&
		(!(BIT_CHECK(flags, NORMALS_DEFINED))))
		ft_putstr ("f %d/%d/ %d/%d/ %d/%d/ %d/%d/\n");
}

void		load_obj(t_model *model, FILE *fd)
{
	t_group_lst		*group;

	group = model->root_group;
	count_group_data(fd, group, &model->n_groups, &model->flags);
	check_flags(model->flags);
	model->obj_data = fetch_obj_data_mem(model->root_group, model->n_groups);

//	/*DEBUG:*/	check_groups(model->root_group);

	fseek(fd, 0, SEEK_SET);	
	write_in_data(model->obj_data, fd, model->flags);
	model->vertex_tables = fetch_vertex_table_mem(model->obj_data, model->n_groups, model->flags);
	order_data(model->vertex_tables, model->obj_data, model->n_groups, model->flags);
	bound_model(model);
}
