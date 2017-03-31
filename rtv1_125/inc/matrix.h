/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:23:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 21:12:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATRIX_H
# define __MATRIX_H

typedef double		t_matrix[4][4];

void		print_matrix(t_matrix m);
void		copy_matrix(t_matrix dst, t_matrix src);
void		matrix_multiply(t_matrix res, t_matrix m1, t_matrix m2);
#endif
