#version 410

in vec3 position;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void	main()
{
	//gl_Position = proj * model * vec4(position, 1.0);
	gl_Position = proj * view * model * vec4(position, 1.0);
}
