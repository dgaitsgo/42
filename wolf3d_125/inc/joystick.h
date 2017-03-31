/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joystick.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:58:25 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:48:52 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __JOYSTICK_H
# define __JOYSTICK_H

typedef struct
{
	int x_move;
	int	y_move;
	int	y_look;
	int	aim;
	int	fire;
}		t_joystick;

#endif
