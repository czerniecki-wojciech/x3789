
#pragma once

#ifdef X3789_ENGINE_EXPORT
#	define DLL_INTERFACE __declspec(dllexport)
#	define EXT extern "C"
#else
#	define DLL_INTERFACE __declspec(dllimport)
#	define EXT
#endif

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
};

struct UniformBase
{
	char* name;
	GLenum type;
	GLsizei total_size;
};

struct Uniform : public UniformBase
{
	float data[16];
};