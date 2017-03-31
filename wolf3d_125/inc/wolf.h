/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:57:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 15:59:14 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H

# include <SDL2/SDL.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "macros.h"
# include "joystick.h"
# include "enums.h"
# include "weapon.h"
# include <time.h>

typedef struct		s_time
{
	double			time;
	double			old_time;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	double			now;
	double			start;
	int				set;
}					t_time;

typedef	struct		s_sdlwindow
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Surface		*image;
	SDL_Event		event;
	SDL_Joystick	*joystick;
	char			*frame_buffer;
	int				width;
	int				height;
	int				depth;
	int				bytes_per_line;
}					t_sdlwindow;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				t;
}					t_color;

typedef struct		s_raycast
{
	int				iterator;
	int				intersection;
	int				map_x;
	int				map_y;
	double			camera_x;
	double			rot_amt;
	double			dir_x;
	double			dir_y;
	double			pos_y;
	double			pos_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_y;
	double			ray_dir_x;
	double			plane_x;
	double			plane_y;
	double			hyp_x_displacement;
	double			hyp_y_displacement;
	double			horizontal_poi;
	double			vertical_poi;
	double			x_step;
	double			y_step;
	double			perp_wall_distance;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_raycast;

typedef	struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
}					t_sprite;

typedef struct		s_sprite_calc_cont
{
	double			sprite_x;
	double			sprite_y;
	double			inv_dot;
	double			trans_x;
	double			trans_y;
	double			sprite_screen_x;
	double			sprite_height;
	double			draw_y_start;
	double			draw_y_end;
	double			sprite_width;
	double			draw_x_start;
	double			draw_x_end;
	int				stripe;
	int				y;
	int				d;
	int				i;
	int				tex_x;
	int				tex_y;
}					t_sprite_calc_cont;

typedef	struct		s_weapon
{
	SDL_Surface		**weapon;
	int				status;
}					t_weapon;

typedef	struct		s_texture
{
	SDL_Surface		**wall_txtr;
	SDL_Surface		*skybox;
	t_sprite		*sprite;
	SDL_Surface		**sprite_txtr;
	t_weapon		*weapons;
	double			*sprite_distance;
	int				*sprite_order;
	int				*z_buffer;
	int				tex_num;
	int				wall_width;
	int				wall_height;
	double			wall_x;
	double			tex_x;
}					t_texture;

void				weapon_bmps_to_surfaces(t_texture *texture);
void				exit_routine(t_sdlwindow *window);
void				initialize_program(void **env);
void				init_raycast(t_raycast *wolf);
void				init_map(int **map, t_texture *texture);
void				init_window(t_sdlwindow *window);
void				render(void **env);
int					intify(double number);
double				arc_to_radians(double degrees);
void				double_swap(double *a, double *b);
void				int_swap(int *a, int *b);
void				comb_sort(int *order, double *distance, int i, int j);
int					ft_strcmp(const char *s1, const char *s2);
void				strafe_left(int **world_map, t_raycast *wolf);
void				strafe_right(int **world_map, t_raycast *wolf);
void				move_down(int **world_map, t_raycast *wolf);
void				move_up(int **world_map, t_raycast *wolf);
void				look_left(t_raycast *wolf);
void				look_right(t_raycast *wolf);
void				draw_pixel(t_sdlwindow *window,
					t_color color, int x, int y);
void				set_color(t_color *color, int r, int g, int b);
void				draw_weapon(t_sdlwindow *window, t_texture *texture);
void				assess_color(t_color *color, t_raycast *wolf,
					t_texture *texture, int tex_y);
void				lookup_texture(int **world_map,
					t_texture *texture, t_raycast *wolf);
void				get_sky_color(t_color *color,
					t_texture *texture, int row, int col);
void				write_in_texture(t_sdlwindow *window,
					t_raycast *wolf, t_texture *texture);
t_color				get_ground_color(void);
void				calc_ray_vectors(t_raycast *wolf, int width);
void				cast_rays(void **env, int **world_map,
					t_raycast *wolf, t_sdlwindow *window);
void				find_intersections(t_raycast *wolf);
void				digital_differential_analysis(t_raycast
					*wolf, int **world_map);
void				calc_wall_distance(t_raycast *wolf, t_texture *texture);
void				calc_pixels_to_draw(t_raycast *wolf, t_sdlwindow *window);
void				init_sprites(t_texture *texture, t_sdlwindow *window);
void				draw_sprites(t_sdlwindow *window,
					t_texture *texture, t_raycast *wolf);
void				place_sprite(t_sprite *sprite,
					double x, double y, int texture);
void				calc_sprite_width(t_sprite_calc_cont *sc,
					t_sdlwindow *window);
void				calc_sprite_height(t_sprite_calc_cont *sc,
					t_sdlwindow *window);
void				calc_sprite(t_sprite_calc_cont *sc,
					t_sdlwindow *window, t_texture *texture, t_raycast *wolf);
void				joystick(t_sdlwindow *window, t_raycast *wolf,
					int **world_map, t_texture *texture);
void				keyboard_event_loop(void **env);
void				joystick_event_loop(void **env);
int					random_int(double max);
double				random_double(double max);
int					**malloc_world_map(void);
void				put_image(t_sdlwindow *window);

#endif
