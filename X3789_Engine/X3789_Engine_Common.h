
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
	//glm::vec3 color;
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

static void GL_ERROR()
{
	switch (glGetError())
	{
	//case GL_NO_ERROR:						printf("GL_NO_ERROR						\n"); break;
	case GL_INVALID_ENUM:					printf("GL_INVALID_ENUM					\n"); break;
	case GL_INVALID_VALUE:					printf("GL_INVALID_VALUE				\n"); break;
	case GL_INVALID_OPERATION:				printf("GL_INVALID_OPERATION			\n"); break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:	printf("GL_INVALID_FRAMEBUFFER_OPERATION\n"); break;
	case GL_OUT_OF_MEMORY:					printf("GL_OUT_OF_MEMORY				\n"); break;
	case GL_STACK_UNDERFLOW:				printf("GL_STACK_UNDERFLOW				\n"); break;
	case GL_STACK_OVERFLOW:					printf("GL_STACK_OVERFLOW				\n"); break;
	}
}