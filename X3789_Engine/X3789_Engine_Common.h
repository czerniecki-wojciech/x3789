
#pragma once

#ifdef X3789_ENGINE_EXPORT
#	define DLL_INTERFACE __declspec(dllexport)
#	define EXT extern "C"
#else
#	define DLL_INTERFACE __declspec(dllimport)
#	define EXT
#endif

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define CUBE_SIZE 1.0f

enum Shader
{
	SHADER_DEFAULT_SOLID		= 0x00,
	SHADER_DEFAULT_TEXTURED		= 0x01,

	SHADER_TOTAL_NUM
};

//#define VSYNC
#ifndef VSYNC
#	define VSYNC_ENABLED 0
#else
#	define VSYNC_ENABLED 1
#endif

enum Texture
{
	TEXTURE_TEST = 0,
	TEXTURE_SKY,

	TOTAL_TEXTURE_NUM
};

struct VertexData
{
	float data[3];
};

struct ColorData : public VertexData
{};

struct UVData : public VertexData
{};

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
	/*case GL_NO_ERROR:						
		printf("GL_NO_ERROR						\n");
		break;*/
	case GL_INVALID_ENUM:					
		printf("GL_INVALID_ENUM					\n");
		__debugbreak();
		break;
	case GL_INVALID_VALUE:					
		printf("GL_INVALID_VALUE				\n");
		__debugbreak();
		break;
	case GL_INVALID_OPERATION:				
		printf("GL_INVALID_OPERATION			\n");
		__debugbreak();
		break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:	
		printf("GL_INVALID_FRAMEBUFFER_OPERATION\n");
		__debugbreak();
		break;
	case GL_OUT_OF_MEMORY:					
		printf("GL_OUT_OF_MEMORY				\n");
		__debugbreak();
		break;
	case GL_STACK_UNDERFLOW:				
		printf("GL_STACK_UNDERFLOW				\n");
		__debugbreak();
		break;
	case GL_STACK_OVERFLOW:					
		printf("GL_STACK_OVERFLOW				\n");
		__debugbreak();
		break;
	}
}