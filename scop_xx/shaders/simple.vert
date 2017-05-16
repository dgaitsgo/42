#version 410

in 	vec3 position;

out vData {
	vec4 raw_pos;
}	vertex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform mat4 offset;

void	main()
{
	vertex.raw_pos = vec4(position, 1.0);
	gl_Position = proj * view * model * offset * vertex.raw_pos;	
}
