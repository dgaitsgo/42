#version 410

layout ( triangles ) in;
layout ( triangle_strip, max_vertices = 3 ) out;

vec3 temp1;
vec3 temp2;
out vec3 fNormal;

void	main()
{
	gl_Position = gl_in[0].gl_Position;
	temp1 = gl_in[1].gl_Position.xyz - gl_Position.xyz;
	temp2 = gl_in[2].gl_Position.xyz - gl_Position.xyz;
	fNormal = normalize (cross (temp1, temp2));
	gl_Position = gl_Position;
	EmitVertex ();
	
	gl_Position = gl_in[1].gl_Position;
	EmitVertex ();
 
	gl_Position = gl_in[2].gl_Position;
	EmitVertex ();
	EndPrimitive ();
}
