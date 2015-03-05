
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

VertexCollector::VertexCollector()
    : vertices_num(0)
{
    vertices = (test_vertex*)malloc(1000 * sizeof(test_vertex));
}

VertexCollector::~VertexCollector()
{
    free(vertices);
}

void VertexCollector::addVertex(float x, float y, float z, float r, float g, float b){
    test_vertex v(x, y, z, r, g, b);

    vertices[vertices_num++] = v;
}

float* VAOTestClass::getVerticesWithColors()
{
    test_vertex* vertices = (test_vertex*)std::malloc(CUBE_NUM * CUBE_NUM * sizeof(test_vertex) * 6 * 6);

	for (unsigned int h = 0; h < CUBE_NUM; ++h)
	{
		for (unsigned int v = 0; v < CUBE_NUM; ++v)
        {
            //front1
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //front2
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //back1
/*            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //back2
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //left1
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);
            //left2
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);
            //right1
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //right2
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //top1
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //top2
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h - CUBE_SIZE_2, v + CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //bottom1
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            //bottom2
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 - CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h + CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
            collector.addVertex(h - CUBE_SIZE_2, v - CUBE_SIZE_2, 0 + CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
*/
		}
	}
	printf("vertices num: %d(%d bytes)\n", CUBE_NUM * CUBE_NUM * 8, CUBE_NUM * CUBE_NUM * sizeof(test_vertex) * 8);

	return (float*)vertices;
}

void VAOTestClass::PreDraw()
{
    float* vertices_ptr = reinterpret_cast<float*>(collector.getVertices());

	//vertices with colros
	glGenBuffers(1, &vertex_with_colors_id);	GL_ERROR;
	glBindBuffer(GL_ARRAY_BUFFER, vertex_with_colors_id);	GL_ERROR;
    glBufferData(GL_ARRAY_BUFFER, collector.getVerticesNum() * 6 * sizeof(GLfloat), vertices_ptr, GL_DYNAMIC_DRAW);	GL_ERROR;
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


    glDrawArrays(GL_TRIANGLES, 0, collector.getVerticesNum()); GL_ERROR;
}
void VAOTestClass::PostDraw()
{

}
