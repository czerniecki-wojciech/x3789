#include <vector>
#include "vertexcollector.h"

template<typename T>
VertexCollector<T>::VertexCollector()
{}

template<typename T>
void VertexCollector<T>::addVertex(T new_one)
{
    vertices.push_back(new_one);
}

template<typename T>
void VertexCollector<T>::addVertices(T *new_ones, uint num)
{
    for(uint i=0; i<num; ++i)
    {
        vertices.push_back(new_ones[i]);
    }
}

template<typename T>
inline void VertexCollector<T>::clear()
{
    vertices.clear();
}

template<typename T>
uint VertexCollector<T>::getVerticesNum()
{
    return vertices.size();
}

template<typename T>
T* VertexCollector<T>::getVertexPointer()
{
    return vertices.data();
}
