
#ifndef __VERTICES_LIST_H__
#define __VERTICES_LIST_H__

class VerticesListBase
{
protected:
	void* vertices_data;
	uint total_vertices_num;
	uint shader_id;

public:
	virtual ~VerticesListBase();
	
	uint getTotalVerticesNum();
	void* getVerticesListPointer();
	void reset();
};

template<typename T, uint SHADER_ID>
class VerticesList : public VerticesListBase
{

public:
	VerticesList();
	~VerticesList();
	void addNewVertexToList(const T* vertex);
	void addNewVerticesToList(const T* vertices, uint vertices_num);
};

#endif
