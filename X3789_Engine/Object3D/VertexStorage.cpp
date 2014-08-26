
#include "stdafx.h"
#include "VertexStorage.h"

const unsigned int VertexStorage::size_of_vertex = sizeof(Vertex);

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

Vertex* VertexStorage::newVertex()
{
	return this->allocNewVertexSpace();
}

/*
void VertexStorage::newVertex(Vertex* vertex)
{
	memcpy((BYTE*)this->allocNewVertexSpace(), vertex, size_of_vertex);
}
*/

void VertexStorage::newVertex(float x, float y, float z, float r, float g, float b)
{
	Vertex* vertex = this->allocNewVertexSpace();
	vertex->position = glm::vec3(x, y, z);
//	vertex->color = glm::vec3(r, g, b);

	//return vertex;
}

Vertex* VertexStorage::allocNewVertexSpace()
{
	if (vertices_num < allocated_vertices_num + 1)
	{
		Vertex* new_vertices_memory = (Vertex*)malloc(size_of_vertex * (allocated_vertices_num + grow_by));

		if (vertices)
		{
			memcpy((BYTE*)new_vertices_memory, vertices, allocated_vertices_num * size_of_vertex);
			free(vertices);
		}
		vertices = new_vertices_memory;
		allocated_vertices_num += grow_by;
	}

	return vertices + vertices_num++;

}
