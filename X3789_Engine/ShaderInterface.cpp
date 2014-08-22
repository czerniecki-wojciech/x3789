
#include "stdafx.h"

#include "Shaders\ShaderLoader.h"

#include "ShaderInterface.h"

ShaderInterface* ShaderInterface::instance = NULL;

ShaderInterface::ShaderInterface()
{}

ShaderInterface::~ShaderInterface()
{}

GLuint ShaderInterface::loadBasicShader()
{
	return ShaderLoader::loadShader("Shaders/SimpleVertexShader.vertexshader", "Shaders/SimpleFragmentShader.fragmentshader");
}
