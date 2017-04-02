/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:40:01 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 05:04:51 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCOP_H
# define __SCOP_H

#include <stdio.h>
#include <dirent.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "window.h"
#include "open_gl.h"
#include "window.h"
#include "macros.h"
#include "wavefront_obj.h"
#include "flags.h"
#include "helpers.h"
#include "libft.h"
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
}					t_scop;


t_gl				*init_gl_mem(void);
void				init_array_memory(t_model *m);
t_model				*init_model_mem(void);
void				poll_events(t_scop *display);
void				put_image(t_scop *display);

#endif
