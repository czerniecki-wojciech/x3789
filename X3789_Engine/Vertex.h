
#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex_Base
{
public:
	float x;
	float y;
	float z;

	Vertex_Base(float x, float y, float z);
};

class Vertex_RGB : public Vertex_Base
{
public:
	float r;
	float g;
	float b;

	Vertex_RGB(float x, float y, float z, float red, float green, float blue);
};

class Vertex_RGBA : public Vertex_RGB
{
public:
	float a;

	Vertex_RGBA(float x, float y, float z, float red, float green, float blue, float alpha);
};

class Vertex_Textured : public Vertex_Base
{
public:
	float u;
	float v;

	Vertex_Textured(float x, float y, float z, float u, float v);
};

#endif
