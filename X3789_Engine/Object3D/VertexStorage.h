
#pragma once

class DLL_INTERFACE VertexStorage
{
	static const unsigned int size_of_vertex;
	VertexData* vertices;
	VertexData* colors;
	unsigned int vertices_num;
	unsigned int allocated_vertices_num;

	unsigned int grow_by;

	VertexData* allocNewVertexSpace();

public:
	VertexStorage(unsigned int grow_by = 8);
	~VertexStorage();

	//Vertex* newVertex();
	//void newVertex(Vertex* vertex);
	void newVertex(float x, float y, float z, float r, float g, float b);

	VertexData* getVerticesData()
	{
		return this->vertices;
	}

	VertexData* getVerticesColorData()
	{
		return this->colors;
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

	unsigned int getVerticesTotalSize()
	{
		return this->vertices_num * this->size_of_vertex;
	}
};
