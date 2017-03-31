/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:05:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/30 19:45:12 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_MESH_H
# define __PARSE_MESH_H

int			get_extension(const char *file_name);
void		meta_obj(t_wavefront_obj *od, const int fd);
void		about_file(t_wavefront_obj *od, int extension, const int fd);
void		reset_counter(t_wavefront_obj *od);
void		load_mesh(t_wavefront_obj *od, const char *file_name);
void		load_obj(t_model *model, const int fd);
//void		fetch_obj_data_mem(t_wavefront_obj *od);
//void		push_obj_vertex(t_wavefront_obj *od, char **line);
//void		push_obj_normal(t_wavefront_obj *od, char **line);
//void		push_obj_face_data(t_wavefront_obj *od, char **line);

#endif
