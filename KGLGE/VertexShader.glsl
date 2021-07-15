#version 330 core

layout(location=0) in vec4 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in float texID;

out vec2 v_TexCoord;
out float v_texID;

void main()
{
	gl_Position= position;
	v_texID = texID;
	v_TexCoord = texCoord;
}