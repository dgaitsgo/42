/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   softEngine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:46:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/19 23:01:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "mlx.h"
# include "libft.h"
# include "ft_graph.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <malloc/malloc.h>

# define MODULES 10

typedef float **t_matrix;

enum	e_file_types
{
	FDF,
	OBJ,
	NO_FORMAT,
};

int					invalid_line(char *s);
void				draw_triangle(t_window *window, t_vertex v1,
t_vertex v2, t_vertex v3);
t_vector			lerp(t_vector min, t_vector max, float lerp_per);
void				get_color(t_vertex *a, t_vertex *b,
t_vertex *c, t_trans *transf);
void				select_modify(int key, void **env);
t_vector			init_colors();
t_vector			new_color_vector(float r, float g, float b, float t);
t_color				*fill_color(t_color *color, char *which);
t_mesh				*load_mesh(char *file_name);
t_mesh				*load_fdf(int x_max, int z_max, int fd, int lines);
t_mesh				*init_fdf_mesh(t_mesh *model, int points);
void				clear_depth_buffer(size_t length);
void				fill_mesh(t_window *window, t_mesh *model,
t_matrix trans, t_trans *transf);
int					*meta_fdf(int *meta_data, int fd);
t_mesh				*load_obj(int points, int indexes, const int fd);
void				insert_obj_vertex(t_mesh *obj, char **line);
void				insert_obj_index(t_mesh *obj, char **line);
int					*meta_obj(int *meta_data, int fd);
int					find_x_max(char *line);
t_matrix			build_transform(t_window *window, t_trans *trans);
t_matrix			init_screen_space(t_window *window);
t_matrix			init_scale(float x, float y, float z);
t_matrix			init_translation(float x, float y, float z);
void				free_matrix(t_matrix m);
t_matrix			new_matrix();
t_matrix			matrix_multip(t_matrix m1, t_matrix m2);
void				rotate_x(t_matrix rx, float x);
void				rotate_y(t_matrix ry, float y);
void				rotate_z(t_matrix rz, float z);
t_matrix			init_rotation(float x, float y, float z);
t_gradient			new_gradient(t_vertex *min, t_vertex *mid, t_vertex *max);
t_edge				find_edge(t_gradient g, t_vertex *min_y_vert,
t_vertex *max_y_vert, int mindex);
void				scan_edge(t_gradient grad, t_window *window,
t_edge *a, t_edge *b);
void				step(t_edge *e);
int					key_to_event(int keycode, void **env);
void				order_vertices_by_y(t_vertex *min,
t_vertex *mid, t_vertex *max);
void				put_and_loop(t_window *window, void **env);
void				init_window(t_window *window,
int width, int height, char *title);
void				clear_window(t_window *window);
void				draw_pixel(t_window *window, int x, int y, t_vector *color);
void				draw_scan_line(t_gradient grad, t_window *window,
t_edge *l, t_edge *r);
void				fill_triangle(t_window *window, t_vertex v1,
t_vertex v2, t_vertex v3);
t_vertex			transform(t_matrix m, t_vertex r);
t_vector			c_mult(t_vector r1, float c);
t_vector			v_sub(t_vector r1, t_vector r2);
t_vector			v_add(t_vector r1, t_vector r2);
t_vector			c_add(t_vector r1, float c);
t_vector			init_colors(void);
t_vertex			perspective_divide(t_vertex v);
int					tokenize(char *s, char c, char ***tokenized);

#endif
