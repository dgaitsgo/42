/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:48:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:49:19 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H
# define __WEAPON_H

typedef struct
{
	int		tex_x;
	int		tex_y;
	int		d;
	int		gun_height;
	int		gun_width;
	int		screen_x;
	int		bpp;
	int		line_size;
	char	*pixels;
	int		draw_x_start;
	int		draw_y_start;
	int		draw_x_end;
	int		draw_y_end;
}			t_weapon_data;

#endif
