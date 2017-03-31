/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:17:58 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:58 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include "vector.h"

typedef struct
{
	int				flags;
	t_vector		point;
	t_vector		normal;
}					t_plane;

typedef struct
{
	int				flags;
}					t_sphere;

typedef struct
{
	int				flags;
}					t_cone;

typedef struct
{
	int				flags;
}					t_cylinder;

void				new_canonical_plane(void *ptr);
void				new_canonical_sphere(void *ptr);
void				new_canonical_cylinder(void *ptr);
void				new_canonical_cone(void *ptr);

#endif
