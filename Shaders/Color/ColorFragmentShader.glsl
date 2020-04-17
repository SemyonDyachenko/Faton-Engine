#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;
	
void main()
{
	gl_FragColor = u_Color;
}