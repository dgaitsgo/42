/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:48:39 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:30:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERSECTION_H
# define __INTERSECTION_H
# include "object.h"
# include "vector.h"
# include "ray.h"
# include "shapes.h"

typedef struct
{
	int				id;
	int				hit;
	t_object		*object;
	double			distance;
	t_vector		point;
	t_vector		normal;
	t_ray			ray;
}					t_intersection;

t_intersection		new_intersection();
void				copy_intersection(t_intersection *dst, t_intersection *src);
void				reset_intersection(t_intersection *i);

int					intersect_plane(t_ray world_ray,
t_intersection *intersection);

int					intersect_sphere(t_ray world_ray,
t_intersection *intersection);

int					intersect_cone(t_ray world_ray,
t_intersection *intersection);

int					intersect_cylinder(t_ray world_ray,
t_intersection *intersection);
#endif
