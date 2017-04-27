#version 410

in vec3 position;
vec4 pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform mat4 offset;

void	main()
{
	pos = model * offset * vec4(position, 1.0);	
	gl_Position = proj * view * pos;
}
