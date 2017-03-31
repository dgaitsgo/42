/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_and_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:18:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 00:49:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			capitalized_word(char *s, int *i, int j)
{
	(*i)++;
	while (lower_case_letter(s[*i]))
	{
		(*i)++;
		j++;
	}
	return (j);
}

int			numerical_word(char *s, int *i, int j)
{
	(*i)++;
	while (is_digit(s[*i]))
	{
		(*i)++;
		j++;
	}
	return (j);
}

int			count_words_and_length(char *s, int length_table[1000])
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (capital_letter(s[i]))
			length_table[n++] = capitalized_word(s, &i, 1);
		if (lower_case_letter(s[i]))
			length_table[n++] = capitalized_word(s, &i, 1);
		if (is_digit(s[i]))
			length_table[n++] = numerical_word(s, &i, 1);
		if ((s[i] == ',') || balancing_symbol(s[i]))
		{
			length_table[n++] = 1;
			i++;
		}
	}
	return (n);
}
