#version 330 core

// Interpolated values from the vertex shaders

in vec4 particlecolor;

// Output data
out vec4 color;

void main(){
	// Output color = color of the texture at the specified UV
	color = vec4(1,0.5,1,1);
}