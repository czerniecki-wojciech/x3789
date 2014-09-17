
#include <stdafx.h>
#include <X3789_Engine\Common\ControlInterface.h>
#include "VBOTestClass.h"


VBOTestClass::VBOTestClass()
{
}


VBOTestClass::~VBOTestClass()
{
}


void VBOTestClass::PreDraw()
{
	float vertices[] =
	{
		 1.0f,	 1.0f,	1.0f,
		-1.0f,	 1.0f,	1.0f,
		-1.0f,	-1.0f,	1.0f,
		 1.0f,	-1.0f,	1.0f,

		 1.0f,	 1.0f, -1.0f,
		-1.0f,	 1.0f, -1.0f,
		-1.0f,	-1.0f, -1.0f,
		 1.0f,	-1.0f, -1.0f
	};

	float colors[] =
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f
	};

	GLushort indices[] =
	{
		0, 1, 2,
		0, 2, 3,

		0, 1, 5,
		0, 5, 4,

		0, 3, 4,
		0, 4, 7,

		2, 3, 7,
		2, 6, 7,

		1, 2, 6,
		1, 5, 6,

		4, 5, 6,
		4, 6, 7
	};

	//vertices
	glGenBuffers(1, &vertex_buffer_id);	GL_ERROR();
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);	GL_ERROR();
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(GLfloat), 0, GL_STATIC_DRAW);	GL_ERROR();

	GLvoid* vbo_buffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	memcpy(vbo_buffer, vertices, sizeof(vertices) * sizeof(GLfloat));

	glUnmapBuffer(GL_ARRAY_BUFFER);

	glVertexPointer(3, GL_FLOAT, 0, (GLvoid*)0);

	/*colors
	glGenBuffers(1, &color_buffer_id);	GL_ERROR();
	glBindBuffer(GL_ARRAY_BUFFER, color_buffer_id);	GL_ERROR();
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors) * sizeof(float), colors, GL_STATIC_DRAW);	GL_ERROR();
	*/
	//indices
	glGenBuffers(1, &indices_buffer_id);	GL_ERROR();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_id);	GL_ERROR();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * sizeof(GLubyte), indices, GL_STATIC_DRAW);	GL_ERROR();
}
void VBOTestClass::Draw(GLuint shader)
{
	glUseProgram(shader);


	GLuint mvp_id = glGetUniformLocation(shader, "MVP");	GL_ERROR();
	glUniformMatrix4fv(mvp_id, 1, GL_FALSE, ControlInterface::getMVPData()); GL_ERROR();

	GLuint id = 999;
	id = glGetAttribLocation(shader, "vertex_position_modelspace"); GL_ERROR();

	glEnableVertexAttribArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id); GL_ERROR();
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0); GL_ERROR();

	//id = glGetAttribLocationARB(shader, "inColor"); GL_ERROR();
	//glBindBufferARB(GL_ARRAY_BUFFER_ARB, color_buffer_id); GL_ERROR();
	//glVertexAttribPointerARB(id, 3, GL_FLOAT, GL_FALSE, GL_FALSE, (void*)0); GL_ERROR();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_id); GL_ERROR();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0); GL_ERROR();
	//glDrawRangeElements(GL_TRIANGLES, 0, 3, 3, GL_UNSIGNED_SHORT, (void*)0);

	//glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indices_buffer_id);
	//glEnableClientState(GL_VERTEX_ARRAY);
	//glVertexPointer(3, GL_FLOAT, 0, 0);
}
void VBOTestClass::PostDraw()
{

}
