#version 460 core

layout(location=0) out vec4 color;

in vec2 v_TexCoord;
in float v_texID;
in vec4 v_colour;

uniform sampler2D u_Texture[8];

void main()
{
	int index = int(v_texID);
	if(index == -1){
		color = v_colour;
	}
	else{
		vec4 texColor = texture(u_Texture[index], v_TexCoord);
		if(texColor[3] < 0.1)
			discard;
		color = texColor;
	}
}