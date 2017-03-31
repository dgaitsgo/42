/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:34:10 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 00:56:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WINDOW_H
# define __WINDOW_H

# include "vector.h"

typedef struct
{
	int				flags;
	double			inverse_aspect_ratio;
	void			*mlx;
	void			*image;
	void			*window;
	char			*pixel_buffer;
	int				line_size;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				endianess;
	int				left_offset;
	int				right_offset;
}					t_window;

void				new_blank_window(t_window *window);
void				put_pixel(t_window *window, int x, int y, t_vector color);
void				put_and_loop(t_window *window, void *ptr);
void				default_window(t_window *window);
void				initialize_window(t_window *window);
#endif
