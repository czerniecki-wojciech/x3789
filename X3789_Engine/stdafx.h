// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
//#include <windows.h>

#ifdef WIN32
#include <Windows.h>
#endif

// TODO: reference additional headers your program requires here
#include <stdio.h>
#include <cstdlib>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp> 

//#define GLM_FORCE_RADIANS

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "X3789_Engine_Common.h"
#include "WindowHolder.h"

#pragma warning(disable: 4244)
#pragma warning(disable: 4251)
#pragma warning(disable: 4018)

typedef unsigned int uint;
typedef unsigned short ushort;

#ifndef BOOL
	typedef bool BOOL;
	typedef char BYTE;
#endif
