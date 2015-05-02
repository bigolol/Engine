#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 normal;

uniform mat4 transformMatrix;
uniform mat4 projViewMat;

uniform vec4 lightPosition;
uniform vec3 Kd;
uniform vec3 Ld;
uniform mat3 normalMatrix;
out vec3 outColor;

void main()
{
	vec3 tnorm = normalize(normalMatrix * normal);
	vec4 newPos =  projViewMat * transformMatrix * vec4(position, 1.0f);
	vec3 s = normalize(vec3(lightPosition - newPos));
	gl_Position = newPos;

	outColor = color * Ld * Kd * max(dot(s, tnorm), 0.0f);
}