#version 330 core

layout(location = 0) out vec4 color;

in vec2 TexCoord;
	
uniform sampler2D m_Texture;
		

uniform vec4 m_Color;
	
void main()
{
	color = m_Color;
}