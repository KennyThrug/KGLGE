#version 330 core

layout(location=0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in float texID;
layout(location = 3) in vec4 colour;

uniform vec4 u_windowSize;

out vec2 v_TexCoord;
out float v_texID;
out vec4 v_colour;

float toLocal(float start,float maximum, float minimum){
	if(minimum == maximum){
		minimum = -1;
		maximum = 1;
	}
	else{
		return start - 0.25;
	}
	return (((start-minimum)/(maximum-minimum) * 2) - 1);
}
void main()
{
	vec4 localPos = vec4(toLocal(position[0],u_windowSize[1],u_windowSize[0]),
						toLocal(position[1],u_windowSize[3],u_windowSize[2]),
						toLocal(position[2],u_windowSize[1],u_windowSize[0]),
						toLocal(position[3],u_windowSize[3],u_windowSize[2]));
	gl_Position= localPos;
	v_texID = texID;
	v_TexCoord = texCoord;
	v_colour = u_windowSize;
}