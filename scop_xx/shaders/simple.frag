#version 410

//Defines:
	const uint		mode_greyScale = 0;
	const uint		mode_normalMapping = 1;

//Uniforms
uniform float		fade;

//Ins
in	vec3 			fNormal;
in	vec4			fPositions;
flat in int			render_mode;

vec4				color;
vec4				texel;
vec2				text_coords;

//Out
out vec4			frag_color;

uniform sampler2D	basic_texture;

float		map(float value, float low1, float high1, float low2, float high2)
{
	return (low2 + (value - low1) * (high2 - low2) / (high1 - low1));
}

void		 main () {

	text_coords.x = map(fPositions.x, -1, 1, 0, 1);
	text_coords.y = map(fPositions.y, -1, 1, 0, 1);
	texel = texture(basic_texture, text_coords); 

	if (render_mode == mode_greyScale)
	{
		float grey = (abs(fNormal.x) * 0.1f + abs(fNormal.y) * 0.4f + abs(fNormal.z) * 0.2f) / 3.0f + 0.2f;
		color = vec4(grey, grey, grey, 1.0);
	}
	else if (render_mode == mode_normalMapping)
	{
		color = vec4 (fNormal, 1.0);
	}
	frag_color = mix(color, texel, fade);
}
