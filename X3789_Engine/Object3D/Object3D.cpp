
#include "stdafx.h"
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\WindowInterface.h>
#include <X3789_Engine\Common\ControlInterface.h>
#include <X3789_Engine\Common\TextureStorage.h>
#include "VertexStorage.h"
#include "UniformStorage.h"
#include "Object3D.h"


Object3D::Object3D()
	: primitive_type(GL_TRIANGLES)
	, vertices(NULL)
	, uniforms(NULL)
	, shader(-1)
{}


Object3D::~Object3D()
{}

void Object3D::loadVertexToGPU()
{
	if (!vertices)
		return;

	GLint posAttrib[2];

	posAttrib[0] = glGetAttribLocation(shader, "vertex_position_modelspace");
	glEnableVertexAttribArray(posAttrib[0]);						   GL_ERROR();
	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);	   GL_ERROR();
	glVertexAttribPointer(
		posAttrib[0],                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,									// size (how many floats define vertex)
		GL_FLOAT,							// type
		GL_FALSE,							// normalized?
		0,									// stride
		(void*)0							// array buffer offset
		);	GL_ERROR();

	posAttrib[1] = glGetAttribLocation(shader, "inColor");
	glEnableVertexAttribArray(posAttrib[1]);						   GL_ERROR();
	glBindBuffer(GL_ARRAY_BUFFER, this->color_buffer);	   GL_ERROR();
	glVertexAttribPointer(
		posAttrib[1],                  // attribute 0. No particular reason for 0, but must atch the layout in the shader.
		3,									// size (how many floats define vertex)
		GL_FLOAT,							// type
		GL_FALSE,							// normalized?
		0,									// stride
		(void*)0							// array buffer offset
		);	GL_ERROR();
#if (defined(VBO))

#endif
#ifndef GEOMETRY_CUBE
	glDrawArrays(GL_TRIANGLES, 0, this->vertices->getVerticesNum());	GL_ERROR();
#else
	glDrawArrays(GL_POINTS, 0, this->vertices->getVerticesNum());	GL_ERROR();
#endif
	glDisableVertexAttribArray(posAttrib[0]);	GL_ERROR();
	glDisableVertexAttribArray(posAttrib[1]);	GL_ERROR();
}

inline void Object3D::loadStandarUniformsToGPU()
{
	glUniformMatrix4fv(mvp_id, 1, GL_FALSE, ControlInterface::getMVPData());
	glUniform3fv(object_position_id, 1, glm::value_ptr(position));
}

inline void Object3D::loadExtraUniformsToGPU()
{
	if (uniforms)
		this->uniforms->loadToGPU(this->shader);

	if (checkShader(X3789_SHADER_DEFAULT_TEXTURED))
	{
		TextureStorage::useTexture(TEXTURE_TEST, this->shader);
	}
}

inline void Object3D::draw(bool reload_uniforms)
{
	if (reload_uniforms)
	{
		glUseProgram(this->shader);
		loadExtraUniformsToGPU();
	}

	loadStandarUniformsToGPU();
	loadVertexToGPU();
}

void Object3D::endObjectDefinition()
{
	if (shader == -1)
		this->setShader(X3789_SHADER_DEFAULT_SOLID);

	glGenBuffers(1, &this->vertex_buffer);						GL_ERROR();

	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);			GL_ERROR();
	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesTotalSize(), this->vertices->getVerticesData(), GL_STATIC_DRAW);		GL_ERROR();

	glGenBuffers(1, &this->color_buffer);						GL_ERROR();

	glBindBuffer(GL_ARRAY_BUFFER, this->color_buffer);			GL_ERROR();
	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesTotalSize(), this->vertices->getVerticesColorData(), GL_STATIC_DRAW);		GL_ERROR();
}
