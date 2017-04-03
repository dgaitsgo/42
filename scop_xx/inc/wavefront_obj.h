/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront_obj.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:25:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/03 20:25:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WAVEFRONT_OBJ_H
# define __WAVEFRONT_OBJ_H

#include "vector.h"
#include "open_gl.h"

typedef struct	s_array_group t_array_group;

enum			e_flags
{
	NEGATIVE_INDEXES,
	W_FACE_DEFINED,
	W_TEXTURE_DEFINED,
	UNDEFINED_MATERIAL,
	UNDEFINED_TEXT_COORDS,
	UNDEFINED_NORMALS,
	MTL_ASSOCIATED,
};

enum						e_model_indices
{
	vertex,
	NORMAL,
	TEXTURE,
};

typedef struct 				s_texture
{
	GLuint					id;
	int						type;
}							t_texture;

typedef struct				s_face_lst
{
	int						v[4];
	int						t[4];
	int						n[4];
	struct	s_face_lst		*next;
}							t_face_lst;

typedef struct				s_vertex_lst
{
	t_vector				vertex;
	struct s_vertex_lst		*next;
}							t_vertex_lst;

typedef	struct				s_text_coord_lst
{
	t_vector				text_coord;
	struct s_text_coord_lst	*next;
}							t_text_coord_lst;

typedef struct				s_normal_lst
{
	t_vector				normal;
	struct s_normal_lst		*next;
}							t_normal_lst;

typedef	struct				s_group_lst
{
	t_vertex_lst			*root_vertex;
	t_vertex_lst			*curr_vertex;
	t_text_coord_lst		*root_text_coord;
	t_text_coord_lst		*curr_text_coord;
	t_normal_lst			*root_normal;
	t_normal_lst			*curr_normal;
	t_face_lst				*root_face;
	t_face_lst				*curr_face;
	long					byte_marker;
	int						n_vertices;
	int						n_text_coords;
	int						n_normals;
	int						n_faces;
	struct s_group_lst		*next;
}							t_group_lst;

typedef struct				s_obj_data
{
	t_vector				*vertices;
	t_vector				*text_coords;
	t_vector				*normals;

	int						*vert_indices;
	int						*text_indices;
	int						*norm_indices;

	int						n_vertices;
	int						n_text_coords;
	int						n_normals;

	int						n_vert_indices;
	int						n_text_indices;
	int						n_norm_indices;
}							t_obj_data;

typedef struct				s_model
{
	// missing reference to mtl file
	int						flags;
	int						n_groups;
	t_group_lst				*root_group;
	t_obj_data				**obj_data;
	GLuint					vao;
}							t_model;

typedef struct				s_wavefront_obj
{
	int						flags;
	int						index_sign;

	t_vector				*vertices;
	t_vector				*normals;
	t_vector				*text_coords;

	int						*face_indexes;
	int						*normal_indexes;
	int						*texture_indexes;

	int						n_normal_indexes;
	int						n_text_indexes;

	int						n_text_coords;
	int						n_vertices;
	int						n_normals;
	int						n_faces;
}							t_wavefront_obj;

struct s_vertex_lst			*new_vertex(void);
struct s_face_lst			*new_face(void);
struct s_text_coord_lst		*new_text_coord(void);
struct s_normal_lst			*new_normal(void);
struct s_group_lst			*new_group(void);

#endif
