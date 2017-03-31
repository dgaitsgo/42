/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stream_controls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:19:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 21:46:39 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	accept(char *candidate, char *expected, int *i)
{
	if (candidate && expected)
	{
		if (ft_strcmp(candidate, expected) == 0)
		{
			(*i)++;
			return (1);
		}
	}
	return (0);
}

int	check(char *candidate, char *possibility)
{
	if (candidate && possibility)
	{
		if (ft_strcmp(candidate, possibility) == 0)
			return (1);
		else
			return (0);
	}
	parse_error(UNEXPECTED_SYMBOL);
	return (0);
}

int	expect(char *candidate, char *expected, int *i)
{
	if (accept(candidate, expected, i))
		return (1);
	else
		parse_error(UNEXPECTED_SYMBOL);
	return (0);
}

int	next(char **tokens, char *candidate, int *i)
{
	(*i)++;
	if (tokens[*i])
		if (expect(tokens[*i], candidate, i))
			return (1);
	return (0);
}
