
#pragma once

class DLL_INTERFACE VertexStorage
{
	static const unsigned int size_of_vertex;
	Vertex* vertices;
	unsigned int vertices_num;
	unsigned int allocated_vertices_num;

	unsigned int grow_by;

	Vertex* allocNewVertexSpace();

public:
	VertexStorage(unsigned int grow_by = 8);
	~VertexStorage();

	Vertex* newVertex();
	void newVertex(Vertex* vertex);
	void newVertex(float x, float y, float z, float r, float g, float b);

	Vertex* getData()
	{
		return this->vertices;
	}

	unsigned int getVerticesNum()
	{
		return this->vertices_num;
	}

	unsigned int getAllocatedVerticesNum()
	{
		return this->allocated_vertices_num;
	}

	void changeGrowBy(unsigned int grow_by)
	{
		this->grow_by = grow_by;
	}
};
