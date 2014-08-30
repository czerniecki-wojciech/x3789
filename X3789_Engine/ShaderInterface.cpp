
#include "stdafx.h"

#include "Shaders\ShaderLoader.h"

#include "ShaderInterface.h"

ShaderInterface* ShaderInterface::instance = NULL;

ShaderInterface::ShaderInterface()
{
	this->loadShaders();
}

ShaderInterface::~ShaderInterface()
{}

void ShaderInterface::loadShaders()
{
	shaders_id[SHADER_DEFAULT_SOLID] =  ShaderLoader::loadShader("Shaders/SimpleVertexShader.vertexshader", "Shaders/SimpleFragmentShader.fragmentshader");

	//shaders_id[SHADER_DEFAULT_TEXTURED] = ShaderLoader::loadShader("Shaders/TextureVertexShader.vertexshader", "Shaders/TextureFragmentShader.fragmentshader");
}
