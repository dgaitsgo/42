/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:15:04 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/19 23:14:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_material(char **tokens, int *i, t_material *field, int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == MAX_MATERIAL_ELEMENTS)
	{
		check_material_flags(field);
		return ;
	}
	if (accept(tokens[*i], "color", i) &&
	check_repeat(&field->flags, COLOR_DEFINED))
		parse_vector(tokens, i, &field->color, range(0, 255));
	else if (accept(tokens[*i], "lambert", i) &&
	check_repeat(&field->flags, LAMBERT_DEFINED))
		parse_double_container(tokens, i, &field->lambert, range(0, 1.0));
	else if (accept(tokens[*i], "specular", i) &&
	check_repeat(&field->flags, SPECULAR_DEFINED))
		parse_double_container(tokens, i, &field->specular, range(0, 1.0));
	else if (accept(tokens[*i], "ambient", i) &&
	check_repeat(&field->flags, AMBIENT_DEFINED))
		parse_double_container(tokens, i, &field->ambient, range(0, 1.0));
	else if (accept(tokens[*i], "reflective", i) &&
	check_repeat(&field->flags, REFLECTIVE_DEFINED))
		parse_double_container(tokens, i, &field->reflective, range(0, 1.0));
	else
		parse_error(UNEXPECTED_SYMBOL);
	parse_material(tokens, i, field, max_depth++);
}

void	parse_material_container(char **tokens, int *i, t_material *field)
{
	if (expect(tokens[*i], "{", i))
	{
		parse_material(tokens, i, field, 0);
		if (expect(tokens[*i], "}", i))
			;
	}
}
