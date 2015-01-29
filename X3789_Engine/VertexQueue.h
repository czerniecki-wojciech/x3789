
#ifndef __VERTEX_QUEUE_H__
#define __VERTEX_QUEUE_H__

template<typename T, uint SHADER_ID>
class VertexQueue
{
private:
	T* vertices_list;
	uint total_vertices_num;
	uint shader_id;

public:
	VertexQueue();
	~VertexQueue();

	T* getVerticesListPointer();
	void addNewVertexToList(const T* vertex);
	void addNewVerticesToList(const T* vertices, uint vertices_num);

	void reset();

	uint getTotalVerticesNum();
};

#endif
