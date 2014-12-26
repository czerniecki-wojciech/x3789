
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
#define CUBE_SIZE_2 0.5f

//Render_METOD
//#define X3789_RENDER_VAO
//#define X3789_RENDER_VAO_GEOMETRY
#define X3789_RENDER_VBO_GEOMETRY
//#define X3789_RENDER_VBO_TRIANGLE
//#define X3789_RENDER_VBO_TRI_STRIP

//Cube surface mode
#define X3789_SURFACE_MODE_COLOR
//#define X3789_SURFACE_MODE_TEXTURE

//#define VSYNC
#ifndef VSYNC
#	define VSYNC_ENABLED 0
#else
#	define VSYNC_ENABLED 1
#endif

#ifdef _DEBUG
#	define DebugBreak __debugbreak
#else
#	define DebugBreak
#endif

enum Shader
{
	X3789_SHADER_DEFAULT_SOLID		= 0x00,
	X3789_SHADER_DEFAULT_TEXTURED		= 0x01,
	X3789_SHADER_GEOMETRY_CUBE		= 0x02,

	SHADER_TOTAL_NUM
};

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

#ifdef _DEBUG
#	define GL_ERROR GL_ERROR_IMP()
#else
#	define GL_ERROR
#endif

static void GL_ERROR_IMP()
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