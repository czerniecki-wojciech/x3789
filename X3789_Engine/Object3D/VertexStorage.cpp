
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
	vertex->data[0] = x;
	vertex->data[1] = y;
	vertex->data[2] = z;

	ColorData* color = (ColorData*)((BYTE*)this->colors + (vertices_num - 1) * size_of_vertex);
	color->data[0] = r;
	color->data[1] = g;
	color->data[2] = b;
}

VertexData* VertexStorage::allocNewVertexSpace()
{
	if (vertices_num + 1 > allocated_vertices_num)
	{
		VertexData* new_vertices_memory = (VertexData*)malloc(size_of_vertex * (allocated_vertices_num + grow_by));

		ColorData* new_vertices_color_memory = (ColorData*)malloc(size_of_vertex * (allocated_vertices_num + grow_by));

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
