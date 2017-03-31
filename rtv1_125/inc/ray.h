/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:50:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 22:44:40 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAY_H
# define __RAY_H
# include "object.h"
# include "vector.h"

typedef struct		s_ray
{
	double			len;
	t_vector		origin;
	t_vector		direction;
}					t_ray;

t_ray				ray_world_to_object(t_ray world_ray, t_object *object);
t_vector			solve_parametric(t_ray ray, double t);
#endif
