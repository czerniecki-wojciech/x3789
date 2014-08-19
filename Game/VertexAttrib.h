#pragma once
class VertexAttrib
{
private:
	GLfloat* data;
	unsigned int size;
	unsigned int internal_index;
	GLuint buffer_ID;
public:
	VertexAttrib(unsigned int size)
		: internal_index(0)
		, buffer_ID(0)
	{
		this->size = size;
		data = new GLfloat[size];
	}
	~VertexAttrib()
	{
		if(data)
			delete[] data;
		data = 0;
	}

	float* operator[](unsigned int index) const;
	
	inline void addValue(float value)
	{
		data[internal_index++] = value;
	}

	inline void setInternalIndex(unsigned int value)
	{
		internal_index = value;
	}

	void copyDataToGPU(unsigned int latout_index);
};

