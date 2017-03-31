/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:28:19 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/04 01:45:45 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	modify_rotation(int keycode, t_trans *transf)
{
	if (keycode == 124)
		transf->y_rot += .1f;
	if (keycode == 126)
		transf->x_rot += .1f;
	if (keycode == 123)
		transf->z_rot += .1f;
}

void	modify_translation(int keycode, t_trans *transf)
{
	if (keycode == 17)
		transf->x_trad += .2f;
	if (keycode == 16)
		transf->y_trad += .1f;
	if (keycode == 5)
		transf->x_trad -= .2f;
	if (keycode == 4)
		transf->y_trad -= .1f;
	if (keycode == 32)
		transf->z_trad += .1f;
	if (keycode == 38)
		transf->z_trad -= .1f;
}

void	modify_color(int key, t_trans *transf)
{
	if (key == 18)
		transf->a_r_col += 0.01f;
	if (key == 19)
		transf->a_g_col += 0.01f;
	if (key == 20)
		transf->a_b_col += 0.01f;
	if (key == 21)
		transf->b_r_col += 0.01f;
	if (key == 23)
		transf->b_g_col += 0.01f;
	if (key == 22)
		transf->b_b_col += 0.01f;
	if (key == 26)
		transf->c_r_col += 0.01f;
	if (key == 28)
		transf->c_g_col += 0.01f;
	if (key == 25)
		transf->c_b_col += 0.01f;
}

void	modify_scale(int keycode, t_trans *transf)
{
	if (keycode == 12)
		transf->x_scale += .1f;
	if (keycode == 13)
		transf->y_scale -= .1f;
	if (keycode == 14)
		transf->z_scale += .1f;
	if (keycode == 0 && transf->x_scale > 0.1f)
		transf->x_scale -= .1f;
	if (keycode == 1)
		transf->y_scale += .1f;
	if (keycode == 2 && transf->z_scale > 0.1f)
		transf->z_scale -= .1f;
}

void	select_modify(int key, void **env)
{
	t_trans		*transf;

	transf = (t_trans *)env[1];
	if (key == 124 || key == 126 || key == 123)
		modify_rotation(key, transf);
	if (key == 12 || key == 13 || key == 14 || key == 0 || key == 1 || key == 2)
		modify_scale(key, transf);
	if (key == 17 || key == 16 || key == 5 || key == 4
	|| key == 32 || key == 38)
		modify_translation(key, transf);
	if (key == 18 || key == 19 || key == 20 || key == 21 ||
		key == 23 || key == 22 || key == 26 || key == 28 || key == 25)
		modify_color(key, transf);
}
