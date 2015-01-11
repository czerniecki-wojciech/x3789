cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(X3789_Engine)
FILE(GLOB_RECURSE X3789_Engine_SRC "*.cpp" "*.h")

add_definitions(-DX3789_ENGINE_EXPORT -D_CRT_SECURE_NO_WARNINGS)

add_library(X3789_Engine SHARED ${X3789_Engine_SRC})

include_directories(
	.
	..
	../Common
	)

find_library(GLEW32_LIB glew32 ${LIB_DIR})
find_library(GLFW3DLL_LIB glfw3dll ${LIB_DIR})
find_library(OPENGL32_LIB opengl32 ${LIB_DIR})

MESSAGE("GLEW32_LIB: " ${GLEW32_LIB})

target_link_libraries(X3789_Engine
	${GLEW32_LIB}
	${GLFW3DLL_LIB}
	${OPENGL32_LIB}
)