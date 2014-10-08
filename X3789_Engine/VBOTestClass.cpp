
#include <stdafx.h>
#include <X3789_Engine\Common\ControlInterface.h>
#include "VBOTestClass.h"
#include <ctime>

#define CUBE_NUM 60

VBOTestClass::VBOTestClass()
{
}


VBOTestClass::~VBOTestClass()
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

float* agetVerticesWithColors();

/*float* VBOTestClass::getVerticesWithColors()
{
	return agetVerticesWithColors();
}*/

float* VBOTestClass::getVerticesWithColors()
{
	test_vertex* vertices = (test_vertex*)malloc(CUBE_NUM * CUBE_NUM * sizeof(test_vertex) * 8);

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

	return (float*)vertices;
}

GLuint* VBOTestClass::getIndices()
{
	GLuint* indices = (GLuint*)malloc(36 * CUBE_NUM * CUBE_NUM * sizeof(GLuint));

	for (unsigned int i = 0; i < CUBE_NUM * CUBE_NUM; ++i)
	{
		indices[i * 36 + 0] = 0 + i*8;
		indices[i * 36 + 1] = 1 + i*8;
		indices[i * 36 + 2] = 2 + i*8;
		indices[i * 36 + 3] = 0 + i*8;
		indices[i * 36 + 4] = 2 + i*8;
		indices[i * 36 + 5] = 3 + i*8;

		indices[i * 36 + 6] = 4 + i*8;
		indices[i * 36 + 7] = 0 + i*8;
		indices[i * 36 + 8] = 3 + i*8;
		indices[i * 36 + 9] = 4 + i*8;
		indices[i * 36 + 10] = 3 + i*8;
		indices[i * 36 + 11] = 7 + i*8;


		indices[i * 36 + 12] = 5 + i*8;
		indices[i * 36 + 13] = 4 + i*8;
		indices[i * 36 + 14] = 7 + i*8;
		indices[i * 36 + 15] = 5 + i*8;
		indices[i * 36 + 16] = 7 + i*8;
		indices[i * 36 + 17] = 6 + i*8;


		indices[i * 36 + 18] = 1 + i*8;
		indices[i * 36 + 19] = 5 + i*8;
		indices[i * 36 + 20] = 6 + i*8;
		indices[i * 36 + 21] = 1 + i*8;
		indices[i * 36 + 22] = 6 + i*8;
		indices[i * 36 + 23] = 2 + i*8;


		indices[i * 36 + 24] = 0 + i*8;
		indices[i * 36 + 25] = 4 + i*8;
		indices[i * 36 + 26] = 5 + i*8;
		indices[i * 36 + 27] = 1 + i*8;
		indices[i * 36 + 28] = 0 + i*8;
		indices[i * 36 + 29] = 5 + i*8;

		indices[i * 36 + 30] = 3 + i*8;
		indices[i * 36 + 31] = 2 + i*8;
		indices[i * 36 + 32] = 6 + i*8;
		indices[i * 36 + 33] = 3 + i*8;
		indices[i * 36 + 34] = 6 + i*8;
		indices[i * 36 + 35] = 7 + i*8;
	}

	return indices;
}

void VBOTestClass::PreDraw()
{
	test_vertex* tv = new test_vertex[10];

	GLuint* indices = getIndices();
	float* vertices_ptr = getVerticesWithColors();

	//vertices with colros
	glGenBuffers(1, &vertex_with_colors_id);	GL_ERROR;
	glBindBuffer(GL_ARRAY_BUFFER, vertex_with_colors_id);	GL_ERROR;
	glBufferData(GL_ARRAY_BUFFER, CUBE_NUM * CUBE_NUM * 8 * 6 * sizeof(GLfloat), vertices_ptr, GL_STATIC_DRAW);	GL_ERROR;
	
	//indices
	glGenBuffers(1, &indices_buffer_id);	GL_ERROR;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_id);	GL_ERROR;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, CUBE_NUM * CUBE_NUM * 36 * sizeof(GLuint), indices, GL_STATIC_DRAW);	GL_ERROR;

	anotherTest();
	anotherTest2();
}


#define array_size 64 * 64 * 64

void VBOTestClass::anotherTest()
{
	test_vertex* test_array = new test_vertex[array_size];
	
	test_vertex t;

	t.r = 234;
	t.g = 345;
	t.b = 546;
	t.x = 667;
	t.y = 231;
	t.z = 213;

	test_array[array_size - 1] = t;
	
	clock_t start;
	clock_t end;

	unsigned int b;
	unsigned int len = sizeof(test_vertex) / 8;

	double* v1 = (double*)&t;
	double* v2;
	bool find;
	unsigned int i;

	for (int j = 0; j < 10; ++j)
	{
		start = clock();

		for (i = 0; i < array_size; ++i)
		{
			v2 = (double*)&test_array[i];
			find = true;

			for (b = 0; b < len; ++b)
			{
				if (v1[b] != v2[b])
				{
					find = false;
					break;
				}
			}

			if (find)
			{
				end = clock();
				double time_elapsed = double(end - start) / CLOCKS_PER_SEC;
				printf("Time elapsed: %f\n", time_elapsed);
			}
		}
	}
	
	delete[] test_array;
}

void VBOTestClass::anotherTest2()
{
	unsigned long l = array_size;
	printf("normal cmp %lu \n", l);
	test_vertex* test_array = new test_vertex[array_size];

	test_vertex t;

	t.r = 234;
	t.g = 345;
	t.b = 546;
	t.x = 667;
	t.y = 231;
	t.z = 213;

	test_array[array_size - 1] = t;

	clock_t start;
	clock_t end;

	unsigned int b;
	unsigned int len = sizeof(test_vertex);

	BYTE* v1 = (BYTE*)&t;
	BYTE* v2;
	bool find;
	unsigned int i;

	for (int j = 0; j < 10; ++j)
	{
		start = clock();

		for (i = 0; i <array_size; ++i)
		{
			if (test_array[i].x == t.x &&
				test_array[i].y == t.y &&
				test_array[i].z == t.z &&
				test_array[i].r == t.r &&
				test_array[i].g == t.g &&
				test_array[i].b == t.b)
			{
				end = clock();
				double time_elapsed = double(end - start) / CLOCKS_PER_SEC;
				printf("Time elapsed: %f\n", time_elapsed);
			}
		}
	}

	delete[] test_array;
}

void VBOTestClass::Draw(GLuint shader)
{
	glUseProgram(shader);


	GLuint mvp_id = glGetUniformLocation(shader, "MVP");	GL_ERROR;
	glUniformMatrix4fv(mvp_id, 1, GL_FALSE, ControlInterface::getMVPData()); GL_ERROR;

	GLuint id = 999;

	id = glGetAttribLocation(shader, "vertex_position_modelspace"); GL_ERROR;
	glEnableVertexAttribArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_with_colors_id); GL_ERROR;
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); GL_ERROR;

	id = glGetAttribLocationARB(shader, "inColor"); GL_ERROR;
	glEnableVertexAttribArray(id);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertex_with_colors_id); GL_ERROR;
	glVertexAttribPointerARB(id, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); GL_ERROR;


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer_id); GL_ERROR;

	glDrawElements(GL_TRIANGLES, CUBE_NUM * CUBE_NUM * 36, GL_UNSIGNED_INT, (void*)0); GL_ERROR;
}
void VBOTestClass::PostDraw()
{

}
