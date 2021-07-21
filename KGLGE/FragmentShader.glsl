#version 330 core

layout(location=0) out vec4 color;

in vec2 v_TexCoord;
in float v_texID;

uniform sampler2D u_Texture[8];

void main()
{
	int index = int(v_texID);
	vec4 texColor = texture(u_Texture[index], v_TexCoord);
	if(texColor[3] < 0.1)
		discard;
	color = texColor;
}