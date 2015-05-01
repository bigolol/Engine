#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform mat4 viewMatrix;
uniform mat4 projMatrix;
out vec3 outColor;
void main()
{
	gl_Position = projMatrix * viewMatrix * vec4(position, 1.0f);
	outColor = color;
}