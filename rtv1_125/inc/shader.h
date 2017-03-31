/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:16:09 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 22:46:39 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHADER_H
# define __SHADER_H

# include "vector.h"

typedef struct	s_material
{
	t_vector	color;
	double		lambert;
	double		specular;
	double		ambient;
	double		reflective;
	double		refraction;
	int			flags;
}				t_material;

#endif
