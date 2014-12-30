
#ifndef __VERTEX_QUEUE_H__
#define __VERTEX_QUEUE_H__

template<typename T>
class VertexQueue
{
private:
	static VertexQueue* instance = 0;

	T* vertices;
	unsigned int vertices_num;
	VertexQueue();

public:
	static VertexQueue<T>* getQueue();
	void addVertex(T)
	~VertexQueue();
};

template<typename T>
static VertexQueue<T>* VertexQueue<T>::getQueue(){
	if (instance)
		return instance;

	instance = new VertexData<T>();
	return instance;
}

#endif
