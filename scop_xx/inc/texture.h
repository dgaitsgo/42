/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:36:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 13:56:39 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEXTURE_H
# define __TEXTURE_H

#define			TEXTURE_FOLDER				"./textures"
#define			MAX_TEXTURES				8

enum			e_texture_types
{
	TGA,
};

typedef struct		s_tga
{
	int				file_type;
	unsigned char	image_type;
	unsigned char	bit_depth;
	short int		width;
	short int		height;
	long			image_size;
	int				color_mode;
}					t_tga;

#endif
