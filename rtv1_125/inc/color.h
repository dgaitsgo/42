/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:17:44 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 22:22:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COLOR_H
# define __COLOR_H

# include "vector.h"

void				process_color(t_vector *color);
t_vector			new_color(double r, double g, double b);
void				clamp_color(t_vector *color);
void				normal_to_rgb(t_vector *color);
void				rgb_to_normal(t_vector *color);
int					out_of_gamut(t_vector *color);

#endif
