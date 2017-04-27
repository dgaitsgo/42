#version 410

out vec4 frag_colour;

in vec3 fNormal;

void main () {
	frag_colour = vec4 (fNormal, 1.0);
}
