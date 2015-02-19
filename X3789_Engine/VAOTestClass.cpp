
#include <stdafx.h>
#include <Common/ControlInterface.h>
#include "VAOTestClass.h"

#define CUBE_NUM 10

VAOTestClass::VAOTestClass()
{
}


VAOTestClass::~VAOTestClass()
{
}

class test_vertex
{
public:
	float x, y, z, r, g, b;

	test_vertex()
		: x(3)
		, y(3)
		, z(3)
		, r(3)
		, g(3)
		, b(3)
	{}

	test_vertex(float x, float y, float z, float r, float g, float b)
		: x(x)
		, y(y)
		, z(z)
		, r(r)
		, g(g)
		, b(b)
	{}
};

float* VAOTestClass::getVerticesWithColors()
{
	test_vertex* vertices = (test_vertex*)std::malloc(CUBE_NUM * CUBE_NUM * sizeof(test_vertex) * 8);

	for (unsigned int h = 0; h < CUBE_NUM; ++h)
	{
		for (unsigned int v = 0; v < CUBE_NUM; ++v)
		{
			test_vertex v1(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 0.0f, 0.0f);
			test_vertex v2(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 0.0f, 1.0f, 0.0f);
			test_vertex v3(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 0.0f, 0.0f, 1.0f);
			test_vertex v4(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);

			test_vertex v5(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 0.0f, 1.0f);
			test_vertex v6(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 0.0f, 1.0f, 1.0f);
			test_vertex v7(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
			test_vertex v8(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 0.0f, 0.0f, 0.0f);

			vertices[h * CUBE_NUM * 8 + v * 8 + 0] = v1;
			vertices[h * CUBE_NUM * 8 + v * 8 + 1] = v2;
			vertices[h * CUBE_NUM * 8 + v * 8 + 2] = v3;
			vertices[h * CUBE_NUM * 8 + v * 8 + 3] = v4;

			vertices[h * CUBE_NUM * 8 + v * 8 + 4] = v5;
			vertices[h * CUBE_NUM * 8 + v * 8 + 5] = v6;
			vertices[h * CUBE_NUM * 8 + v * 8 + 6] = v7;
			vertices[h * CUBE_NUM * 8 + v * 8 + 7] = v8;
		}
	}
	printf("vertices num: %d(%d bytes)\n", CUBE_NUM * CUBE_NUM * 8, CUBE_NUM * CUBE_NUM * sizeof(test_vertex) * 8);

	return (float*)vertices;
}

void VAOTestClass::PreDraw()
{
	float* vertices_ptr = getVerticesWithColors();

	//vertices with colros
	glGenBuffers(1, &vertex_with_colors_id);	GL_ERROR;
	glBindBuffer(GL_ARRAY_BUFFER, vertex_with_colors_id);	GL_ERROR;
	glBufferData(GL_ARRAY_BUFFER, CUBE_NUM * CUBE_NUM * 8 * 6 * sizeof(GLfloat), vertices_ptr, GL_DYNAMIC_DRAW);	GL_ERROR;
}


#define array_size 64 * 64 * 64

void VAOTestClass::Draw(GLuint shader)
{
	glUseProgram(shader); //use shader set

	GLuint mvp_id = glGetUniformLocation(shader, "MVP");	GL_ERROR;
	glUniformMatrix4fv(mvp_id, 1, GL_FALSE, ControlInterface::getMVPData()); GL_ERROR;

	GLuint id = -1;

	id = glGetAttribLocation(shader, "vertex_position_modelspace"); GL_ERROR;
	glEnableVertexAttribArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_with_colors_id); GL_ERROR;
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); GL_ERROR;

	id = glGetAttribLocation(shader, "inColor"); GL_ERROR;
	glEnableVertexAttribArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_with_colors_id); GL_ERROR;
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); GL_ERROR;


	glDrawArrays(GL_TRIANGLES, 0, CUBE_NUM * CUBE_NUM * 36); GL_ERROR;
}
void VAOTestClass::PostDraw()
{

}
