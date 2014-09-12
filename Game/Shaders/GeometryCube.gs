#version 330 core

layout(points) in;
layout(triangle_strip, max_vertices = 14) out;

in vec3 gsColor[];
out vec3 psColor;

void cube(vec4 position)
{
	gl_Position = position + vec4(0.5f, 0.5f, -0.5f, 0.0f); //A
	EmitVertex();
	gl_Position = position + vec4(0.5f, -0.5f, -0.5f, 0.0f); //B
	EmitVertex();
	gl_Position = position + vec4(-0.5f, 0.5f, -0.5f, 0.0f); //C
	EmitVertex();
	gl_Position = position + vec4(-0.5f, -0.5f, -0.5f, 0.0f); //D
	EmitVertex();
	gl_Position = position + vec4(-0.5f, -0.5f, 0.5f, 0.0f); //E
	EmitVertex();
	gl_Position = position + vec4(0.5f, -0.5f, -0.5f, 0.0f); //B
	EmitVertex();
	gl_Position = position + vec4(0.5f, -0.5f, 0.5f, 0.0f); //F
	EmitVertex();
	gl_Position = position + vec4(0.5f, 0.5f, 0.5f, 0.0f); //G
	EmitVertex();
	gl_Position = position + vec4(-0.5f, -0.5f, 0.5f, 0.0f); //E
	EmitVertex();
	gl_Position = position + vec4(-0.5f, 0.5f, 0.5f, 0.0f); //H
	EmitVertex();
	gl_Position = position + vec4(-0.5f, 0.5f, -0.5f, 0.0f); //C
	EmitVertex();
	gl_Position = position + vec4(0.5f, 0.5f, 0.5f, 0.0f); //G
	EmitVertex();
	gl_Position = position + vec4(0.5f, 0.5f, -0.5f, 0.0f); //A
	EmitVertex();
	gl_Position = position + vec4(0.5f, -0.5f, -0.5f, 0.0f); //B
	EmitVertex();
	
	EndPrimitive();
}

void main() {
	psColor = gsColor[0];
    
	cube(gl_in[0].gl_Position);
}