
#pragma once

#ifdef __linux
#	define DLL_EXPORT __attribute__ ((visibility("default")))
#	define DLL_IMPORT __attribute__ ((visibility("default")))
#else
#	define DLL_EXPORT __declspec(dllexport)
#	define DLL_IMPORT __declspec(dllimport)
#endif

#ifdef X3789_ENGINE_EXPORT
#	define DLL_INTERFACE DLL_EXPORT
#	define EXT extern "C"
#else
#	define DLL_INTERFACE DLL_IMPORT
#	define EXT
#endif

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

#ifdef SYSTEM_LINUX
#	define X3789_DEBUG_BREAK
#else
#	define X3789_DEBUG_BREAK	__debugbreak()
#endif

#ifdef _DEBUG
#	define DebugBreak X3789_DEBUG_BREAK
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
		DebugBreak;
		break;
	case GL_INVALID_VALUE:					
		printf("GL_INVALID_VALUE				\n");
		DebugBreak;
		break;
	case GL_INVALID_OPERATION:				
		printf("GL_INVALID_OPERATION			\n");
		DebugBreak;
		break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:	
		printf("GL_INVALID_FRAMEBUFFER_OPERATION\n");
		DebugBreak;
		break;
	case GL_OUT_OF_MEMORY:					
		printf("GL_OUT_OF_MEMORY				\n");
		DebugBreak;
		break;
	case GL_STACK_UNDERFLOW:				
		printf("GL_STACK_UNDERFLOW				\n");
		DebugBreak;
		break;
	case GL_STACK_OVERFLOW:					
		printf("GL_STACK_OVERFLOW				\n");
		DebugBreak;
		break;
	}
}

typedef unsigned int uint;
typedef unsigned short ushort;

#ifdef __linux
    typedef bool BOOL;
    typedef char BYTE;
#endif


const uint SCREEN_WIDTH = 640;
const uint SCREEN_HEIGHT = 480;

const float CUBE_SIZE = 1.0f;
const float CUBE_SIZE_2 = 0.5f;

const uint MAX_VERTICES_ON_LIST = 36000; //10 * 10 * 10 *36
