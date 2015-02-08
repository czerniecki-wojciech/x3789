
#include "stdafx.h"
#include "X3789_Engine_Common.h"
#include "VerticesList.h"

VerticesListBase::~VerticesListBase()
{
	free(vertices_data);
}

void* VerticesListBase::getVerticesListPointer()
{
	return vertices_data;
}

void VerticesListBase::reset()
{
	total_vertices_num = 0;
}

uint VerticesListBase::getTotalVerticesNum()
{
	return total_vertices_num;
}

template<typename T, uint SHADER_ID>
VerticesList<T, SHADER_ID>::VerticesList()
{
	total_vertices_num = 0;
	shader_id = SHADER_ID;
	vertices_list = (void*)malloc(sizeof(T) * MAX_VERTICES_ON_LIST);
}


template<typename T, uint SHADER_ID>
void VerticesList<T, SHADER_ID>::addNewVertexToList(const T* vertex)
{
	memcpy(vertices_data + total_vertices_num * sizeof(T), vertex, sizeof(T));
	++total_vertices_num;
	
	if (total_vertices_num >= MAX_VERTICES_ON_LIST)
		X3789_DEBUG_BREAK;
}

template<typename T, uint SHADER_ID>
void VerticesList<T, SHADER_ID>::addNewVerticesToList(const T* vertices, uint vertices_num)
{
	memcpy(vertices_data + total_vertices_num * sizeof(T), vertices, vertices_num * sizeof(T));
	total_vertices_num += vertices_num;
}
