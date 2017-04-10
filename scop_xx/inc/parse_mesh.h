/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:05:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/10 17:08:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_MESH_H
# define __PARSE_MESH_H

enum			e_VERTEX_TYPES
{
	VERT_V,
	TEXT_V,
	NORM_V,
};

typedef struct	s_getline
{
	char		*s;
	size_t		n;
}				t_getline;

void		init_getline(t_getline *line);
int			get_extension(const char *file_name);

#endif
