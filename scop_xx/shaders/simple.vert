#version 410

in vec3 position;
uniform mat4 rotation;
uniform mat4 projection;
uniform float scale;
uniform vec3 translation;
mat4 scale_mat = mat4(0.005);

void	main()
{
	
	gl_Position =
		projection * (vec4(translation, 0.0) + rotation * (scale_mat * vec4(position, 1.0)));
}
