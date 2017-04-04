/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:37:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/04 19:23:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_getline(t_getline *line)
{
	line->s = NULL;
	line->n = 0;
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

struct s_group_lst			*new_group(void)
{
	struct s_group_lst *node;

	node = malloc_if(sizeof(t_group_lst), 1);
	if (!node)
		exit(1);
	node->quads = 0;
	node->n_vertices = 0;
	node->n_normals = 0;
	node->n_text_coords = 0;
	node->n_faces = 0;
	node->next = NULL;
	return (node);
}
