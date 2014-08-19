#pragma once

#define MAX_VERTEX_ATTRIBS 8

class DrawGroup
{
	VertexAttrib* vertex_attribs[MAX_VERTEX_ATTRIBS];
	unsigned int vertex_attrib_num;
	TextureStorage texture_storage;
	GLuint program_ID;

	unsigned int internal_iterator;

	void realaseBuffers();
public:
	DrawGroup()
		: vertex_attrib_num(0)
		, program_ID(0)
		, internal_iterator(0)
	{}

	~DrawGroup()
	{
		for (int i = 0; i < vertex_attrib_num; i++)
			vertex_attribs[i]->~VertexAttrib();
	}

	void setProgram(GLuint program_ID)
	{
		this->program_ID = program_ID;
	}

	void draw();
	void addTexture(char* filename, char* sampler_name);
	void addVertexAttrib(VertexAttrib* new_va);
};

