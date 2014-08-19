#include "stdafx.h"
#include "VertexAttrib.h"


float* VertexAttrib::operator[] (unsigned int index) const
{
	if (index >= size)
		return data;
	return &data[index];
}

void VertexAttrib::copyDataToGPU(unsigned int layout_index)
{
	if (!buffer_ID)
	{
		glGenBuffers(1, &buffer_ID);
		glBindBuffer(GL_ARRAY_BUFFER, buffer_ID);
	}
		
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(layout_index);
	glVertexAttribPointer(
		layout_index,
		size,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);
}