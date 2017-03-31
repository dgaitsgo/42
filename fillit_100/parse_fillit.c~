/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:02:19 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/03/25 15:53:58 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	first_char(char **s, int y, int x)
{
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[y][x] >= 'A' && s[y][x] <= 'Z')
				return (s[y][x]);
			x++;
		}
		y++;
	}
	return (s[y][x]);
}

void	initialize_fillit(t_fillit *s)
{
	s->i = 0;
	s->x = 0;
	s->tets = (char ***)malloc(sizeof(char **) * 27);
	s->tets[26] = NULL;
	while (s->i < 26)
	{
		s->y = 0;
		s->tets[s->i] = (char **)malloc(sizeof(char *) * 4);
		while (s->y < 4)
		{
			s->tets[s->i][s->y] = (char *)malloc(sizeof(char) * 4);
			s->y++;
		}
		s->i++;
	}
	reset_indexes(s);
	s->i = -1;
}

void	reset_indexes(t_fillit *s)
{
	s->i = 0;
	s->y = 0;
	s->x = 0;
}

int		write_tets(t_fillit *s, int fd, int ret, char eol)
{
	int alt;

	while (++s->i < 26)
	{
		s->y = -1;
		while (++s->y < 4)
		{
			s->x = -1;
			while (++s->x < 4)
			{
				ret = read(fd, &s->tets[s->i][s->y][s->x], 1);
				if (s->tets[s->i][s->y][s->x] == '\0')
					return (alt == 1 ? 0 : check_last(s->i[s->tets], 0, 0));
			}
			ret = read(fd, &eol, 1);
			if (eol != '\n')
				return (0);
		}
		alt = read(fd, &eol, 1);
		if (eol != '\n')
			return (0);
	}
	return (check_last(s->i[s->tets], 0, 0));
}

int		main(int argc, char **argv)
{
	int			fd;
	int			solved;
	t_fillit	s;

	solved = 0;
	fd = 0;
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit [target_file]\n", 2);
		return (0);
	}
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 2)
	{
		initialize_fillit(&s);
		if ((write_tets(&s, fd, 0, 'a') == 1) && (s.i > 0))
			if ((solved = verify(&s) == 1))
				solve_and_display(&s);
	}
	if (solved == 0)
		ft_putstr("error\n");
	return (0);
}
