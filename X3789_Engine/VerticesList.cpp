
#include "stdafx.h"
#include "X3789_Engine_Common.h"
#include "VerticesList.h"

template<typename T, uint SHADER_ID>
VerticesList<T, SHADER_ID>::VerticesList()
	: shader_id(SHADER_ID)
	, total_vertices_num(0)
{
	vertices_list = (T*)malloc(sizeof(T) * MAX_VERTICES_ON_LIST);
}

template<typename T, uint SHADER_ID>
VerticesList<T, SHADER_ID>::~VerticesList()
{
	free(vertices_list);
}

template<typename T, uint SHADER_ID>
T* VerticesList<T, SHADER_ID>::getVerticesListPointer()
{
	return vertices_list;
}

template<typename T, uint SHADER_ID>
void VerticesList<T, SHADER_ID>::addNewVertexToList(const T* vertex)
{
	memcpy(vertices_list + total_vertices_num * sizeof(T), vertex, sizeof(T));
	++total_vertices_num;
}

template<typename T, uint SHADER_ID>
void VerticesList<T, SHADER_ID>::addNewVerticesToList(const T* vertices, uint vertices_num)
{
	memcpy(vertices_list + total_vertices_num * sizeof(T), vertices, vertices_num * sizeof(T));
	total_vertices_num += vertices_num;
	
	if (total_vertices_num >= MAX_VERTICES_ON_LIST)
		X3789_DEBUG_BREAK;
}

template<typename T, uint SHADER_ID>
void VerticesList<T, SHADER_ID>::reset()
{
	total_vertices_num = 0;
}

template<typename T, uint SHADER_ID>
uint VerticesList<T, SHADER_ID>::getTotalVerticesNum()
{
	return shader_id;
}
