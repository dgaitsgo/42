/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:23:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/04 03:06:17 by dgaitsgo         ###   ########.fr       */
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


int			count_char(char c, char *s)
{
	int		i;
	int		n;
	
	n = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			n++;
		i++;
	}
	return (n);
}

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

void		check_groups(t_group_lst *group)
{
	int	i;

	i = 0;
	while (group != NULL)
	{
		printf("Group %d\n", i);
		printf("n normals =\t%d\n", group->n_normals);
		printf("n vertices =\t%d\n", group->n_vertices);
		printf("n text coords = %d\n", group->n_text_coords);
		i++;
		group = group->next;
	}
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
//	check_groups(model->root_group);
	fseek(fd, 0, SEEK_SET);	
	write_in_data(model->obj_data, fd, model->flags);
}
