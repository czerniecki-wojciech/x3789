
#include "stdafx.h"

#include <ShaderLoader.h>

#include <ShaderInterface.h>

_ShaderInterface::_ShaderInterface()
{
	this->loadShaders();
}

_ShaderInterface::~_ShaderInterface()
{}

void _ShaderInterface::loadShaders()
{
	//shaders_id[SHADER_DEFAULT_SOLID] =  ShaderLoader::loadShader("Shaders/SimpleVertexShader.vertexshader", "Shaders/SimpleFragmentShader.fragmentshader");
	shaders_id[X3789_SHADER_DEFAULT_SOLID] = ShaderLoader::createShader();
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_DEFAULT_SOLID], "Shaders/SimpleFragmentShader.fragmentshader", GL_FRAGMENT_SHADER);
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_DEFAULT_SOLID], "Shaders/SimpleVertexShader.vertexshader", GL_VERTEX_SHADER);
	ShaderLoader::linkShader(shaders_id[X3789_SHADER_DEFAULT_SOLID]);

	shaders_id[X3789_SHADER_DEFAULT_TEXTURED] = ShaderLoader::createShader();
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_DEFAULT_TEXTURED], "Shaders/TexturePixelShader.pixelshader", GL_FRAGMENT_SHADER);
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_DEFAULT_TEXTURED], "Shaders/TextureVertexShader.vertexshader", GL_VERTEX_SHADER);
	ShaderLoader::linkShader(shaders_id[X3789_SHADER_DEFAULT_TEXTURED]);

	shaders_id[X3789_SHADER_GEOMETRY_CUBE] = ShaderLoader::createShader();
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_GEOMETRY_CUBE], "Shaders/GeometryCube.vs", GL_VERTEX_SHADER);
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_GEOMETRY_CUBE], "Shaders/GeometryCube.gs", GL_GEOMETRY_SHADER);
    ShaderLoader::combineWithShaderFile(shaders_id[X3789_SHADER_GEOMETRY_CUBE], "Shaders/GeometryCube.ps", GL_FRAGMENT_SHADER);
	ShaderLoader::linkShader(shaders_id[X3789_SHADER_GEOMETRY_CUBE]);


	//shaders_id[SHADER_DEFAULT_TEXTURED] = ShaderLoader::loadShader("Shaders/TextureVertexShader.vertexshader", "Shaders/TexturePixelShader.pixelshader");

	//shaders_id[SHADER_DEFAULT_TEXTURED] = ShaderLoader::loadShader("Shaders/TextureVertexShader.vertexshader", "Shaders/TextureFragmentShader.fragmentshader");
}
