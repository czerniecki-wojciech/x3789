#ifndef VERTEXCOLLECTOR_H
#define VERTEXCOLLECTOR_H
typedef unsigned int uint;

template<typename T>
class VertexCollector
{
    std::vector<T> vertices;
public:
    VertexCollector();

    void addVertex(T new_one);
    void addVertices(T* new_ones, uint num);
    void clear();

    uint getVerticesNum();
    T* getVertexPointer();
};
#endif // VERTEXCOLLECTOR_H
