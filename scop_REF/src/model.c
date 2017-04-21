#include "scop.h"

void	init_model(t_model *model)
{
	model->flags = 0;
	model->root_group = new_group();
	model->n_groups = 1;
}
