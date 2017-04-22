/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 01:32:49 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 04:37:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	check_shader_compile(GLuint shader_name)
{
	GLint	status;
	char	*buffer = malloc(512);

	glGetShaderiv(shader_name, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetShaderInfoLog(shader_name, 512, NULL, buffer);
		printf("%s\n", buffer);
		exit(1);
	}
	free(buffer);
}

//void	log(char *message, void *value, int type)
//{
//	fprintf(scop_log, "%s : %c" message, );
//}

void	status_gl(const char *message, int line, char *file)
{
	int	err;

	if ((err = glGetError()) != GL_NO_ERROR)
	{
		printf("Error : %d at  %d, %s\n", err, line, file);
		exit(1);
	}
	else
		printf("Succeded : %s\n", message);
}

void		check_groups(t_group_lst *group)
{
	int	i;

	i = 0;
	while (group != NULL)
	{
		printf("Group %d\n", i);
		printf("n normals =\t%d\n", group->n_normals);
		printf("n vertices =\t%d\n", group->n_vertices);
		printf("n text coords = %d\n", group->n_text_coords);
		i++;
		group = group->next;
	}
}
