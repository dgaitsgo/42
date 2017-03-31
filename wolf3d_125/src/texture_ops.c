/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:45:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:36:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		lookup_texture(int **world_map,
t_texture *texture, t_raycast *wolf)
{
	texture->wall_width = 64;
	texture->wall_height = 64;
	texture->tex_num = world_map[wolf->map_x][wolf->map_y];
	if (wolf->intersection == VERTICAL)
	{
		texture->wall_x =
		wolf->ray_pos_y + wolf->perp_wall_distance * wolf->ray_dir_y;
	}
	else
	{
		texture->wall_x =
		wolf->ray_pos_x + wolf->perp_wall_distance * wolf->ray_dir_x;
	}
	texture->wall_x -= floor(texture->wall_x);
	texture->tex_x = intify(texture->wall_x * (double)texture->wall_width);
	if (wolf->intersection == VERTICAL && wolf->ray_dir_x > 0)
	{
		texture->tex_x = texture->wall_width - texture->tex_x - 1;
	}
	if (wolf->intersection == HORIZONTAL && wolf->ray_dir_y < 0)
	{
		texture->tex_x = texture->wall_width - texture->tex_x - 1;
	}
}

void		get_sky_color(t_color *color, t_texture *texture, int row, int col)
{
	int		bpp;
	int		line_size;
	char	*pixels;

	pixels = texture->skybox->pixels;
	bpp = texture->skybox->format->BitsPerPixel;
	line_size = texture->skybox->pitch;
	color->r = pixels[(col * bpp >> 3) + row * line_size];
	color->g = pixels[(col * bpp >> 3) + row * line_size + 1];
	color->b = pixels[(col * bpp >> 3) + row * line_size + 2];
}

void		write_in_texture(t_sdlwindow *window,
			t_raycast *wolf, t_texture *texture)
{
	t_color	color;
	int		y;
	int		d;
	int		tex_y;

	y = wolf->draw_start;
	while (y < wolf->draw_end)
	{
		d = y * 256 - SDL_HEIGHT * 128 + wolf->line_height * 128;
		tex_y = ((d * texture->wall_height) / wolf->line_height / 256);
		if (texture->tex_num == 7)
			texture->tex_num--;
		assess_color(&color, wolf, texture, tex_y);
		draw_pixel(window, color, wolf->iterator, y);
		y++;
	}
}

void		assess_color(t_color *color, t_raycast *wolf,
			t_texture *texture, int tex_y)
{
	int		bpp;
	int		tex_x;
	int		line_size;
	char	*pixels;

	if (texture->tex_num > 6)
		texture->tex_num = 6;
	if (texture->tex_num < 0)
		texture->tex_num = 0;
	pixels = texture->wall_txtr[texture->tex_num]->pixels;
	tex_x = texture->tex_x;
	bpp = texture->wall_txtr[texture->tex_num]->format->BitsPerPixel;
	line_size = texture->wall_txtr[texture->tex_num]->pitch;
	color->r = pixels[(tex_x * bpp >> 3) + tex_y * line_size];
	color->g = pixels[(tex_x * bpp >> 3) + tex_y * line_size + 1];
	color->b = pixels[(tex_x * bpp >> 3) + tex_y * line_size + 2];
	if (wolf->intersection == HORIZONTAL)
	{
		color->r = (color->r >> 1) & 8355711;
		color->g = (color->g >> 1) & 8355711;
		color->b = (color->b >> 1) & 8355711;
	}
}
