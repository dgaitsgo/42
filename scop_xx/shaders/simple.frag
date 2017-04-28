#version 410

out vec4 frag_colour;
vec4 normal_map;

in vec3 fNormal;

uniform sampler2D basic_texture;

vec2 text_coords;

void main () {
	text_coords = gl_FragCoord.xz;
	normal_map = vec4 (fNormal, 1.0);
	frag_colour = vec4(sin(normal_map.z), cos(text_coords.y), tan(normal_map.x) * gl_FragCoord.z, 1);

	//texture(basic_texture, text_coords);

}
