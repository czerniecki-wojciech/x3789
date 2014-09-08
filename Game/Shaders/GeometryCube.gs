layout(points) in;
layout(triangle_strip, max_vertices = 14) out;

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
    gl_Position = gl_in[0].gl_Position + vec4(-0.1, 0.0, 0.0, 0.0);
    EmitVertex();

    gl_Position = gl_in[0].gl_Position + vec4(0.1, 0.0, 0.0, 0.0);
    EmitVertex();

    EndPrimitive();
	
	cube(gl_in[0].gl_Position);
}