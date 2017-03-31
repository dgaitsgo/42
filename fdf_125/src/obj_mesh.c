/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:12:25 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/04 01:41:44 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			*meta_obj(int *meta_data, int fd)
{
	int		verts;
	int		faces;
	char	*line;

	verts = 0;
	faces = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			verts++;
		if (line[0] == 'f' && line[1] == ' ')
			faces++;
	}
	meta_data[0] = verts;
	meta_data[1] = faces * 3;
	return (meta_data);
}

t_mesh		*init_obj_mesh(t_mesh *model, int points, int indexes)
{
	int j;

	j = 0;
	model = (t_mesh *)malloc(sizeof(t_mesh));
	model->vertex = (t_vertex **)malloc(sizeof(t_vertex *) * (points));
	while (j < points)
	{
		model->vertex[j] = (t_vertex *)malloc(sizeof(t_vertex));
		j++;
	}
	model->index_arr = malloc(sizeof(int) * (indexes));
	ft_memset(model->index_arr, 0, (indexes));
	model->vindexes = 0;
	model->findexes = -3;
	return (model);
}

void		insert_obj_t_vertex(t_mesh *obj, char **line)
{
	char **tokens;

	tokens = ft_strsplit(*line, ' ');
	obj->vertex[obj->vindexes]->pos.x = atof(tokens[1]);
	obj->vertex[obj->vindexes]->pos.y = atof(tokens[2]);
	obj->vertex[obj->vindexes]->pos.z = atof(tokens[3]);
	obj->vertex[obj->vindexes]->pos.w = 1.0f;
	obj->vertex[obj->vindexes]->col = new_color_vector(0, 0, 0, 0);
	obj->vindexes++;
	free(tokens);
}

void		insert_obj_index(t_mesh *obj, char **line)
{
	char **tokens;

	obj->findexes += 3;
	tokens = ft_strsplit(*line, ' ');
	obj->index_arr[obj->findexes] = atoi(tokens[1]) - 1;
	obj->index_arr[obj->findexes + 1] = atoi(tokens[2]) - 1;
	obj->index_arr[obj->findexes + 2] = atoi(tokens[3]) - 1;
	free(tokens);
}

t_mesh		*load_obj(int points, int indexes, const int fd)
{
	t_mesh	*obj;
	char	*line;

	obj = NULL;
	obj = init_obj_mesh(obj, points, indexes);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v')
		{
			insert_obj_t_vertex(obj, &line);
		}
		if (line[0] == 'f')
		{
			insert_obj_index(obj, &line);
		}
	}
	obj->findexes += 3;
	return (obj);
}
