#version 330 core

layout(location = 0) in vec3 vertex_position_modelspace;
layout(location = 1) in vec3 inColor;

out vec3 gsColor;
uniform mat4 MVP; //Model View Projection
uniform vec3 object_position;

void main()
{
	gl_Position =  MVP * (vec4(vertex_position_modelspace, 1) + vec4(object_position, 1));
	
	gsColor = inColor;
}