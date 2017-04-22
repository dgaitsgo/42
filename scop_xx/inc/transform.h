/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:48:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 12:46:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TRANSFORM_H
# define __TRANSFORM_H

#include "matrix.h"

typedef struct	s_transform
{
	float		translation[3];
	t_matrix	rotation;
	float		scale;
}				t_transform;

void			init_transform(t_transform *t);

#endif
