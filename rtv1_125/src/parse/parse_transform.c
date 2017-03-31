/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:34:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/19 23:23:22 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_transform(char **tokens, int *i, t_transform *field,
int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == MAX_TRANSFORM_ELEMENTS)
	{
		check_transformation_flags(field);
		return ;
	}
	if (accept(tokens[*i], "scale", i) &&
	(check_repeat(&field->flags, SCALE_DEFINED)))
		parse_vector(tokens, i, &field->scale, range(1, FLT_MAX));
	else if (accept(tokens[*i], "rotation", i) &&
	(check_repeat(&field->flags, ROTATION_DEFINED)))
		parse_vector(tokens, i, &field->rotation, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "translation", i) &&
	(check_repeat(&field->flags, TRANSLATION_DEFINED)))
		parse_vector(tokens, i, &field->translation, range(-FLT_MAX, FLT_MAX));
	else
		parse_error(UNEXPECTED_SYMBOL);
	parse_transform(tokens, i, field, max_depth++);
}

void	parse_transform_container(char **tokens, int *i, t_transform *field)
{
	if (expect(tokens[*i], "{", i))
	{
		parse_transform(tokens, i, field, 0);
		if (expect(tokens[*i], "}", i))
			;
	}
}
