/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:57:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 17:03:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"
#include "flags.h"

void	parse_window(char **tokens, int *i, t_window *window, int max_depth)
{
	if (tokens[*i] == NULL)
		parse_error(UNEXPECTED_SYMBOL);
	if (check(tokens[*i], "}") || max_depth == MAX_WINDOW_ELEMENTS)
	{
		check_window_flags(window);
		return ;
	}
	if (accept(tokens[*i], "width", i) &&
	check_repeat(&window->flags, WIDTH_DEFINED))
		parse_int_container(tokens, i, &window->width, range(1, 1800));
	else if (accept(tokens[*i], "height", i) &&
	check_repeat(&window->flags, HEIGHT_DEFINED))
		parse_int_container(tokens, i, &window->height, range(1, 2550));
	else
		parse_error(UNEXPECTED_SYMBOL);
	parse_window(tokens, i, window, max_depth++);
}
