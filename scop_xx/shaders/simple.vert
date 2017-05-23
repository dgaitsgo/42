#version 410

in 	vec3 position;

out vData {
	int		render_mode;
	vec4	raw_pos;
}	vertex;

uniform int render_mode;

void	main()
{
	vertex.raw_pos = vec4(position, 1.0);
	vertex.render_mode = render_mode;
	gl_Position = vertex.raw_pos;
}
