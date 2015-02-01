cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set(LIB_DIR ${LIB_DIR} ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

MESSAGE("LIB_DIR: " ${LIB_DIR})

add_definitions(-DGLM_FORCE_RADIANS)

add_subdirectory(X3789_Engine)

project("X3789")

file(GLOB GAME_SRC "Game/*.cpp")

add_executable(X3789 ${GAME_SRC})

include_directories(
	.
	./Common
	..
	)

find_library(GLFW3DLL_LIB glfw3dll ${LIB_DIR})
	
target_link_libraries(X3789
	X3789_Engine
	${GLFW3_LIB}
	)
	
file(GLOB SHADERS "external_files/Shaders/*")
file(GLOB TEXTURES "external_files/Textures/*")
file(GLOB DLLS "external_files/*")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    file(COPY ${SHADERS} DESTINATION ${CMAKE_BINARY_DIR}/bin/Shaders)
    file(COPY ${TEXTURES} DESTINATION ${CMAKE_BINARY_DIR}/bin/Textures)
    file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR}/bin)
	add_definitions(-std=c++11 -g)
else()
    file(COPY ${SHADERS} DESTINATION ${CMAKE_BINARY_DIR}/bin/Debug/Shaders)
    file(COPY ${TEXTURES} DESTINATION ${CMAKE_BINARY_DIR}/bin/Debug/Textures)
    file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR}/bin/Debug)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()
