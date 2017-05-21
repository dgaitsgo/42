/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 02:22:17 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 15:27:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	extract_indices(t_vector *holder, int *indices, int i, int sign)
{
	holder->x = indices[i] - sign;
	holder->y = indices[i + 1] - sign;
	holder->z = indices[i + 2] - sign;
	holder->w = indices[i + 3] - sign;

	//printf("%d, %d, %d, %d\n", (int)holder->x, (int)holder->y, (int)holder->z, (int)holder->w);
}

void	order_position(t_vertex_table *v, t_obj_data *data, int sign)
{
	t_vector	temp_i;
	float		*pos;
	int			offset;
	int			i_index;

	i_index = -4;
	pos = v->positions;
	offset = sign ? 0 : data->n_vertices;
	v->i_pos = -9;
	printf("\n n vertices = %d, n vert indices = %d, offset == %d, sign == %d\n",
	data->n_vertices, data->n_faces, offset, sign);

	while (i_index < data->n_faces)
	{
		v->i_pos += 9;
		i_index += 4;
		extract_indices(&temp_i, data->vert_indices, i_index, sign);
		//printf("%f, %f, %f, %f\n", temp_i.x, temp_i.y, temp_i.z, temp_i.w);

		pos[v->i_pos + 0] = data->vertices[(int)temp_i.x + offset].x;
		pos[v->i_pos + 1] = data->vertices[(int)temp_i.x + offset].y;
		pos[v->i_pos + 2] = data->vertices[(int)temp_i.x + offset].z;
		pos[v->i_pos + 3] = data->vertices[(int)temp_i.y + offset].x;
		pos[v->i_pos + 4] = data->vertices[(int)temp_i.y + offset].y;
		pos[v->i_pos + 5] = data->vertices[(int)temp_i.y + offset].z;
		pos[v->i_pos + 6] = data->vertices[(int)temp_i.z + offset].x;
		pos[v->i_pos + 7] = data->vertices[(int)temp_i.z + offset].y;
		pos[v->i_pos + 8] = data->vertices[(int)temp_i.z + offset].z;

		printf("Vertex @ %d :  %f, %f, %f\n", (int)temp_i.x, 
		data->vertices[(int)temp_i.x + offset].x,
		data->vertices[(int)temp_i.x + offset].y,
		data->vertices[(int)temp_i.x + offset].z);
	
		//it's a quad
		//make second triangle
		if (!(temp_i.w < 0))
		{
			pos[v->i_pos + 9] = pos[v->i_pos + 0];
			pos[v->i_pos + 10] = pos[v->i_pos + 1];
			pos[v->i_pos + 11] = pos[v->i_pos + 2];

			pos[v->i_pos + 12] = pos[v->i_pos + 6];
			pos[v->i_pos + 13] = pos[v->i_pos + 7];
			pos[v->i_pos + 14] = pos[v->i_pos + 8];

			pos[v->i_pos + 15] = data->vertices[(int)temp_i.w + offset].x;
			pos[v->i_pos + 16] = data->vertices[(int)temp_i.w + offset].y;
			pos[v->i_pos + 17] = data->vertices[(int)temp_i.w + offset].z;
			v->i_pos += 9;
		}
	}
	v->i_pos += 9;
	printf("N FACES == %d\n", v->i_pos);
}

void	check_out_floats(float *data, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}\n",
		data[i + 0], data[i + 1], data[i + 2],
		data[i + 3], data[i + 4], data[i + 5],
		data[i + 6], data[i + 7], data[i + 8]);
		i += 9;
	}
}

void	order_data(t_vertex_table **v, t_obj_data **data, int n_groups, int flags)
{
	int			sign;
	int			i;

	i = 0;
	sign = BIT_CHECK(flags, NEGATIVE_INDEXES) ? -1 : 1;
	printf("Groups == %d\n", n_groups);
	while (i < n_groups)
	{
		order_position(v[i], data[i], sign);
	//	check_out_floats(v[i]->positions, v[i]->i_pos);
	/*
		if (BIT_CHECK(flags, TEXT_COORDS_DEFINED))
  	
			order(v->text_coords, data[i], j, sign);
		if (BIT_CHECK(flags, NORMALS_DEFINED))
			order(v->normals, data[i], j, sign);
		j += 4;
	*/
		i++;
	}
	printf("finished ordering data\n");
}
