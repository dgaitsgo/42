/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:13:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 22:15:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OBJECT_H
# define __OBJECT_H

# include "transform.h"
# include "shader.h"
# include "matrix.h"

typedef struct		s_object
{
	int				id;
	int				type;
	int				flags;
	void			*shape;
	t_material		material;
	t_transform		transformation;
	t_matrix		transformation_matrix;
	t_matrix		inverse_transformation_matrix;
	t_matrix		inverse_scale_times_rotation;
}					t_object;

t_object			new_object(int type);
void				build_object_matrices(t_object *object);
#endif
