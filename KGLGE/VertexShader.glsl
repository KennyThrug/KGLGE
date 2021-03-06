#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in float texID;
layout(location = 3) in vec4 colour;

uniform float u_x_min;
uniform float u_x_max;
uniform float u_y_min;
uniform float u_y_max;

out vec2 v_TexCoord;
out float v_texID;
out vec4 v_colour;

void main()
{
	vec4 localPos = vec4( (((position[0] - u_x_min)/(u_x_max-u_x_min)) * 2) - 1,
						  (((position[1] - u_y_min)/(u_y_max-u_y_min)) * 2) - 1,
						  position[2],
						  position[3]);
	gl_Position= localPos;
	v_texID = texID;
	v_TexCoord = texCoord;
	v_colour = colour;
}