/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:40:01 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/15 12:39:31 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOP_H
# define __SCOP_H

#include <stdio.h>
#include <dirent.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include "window.h"
#include "open_gl.h"
#include "camera.h"
#include "window.h"
#include "macros.h"
#include "wavefront_obj.h"
#include "flags.h"
#include "helpers.h"
#include "libft.h"
#include "ft_math.h"
#include "parse_mesh.h"

enum				e_file_types
{
	OBJ,
};

typedef struct		s_scop
{
	WINDOW			window;
	t_model			*model;
	t_gl			*gl;
	t_camera		camera;
}					t_scop;

void				order_data(t_vertex_table *v, t_obj_data **data,
					int n_groups, int flags);
t_vertex_table		*fetch_vertex_table_mem(t_obj_data **data,
					int n_groups, int flags);
t_obj_data			**fetch_obj_data_mem(t_group_lst *group, int n_groups);
void				push_face(t_obj_data *data, char *line, int flags);
void				fill_model_arrays(t_model *model);
t_gl				*init_gl_mem(void);
void				init_array_memory(t_model *m);
t_model				*init_model_mem(void);
void				poll_events(t_scop *display);
void				put_image(t_scop *display);
void				load_obj(t_model *model, FILE *fd);
#endif
