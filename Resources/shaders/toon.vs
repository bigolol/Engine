#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 normal;

uniform mat4 transformMatrix;
uniform mat4 projViewMat;
uniform mat4 normalTransformMatrix;
uniform vec3 lightSource;

out vec3 outColor;

vec3 calculatedColor;
vec3 transformedNormal;
void main()
{
	transformedNormal = normalize(vec3((normalTransformMatrix * vec4(normal, 0.0f))));
	gl_Position = projViewMat * transformMatrix * vec4(position, 1.0f);
	vec3 vectorToLight = normalize(lightSource - position);
	float factor = max(dot(transformedNormal, vectorToLight),0);
	outColor = color * factor;
}