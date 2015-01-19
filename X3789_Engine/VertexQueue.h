
#ifndef __VERTEX_QUEUE_H__
#define __VERTEX_QUEUE_H__

template<typename T, uint programID>
class VertexQueue
{
private:
	//static VertexQueue* instance;

	T* vertices;
	unsigned int vertices_num;
	
public:
	VertexQueue();
	~VertexQueue();

	void addVertex(T new_one);
	void reset();

	const T* getVerticesPointer();

	static const uint MAX_VERTICES_NUM = 1000;
};

template<typename T, uint programID>
VertexQueue<T, programID>::VertexQueue()
	: vertices_num(0)
{
	vertices = new T[MAX_VERTICES_NUM];
}


template<typename T, uint programID>
VertexQueue<T, programID>::~VertexQueue()
{
	delete[] vertices;
}

template<typename T, uint programID>
VertexQueue<T, programID>::reset()
{
	vertices_num = 0;
}

template<typename T, uint programID>
VertexQueue<T, programID>::addvertex(T new_one)
{
	vertices[vertices_num++] = new_one;
}

#endif
