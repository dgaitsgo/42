#ifndef __TILE_H
# define __TILE_H

typedef struct
{
	short	start_x;
	short	start_y;
	short	end_x;
	short	end_y;
	void	(*function);
	void	*arg;
	pthread_t pthread;
}			t_tile;

#endif
