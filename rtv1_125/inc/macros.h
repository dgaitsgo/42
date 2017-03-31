/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:27:26 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:18:23 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MACROS_H
# define __MACROS_H

# define MAX_OBJECTS 		8
# define PI					3.14159265359
# define FOV				45.0
# define FOV_RADIANS		PI * (FOV / 180.0)
# define HEIGHT				400
# define WIDTH				600
# define ASPECT_RATIO		WIDTH / HEIGHT
# define INVERSE_AR			HEIGHT / WIDTH
# define BCKGD				new_vector(0, 0, 0)
# define UP_VECTOR			new_vector(0, 1, 0)
# define MISS				0
# define HIT				1
# define FROM_INSIDE		-1
# define MAX_DEPTH			10
# define MAX_BOUND			FLT_MAX
# define MIN_PRECISION		0.00000001
# define CYLINDER_TOLERANCE 0.000230
# define AIR_DENSITY		1.0

double		AR_INDEX;

#endif
