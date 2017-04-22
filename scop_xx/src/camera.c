#include "scop.h"

void	perspective_matrix(t_matrix m, float fov, float aspect_ratio)
{
	float range;
	float sx;
	float sy;
	float sz;
	float pz;

	range = tan(in_radians(fov * 0.5)) * Z_NEAR;
	sx = (2 * Z_NEAR) / (range * aspect_ratio + range * aspect_ratio);
	sy = Z_NEAR / range;
	sz = -(Z_FAR + Z_NEAR) / (Z_FAR - Z_NEAR);
	pz = -(2 * Z_FAR * Z_NEAR) / (Z_FAR - Z_NEAR);
	zero_matrix(m);
	print_matrix(m);
	m[0][0] = sx;
	m[1][1] = sy; 
	m[2][2] = sz; 
	m[2][3] = -1;
	m[3][2] = pz;
}


void	init_camera(t_camera *camera)
{
	perspective_matrix(camera->perspective, FOV, ASPECT_RATIO);
	set_vector(&camera->forward,0, 0, 1);
	set_vector(&camera->up, 0, 1, 0);
}
