/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:59:06 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/03/22 21:57:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_fillit
{
	int			i;
	int			x;
	int			y;
	int			placed;
	int			tetris;
	char		***tets;
	int			***diff;
}				t_fillit;

typedef struct	s_cg
{
	int			x;
	int			y;
	int			x_max;
	int			y_max;
	int			x_stock;
	int			y_stock;
	char		**grid;
}				t_cg;

void			reset_indexes(t_fillit *s);
void			print_grid(t_cg *g);
void			print_tables(int **d, int max);
void			initialize_fillit(t_fillit *s);
int				write_tets(t_fillit *s, int fd, int ret, char eol);
int				verify(t_fillit *s);
int				solve_and_display(t_fillit *s);
void			initialize_grid(t_cg *g);
int				place(t_fillit *s, t_cg *g, int x, int y);
void			expand_map(t_cg *g);
int				**get_mem(int **pos);
int				***get_triple_mem(int ***diff, int tetris);
void			reset_vals(t_cg *g);
void			initialize_grid(t_cg *g);
void			expand_map(t_cg *g);
char			first_char(char **s, int y, int x);
int				check_last(char **s, int y, int x);
#endif
