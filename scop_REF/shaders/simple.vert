#version 410

in vec3 position;
uniform mat4 y_rotation;
uniform mat4 persp;
uniform float scale;
uniform vec4 trans;
uniform mat4 model;
mat4 scale_mat = mat4(0.005);

void	main()
{
	gl_Position = vec4(position, 1.0);
}
