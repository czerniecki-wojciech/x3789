cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(X3789_Engine)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(-DSYSTEM_LINUX)
endif()

FILE(GLOB_RECURSE X3789_Engine_SRC "*.cpp" "*.h")

MESSAGE("Creating X3789_Engine...")

add_definitions(-DX3789_ENGINE_EXPORT -D_CRT_SECURE_NO_WARNINGS)

add_library(X3789_Engine SHARED ${X3789_Engine_SRC})

include_directories(
	.
	..
	../Common
	./Shaders
	)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	find_library(GLEW_LIB GLEW ${LIB_DIR})
	find_library(GLFW3_LIB glfw3 ${LIB_DIR})
	find_library(OPENGLU_LIB GLU ${LIB_DIR})
	find_library(OPENGL_LIB GL ${LIB_DIR})
	find_library(X11_LIB X11)
	find_library(XXF86VM_LIB Xxf86vm)
	find_library(XRANDR_LIB Xrandr)
	find_library(MATH_LIB m)
	find_library(XI_LIB Xi)
	
	target_link_libraries(X3789_Engine
		${GLEW_LIB}
		${GLFW3_LIB}
		${OPENGL_LIB}
		${OPENGLU_LIB}
		${X11_LIB}
		${XRANDR_LIB}
		${XXF86VM_LIB}
		${MATH_LIB}
		${XI_LIB}
	)

	add_definitions(-std=c++11 -g)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	find_library(GLEW_LIB glew32 ${LIB_DIR})
	find_library(GLFW3_LIB glfw3dll ${LIB_DIR})
	find_library(OPENGL_LIB opengl32 ${LIB_DIR})
	
	target_link_libraries(X3789_Engine
		${GLEW_LIB}
		${GLFW3_LIB}
		${OPENGL_LIB}
	)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

MESSAGE(STATUS "GLEW_LIB: " ${GLEW_LIB})
MESSAGE(STATUS "GLFW3_LIB: " ${GLFW3_LIB})
MESSAGE(STATUS "OPENGL_LIB: " ${OPENGL_LIB})

