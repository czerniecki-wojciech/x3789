
#ifndef __VERTEX_QUEUE_H__
#define __VERTEX_QUEUE_H__

template<typename T, uint programID>
class VertexQueue
{
private:
	//static VertexQueue* instance;

	T* vertices;
	unsigned int vertices_num;

	VertexQueue();

public:
	~VertexQueue();

	static VertexQueue<T, programID>* getQueue();
	void addVertex(T);
	void reset();

	const T* getVerticesPointer();

	static const uint Max_Vertex_Num = 1000;
};

template<typename T, uint programID>
VertexQueue<T, programID>* VertexQueue<T, programID>::getQueue()
{
	/*if (instance)
		return instance;

	instance = new VertexData<T, programID>();
	return instance;*/
	return 0;
}

#endif
