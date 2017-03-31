/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:15:13 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 07:56:15 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EVENTS_H
# define __EVENTS_H

enum	e_key_events
{
	Q = 12,
	W = 13,
	ZERO = 29,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	RIGHT_BRACKET = 30,
	LEFT_BRACKET = 33,
	SINGLE_QUOTE = 39,
	SEMI_COLON = 41,
	QUESTION = 44,
	GREATER_THAN = 47,
	UP_ARROW = 126,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	LEFT_ARROW = 123,
	NUM_PAD_1 = 83,
	NUM_PAD_2 = 84,
	NUM_PAD_3 = 85,
	NUM_PAD_PLUS = 69,
	NUM_PAD_MINUS = 78,
	MINUS = 27,
	PLUS = 24,
	ESCAPE = 53,
	MAX_KEY = 269,
};

enum		e_mouse_events
{
	CLICK = 1,
	SCROLL_DOWN = 5,
	SCROLL_UP = 4,
};

#endif
