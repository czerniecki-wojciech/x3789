
#include "stdafx.h"
#include "VertexStorage.h"

const unsigned int VertexStorage::size_of_vertex = sizeof(VertexData);

VertexStorage::VertexStorage(unsigned int grow_by)
	: vertices_num(0)
	, allocated_vertices_num(0)
	, grow_by(grow_by)
	, vertices(NULL)
{
}


VertexStorage::~VertexStorage()
{
	if (vertices)
		free(vertices);
}

/*
Vertex* VertexStorage::newVertex()
{
	return this->allocNewVertexSpace();
}
*/

/*
void VertexStorage::newVertex(Vertex* vertex)
{
	memcpy((BYTE*)this->allocNewVertexSpace(), vertex, size_of_vertex);
}
*/

void VertexStorage::newVertex(float x, float y, float z, float r, float g, float b)
{
	VertexData* vertex = this->allocNewVertexSpace();
	vertex->data = glm::vec3(x, y, z);

	VertexData* color = this->colors + vertices_num - 1;
	color->data = glm::vec3(r, g, b);

	//return vertex;
}

VertexData* VertexStorage::allocNewVertexSpace()
{
	if (vertices_num < allocated_vertices_num + 1)
	{
		VertexData* new_vertices_memory = (VertexData*)malloc(size_of_vertex * (allocated_vertices_num + grow_by));

		VertexData* new_vertices_color_memory = (VertexData*)malloc(size_of_vertex * (allocated_vertices_num + grow_by));

		if (vertices)
		{
			memcpy((BYTE*)new_vertices_memory, vertices, allocated_vertices_num * size_of_vertex);
			free(vertices);

			memcpy((BYTE*)new_vertices_color_memory, colors, allocated_vertices_num * size_of_vertex);
			free(colors);
		}
		vertices = new_vertices_memory;
		colors = new_vertices_color_memory;
		allocated_vertices_num += grow_by;
	}

	return vertices + vertices_num++;

}
