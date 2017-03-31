/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:27:25 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:48:11 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENUMS_H
# define __ENUMS_H

enum				e_keys
{
	A = 0,
	W = 13,
	S = 1,
	D = 2,
	C = 8,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
};

enum				e_env
{
	E_WINDOW = 0,
	E_RAYCAST = 1,
	E_TEXTURE = 2,
	E_MAP = 3,
	E_TIME = 4,
};

enum				e_weapons
{
	READY = 0,
	AIM = 1,
	FIRE = 2,
};

enum				e_sprites
{
	BARREL = 0,
};

#endif
