#include "scop.h"

void	perspective_matrix(t_matrix m, float fov, float aspect_ratio)
{
	float		z_range;

	fov = in_radians(fov / 2.0f);
	z_range = Z_NEAR - Z_FAR;
	m[0][0] = 1.0f / (fov * aspect_ratio);
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1.0f / fov;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = (-Z_NEAR - Z_FAR) / z_range;
	m[2][3] = 2.0f * Z_FAR * Z_NEAR / z_range;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 1;
	m[3][3] = 0;
}

void	init_camera(t_camera *camera)
{
	perspective_matrix(camera->perspective, FOV, ASPECT_RATIO);
	set_vector(&camera->forward,0, 0, 1);
	set_vector(&camera->up, 0, 1, 0);
}
