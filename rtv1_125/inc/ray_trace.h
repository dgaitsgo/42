/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:46:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/10 19:28:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAY_TRACE_H
# define __RAY_TRACE_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>
# include <stdio.h>
# include "vector.h"
# include "matrix.h"
# include "shapes.h"
# include "transform.h"
# include "object.h"
# include "shader.h"
# include "color.h"
# include "maths.h"
# include "random.h"
# include "window.h"
# include "camera.h"
# include "intersection.h"
# include "ray.h"
# include "geometry.h"
# include "macros.h"
# include "enums.h"

typedef struct
{
	int			flags;
	int			n_objects;
	int			n_lights;
	int			(*intersect_fn_pointers[4])(t_ray t, t_intersection *i);
	t_object	object[8];
	t_camera	camera;
	t_vector	light[2];
	t_window	window;
}				t_scene;

void			free_if(void *ptr);
int				key_to_event(int keycode, t_scene *scene);
void			destroy_scene(t_scene *scene);

t_vector		*shader(t_intersection intersection, t_scene *scene,
t_vector *color, int depth);

void			phong_shading(t_vector *color,
t_intersection intersection, t_vector *light);

void			initialize_scene(t_scene *scene);

int				parse(char *file_name, t_scene *scene);

int				render(t_window *window, t_camera *camera,
t_scene *scene, t_vector *color);

t_vector		*trace_container(t_ray ray,
t_scene *scene, t_vector *color, int depth);

t_intersection	intersect_scene(t_ray ray, t_scene *scene);

void			calculate_world_intersection(t_object *object,
t_ray world_ray, t_intersection *intersection);

int				test_intersection(t_scene *scene,
t_object *object, t_ray ray, t_intersection *intersection);
t_intersection	intersect_scene(t_ray ray, t_scene *scene);

#endif
