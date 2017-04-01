/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:13:37 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/01 18:27:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		push_obj_group(t_model *model)
{
	model->curr_group->next = new_group();
	model->curr_group = model->curr_group->next;
}

void		push_obj_text_coord(t_group_lst *g, char **line)
{
	char **tokens;

	tokens = ft_strsplit(*line, ' ');
	g->curr_text_coord->text_coord.x = atof(tokens[1]);
	g->curr_text_coord->text_coord.y = atof(tokens[2]);
	g->curr_text_coord->text_coord.z = atof(tokens[3]);
	g->curr_text_coord->text_coord.w = 1.0f;
	g->curr_text_coord->next = new_text_coord();
	g->curr_text_coord = g->curr_text_coord->next;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

void		push_obj_vertex(t_group_lst *g, char **line)
{
	char **tokens;

	tokens = ft_strsplit(*line, ' ');
	g->curr_vertex->vertex.x = atof(tokens[1]);
	g->curr_vertex->vertex.y = atof(tokens[2]);
	g->curr_vertex->vertex.z = atof(tokens[3]);
	g->curr_vertex->vertex.w = 1.0f;
	g->curr_vertex->next = new_vertex();
	g->curr_vertex = g->curr_vertex->next;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

void		push_obj_normal(t_group_lst *g, char **line)
{
	char **tokens;

	tokens = ft_strsplit(*line, ' ');
	g->curr_normal->normal.x = atof(tokens[1]);
	g->curr_normal->normal.y = atof(tokens[2]);
	g->curr_normal->normal.z = atof(tokens[3]);
	g->curr_normal->normal.w = 1.0f;
	g->curr_normal->next = new_normal();
	g->curr_normal = g->curr_normal->next;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

void		push_face_subfields(t_face_lst *f, char **tokens)
{
	f->f[0] = atoi(strsep(&tokens[1], "/"));
	f->f[1] = atoi(strsep(&tokens[2], "/"));
	f->f[2] = atoi(strsep(&tokens[3], "/"));
	f->f[3] = tokens[4] ? atoi(strsep(&tokens[4], "/")) : 0;
	f->t[0] = atoi(strsep(&tokens[1], "/"));
	f->t[1] = atoi(strsep(&tokens[2], "/"));
	f->t[2] = atoi(strsep(&tokens[3], "/"));
	f->t[3] = tokens[4] ? atoi(strsep(&tokens[4], "/")) : 0;
	f->n[0] = atoi(strsep(&tokens[1], "/"));
	f->n[1] = atoi(strsep(&tokens[2], "/"));
	f->n[2] = atoi(strsep(&tokens[3], "/"));
	f->n[3] = tokens[4] ? atoi(strsep(&tokens[4], "/")) : 0;
}

void		push_obj_face(t_group_lst *g, char **line)
{
	char	**tokens;

	tokens = ft_strsplit(*line, ' ');
	g->curr_face->next = new_face();
	g->curr_face = g->curr_face->next;
	push_face_subfields(g->curr_face, tokens);
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

void		load_obj(t_model *model, const int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'g')
			push_obj_group(model);
		else if (line[0] == 'v' && line[1] == ' ')
			push_obj_vertex(model->curr_group, &line);
		else if (line[0] == 'v' && line[1] == 'n')
			push_obj_normal(model->curr_group, &line);
		else if (line[0] == 'v' && line[1] == 't')
			push_obj_text_coord(model->curr_group, &line);
		else if (line[0] == 'f')
			push_obj_face(model->curr_group, &line);
		free_if(line);
	}
	free_if(line);
}
