#version 410

layout ( triangles ) in;
layout ( triangle_strip, max_vertices = 3 ) out;

in vData {
	vec4 raw_pos;
}	vertices[];

vec3 		temp1;
vec3 		temp2;
out vec3	fNormal;
out	vec4	fPositions;

void	main()
{
	fPositions = vertices[0].raw_pos; 
	for (int i = 0; i < gl_in.length(); i++)
	{ 
		gl_Position = gl_in[0].gl_Position;
		temp1 = gl_in[1].gl_Position.xyz - gl_Position.xyz;
		temp2 = gl_in[2].gl_Position.xyz - gl_Position.xyz;
		fNormal = normalize (cross (temp1, temp2));

			EmitVertex ();
		gl_Position = gl_in[1].gl_Position;
			EmitVertex ();
		gl_Position = gl_in[2].gl_Position;
			EmitVertex ();
	}
	EndPrimitive ();
}
