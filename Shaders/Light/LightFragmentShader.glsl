#version 330 core

layout(location = 0) out vec4 color;


in vec2 v_ScreenPos;

uniform vec4 u_Color;

void main()
{
	float dist = 1.0f - distance(v_ScreenPos * 0.8f,vec2(0.0f));
	dist = clamp(dist,0.0f,1.0f);

	dist = sqrt(dist);
	
	color =  u_Color * dist;
}