#version 410

uniform	 float		fade;

out vec4			frag_colour;

in	vec3 			fNormal;
in	vec4			fPositions;

vec4 				normal_map;
vec4				texel;
vec2				text_coords;

uniform sampler2D	basic_texture;

float		map(float value, float low1, float high1, float low2, float high2)
{
	return (low2 + (value - low1) * (high2 - low2) / (high1 - low1));
}

void		 main () {

	text_coords.x = map(fPositions.x, -1, 1, 0, 1);
	text_coords.y = map(fPositions.y, -1, 1, 0, 1);

	texel = texture(basic_texture, text_coords); 
	normal_map = vec4 (fNormal, 1.0);

	frag_colour = mix(normal_map, texel, fade);
}
