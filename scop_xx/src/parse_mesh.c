/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:23:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/03 20:44:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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

t_group_lst		*update_group(t_group_lst *group, long byte_marker,
								int *n_groups)
{
	group->next = new_group();
	group->next->byte_marker = byte_marker;
	(*n_groups)++;
	return (group->next);	
}

void count_group_data(FILE *fd, t_group_lst *group, int *n_groups)
{
	t_getline	line;
	long		curr_bytes;
	long		total_bytes;

	total_bytes = 0;
	init_getline(&line);
	group->byte_marker = 0;
	while ((curr_bytes = getline(&line.s, &line.n, fd)) > 0)
	{
		total_bytes += curr_bytes;
		if (line.s[0] == 'g')
			group = update_group(group, total_bytes, n_groups);
		else if (line.s[0] == 'v' && line.s[1] == ' ')
			group->n_vertices++;
		else if (line.s[0] == 'v' && line.s[1] == 't')
			group->n_text_coords++;
		else if (line.s[0] == 'v' && line.s[1] == 'n')
			group->n_normals++;
		else if (line.s[0] == 'f')
		{
			group->n_faces++;
			// means this face is a quad
			if (count_char('/', line.s) > 6)
			{
				group->n_normals += 3;
				group->n_vertices += 3;
				group->n_text_coords += 3;
			}
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
		printf("n text coords = \t%d\n", group->n_text_coords);
		printf("byte marker = \t%lu\n", group->byte_marker);
		i++;
		group = group->next;
	}
}

t_obj_data		**fetch_obj_data_mem(t_group_lst *group, int n_groups)
{
	t_obj_data **d;
	int			i;

	i = 0;
	d = malloc_if(sizeof(t_obj_data *), n_groups);
	printf("n_group = %d\n", n_groups);
	while (i < n_groups)
	{
		d[i] = malloc_if(sizeof(t_obj_data), 1);
		d[i]->vertices = malloc_if(sizeof(t_vector), group->n_vertices);
		d[i]->text_coords = malloc_if(sizeof(t_vector), group->n_text_coords);
		d[i]->normals = malloc_if(sizeof(t_vector), group->n_normals);
		d[i]->vert_indices = malloc_if(sizeof(int), 4 * group->n_faces);
		d[i]->text_indices = malloc_if(sizeof(int), 4 * group->n_faces);
		d[i]->norm_indices = malloc_if(sizeof(int), 4 * group->n_faces);
		printf("verts = %d\n", group->n_vertices);
		printf("txts = %d\n", group->n_text_coords);
		printf("norms= %d\n", group->n_normals);
		printf("fcs = %d\n", group->n_faces);
		d[i]->n_vertices = -1;
		d[i]->n_text_coords = -1;
		d[i]->n_normals = -1;
		group = group->next;
		i++;
	}
	return (d);
}

void		push_vertex(t_vector *vertex, char **line)
{
	vertex->x = atof(strsep(line, " "));
	vertex->y = atof(strsep(line, " "));
	vertex->z = atof(strsep(line, " "));
}

void		write_in_data(t_obj_data **obj_data, t_group_lst *group, FILE *fd)
{
	t_getline	line;
	int			i_group;

	i_group = 0;
	init_getline(&line);
	while (getline(&line.s, &line.n, fd) > 0)
	{
		printf("%s\n", line.s);
		if (line.s[0] == 'g')
			i_group++;
		else if (line.s[0] == 'v' && line.s[1] == ' ')
		{
			printf("Inside\n");
			push_vertex(
			&obj_data[i_group]->vertices[obj_data[i_group]->n_vertices++],
				&line.s);
			printf("deep\n");
		}
		else if (line.s[0] == 'v' && line.s[1] == 't')
		{
			printf("One\n");
			push_vertex(
			&obj_data[i_group]->text_coords[obj_data[i_group]->n_text_coords++],
				&line.s);
			printf("neo \n");
		}
		else if (line.s[0] == 'v' && line.s[1] == 'n')
		{
			printf("of thsese\n");
			push_vertex(
			&obj_data[i_group]->normals[obj_data[i_group]->n_normals++],
				&line.s);
			printf("nuts\n");
		}
		//else if (line.s[0] == 'f')
		//	push_face(obj_data[i_group], line.s);
	}
}


void		load_obj(t_model *model, FILE *fd)
{
	t_group_lst		*group;

	group = model->root_group;
	count_group_data(fd, group, &model->n_groups);
	model->obj_data = fetch_obj_data_mem(model->root_group, model->n_groups);
	fseek(fd, 0, SEEK_SET);
	
	write_in_data(model->obj_data, model->root_group, fd);

//	get_unordered_data();
//	group = model->root_group;
//	check_groups(group);
}
