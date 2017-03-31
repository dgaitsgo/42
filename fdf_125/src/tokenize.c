/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:15:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/04/29 20:19:40 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		count_words(char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	words++;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] == c)
			{
				i++;
				if (s[i] == '\0')
					return (--words);
			}
		}
		i++;
	}
	return (words);
}

void	parse_words(char *s, char c, int *letters_per_word)
{
	int word_length;
	int i;
	int windex;

	i = 0;
	windex = 0;
	while (s[i] != '\0')
	{
		word_length = 0;
		while (s[i] != c)
		{
			word_length++;
			i++;
			if (s[i] == '\0')
				break ;
		}
		if (word_length)
		{
			letters_per_word[windex] = word_length;
			windex++;
		}
		i++;
	}
}

char	**allocate(int words, int *letters_per_word)
{
	char	**parse;
	int		i;

	i = 0;
	if (!(parse = (char **)malloc(sizeof(char *) * words)))
		return (NULL);
	while (i < words)
	{
		if (!(parse[i] = malloc(sizeof(char) * (letters_per_word[i]) + 1)))
			return (NULL);
		i++;
	}
	return (parse);
}

void	fill_tokens(char **tokenized, char *s, char c, int i)
{
	int j;
	int strindex;

	strindex = 0;
	while (s[strindex])
	{
		if (s[strindex] != c)
		{
			j = 0;
			while (s[strindex] != c)
			{
				tokenized[i][j] = s[strindex];
				j++;
				strindex++;
				if (s[strindex] == '\0')
				{
					tokenized[i][j] = '\0';
					return ;
				}
			}
			tokenized[i][j] = '\0';
			i++;
		}
		strindex++;
	}
}

int		tokenize(char *s, char c, char ***tokenized)
{
	int words;
	int *letters_per_word;

	words = count_words(s, c);
	if (words > 0)
	{
		letters_per_word = malloc(sizeof(int) * words);
		parse_words(s, c, letters_per_word);
		*tokenized = allocate(words, letters_per_word);
		if (*tokenized != NULL)
		{
			fill_tokens(*tokenized, s, c, 0);
			free(letters_per_word);
			return (words);
		}
	}
	return (0);
}
