
#include "Vertex.h"

Vertex_Base::Vertex_Base(float x, float y, float z)
	: x(x)
	, y(y)
	, z(z)
{
}

Vertex_RGB::Vertex_RGB(float x, float y, float z, float red, float green, float blue)
	: r(red)
	, g(green)
	, b(blue)
	, Vertex_Base(x, y, z)
{
}

Vertex_RGBA::Vertex_RGBA(float x, float y, float z, float red, float green, float blue, float alpha)
	: a(alpha)
	, Vertex_RGB(x, y, z, red, green, blue)
{
}

Vertex_Textured::Vertex_Textured(float x, float y, float z, float u, float v)
	: u(u)
	, v(v)
	, Vertex_Base(x, y, z)
{
}
