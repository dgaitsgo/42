#version 410

layout ( triangles ) in;
layout ( triangle_strip, max_vertices = 3 ) out;

in vData {
	int		render_mode;
	vec4	raw_pos;
} vertices[];

vec3 			temp1;
vec3 			temp2;

out vec3		fNormal;
flat out int	render_mode;
out	vec4		fPositions;

void	main()
{
//	fPositions = vertices[0].raw_pos;
	render_mode = vertices[0].render_mode;
	for (int i = 0; i < gl_in.length(); i++)
	{
		gl_Position = gl_in[0].gl_Position;
		temp1 = gl_in[1].gl_Position.xyz - gl_Position.xyz;
		temp2 = gl_in[2].gl_Position.xyz - gl_Position.xyz;
		fNormal = normalize (cross (temp1, temp2));

		fPositions = vertices[0].raw_pos;
			EmitVertex ();
		gl_Position = gl_in[1].gl_Position;
		fPositions = vertices[1].raw_pos;
			EmitVertex ();
		gl_Position = gl_in[2].gl_Position;
		fPositions = vertices[2].raw_pos;
			EmitVertex ();
	}
	EndPrimitive ();
}
