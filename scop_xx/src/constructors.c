/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:37:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 21:56:43 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

struct s_vertex_lst			*new_vertex(void)
{
	struct s_vertex_lst *node;

	node = malloc_if(sizeof(t_vertex_lst), 1);
	if (!node)
		exit(1);
	node->next = NULL;
	return (node);
}

struct s_face_lst			*new_face(void)
{
	struct s_face_lst	*node;

	node = malloc_if(sizeof(t_face_lst), 1);
	if (!node)
		exit(1);
	ft_memset(&node->v, 0, 4);
	ft_memset(&node->t, 0, 4);
	ft_memset(&node->n, 0, 4);
	node->next = NULL;
	return (node);
}

struct s_shader_lst		*new_shader(short type)
{
	struct s_shader_lst	*node;

	node = malloc_if(sizeof(t_shader_lst), 1);
	node->type = type;
	if (!node)
		exit(1);
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

struct s_text_coord_lst		*new_text_coord(void)
{
	struct s_text_coord_lst	*node;

	node = malloc_if(sizeof(t_text_coord_lst), 1);
	if (!node)
		exit(1);
	node->next = NULL;
	return (node);
}

struct s_normal_lst			*new_normal(void)
{
	struct s_normal_lst *node;

	node = malloc_if(sizeof(t_normal_lst), 1);
	if (!node)
		exit(1);
	node->next = NULL;
	return (node);
}

struct s_group_lst			*new_group(void)
{
	struct s_group_lst *node;

	node = malloc_if(sizeof(t_group_lst), 1);
	if (!node)
		exit(1);
	node->root_vertex = new_vertex();
	node->root_text_coord = new_text_coord();
	node->root_normal = new_normal();
	node->root_face = new_face();
	node->curr_vertex = node->root_vertex;
	node->curr_text_coord = node->root_text_coord;
	node->curr_normal = node->root_normal;
	node->curr_face = node->root_face;
	node->n_vertices = 0;
	node->n_normals = 0;
	node->n_text_coords = 0;
	node->n_faces = 0;
	node->next = NULL;
	return (node);
}
