/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:47 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/15 10:48:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATRIX_H
# define __MATRIX_H

# define M_TRANSLATION	3
# define X				0
# define Y				1
# define Z				2

typedef 	float t_matrix[4][4];

void		init_screen_space(t_matrix m, float width, float height);
void		new_perspective_matrix(t_matrix m, float fov, float aspect_ratio);
void		print_matrix(t_matrix m);
void		copy_matrix(t_matrix dst, t_matrix src);
void		matrix_multiply(t_matrix res, t_matrix m1, t_matrix m2);
void		rotate_y(t_matrix ry, float y);
void		identity_matrix(t_matrix m);
void		perspective_matrix(t_matrix m);

#endif
