
#include "stdafx.h"
#include <X3789_Engine\WindowInterface.h>
#include <X3789_Engine\Common\ControlInterface.h>
#include "VertexStorage.h"
#include "UniformStorage.h"
#include "Object3D.h"


Object3D::Object3D()
	: program_ID(0)
	, primitive_type(GL_TRIANGLES)
	, vertices(NULL)
	, uniforms(NULL)
{}


Object3D::~Object3D()
{}

void Object3D::loadVertexToGPU()
{
	if (!vertices)
		return;


	glEnableVertexAttribArray(0);						   GL_ERROR();
	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);	   GL_ERROR();
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,									// size (how many floats define vertex)
		GL_FLOAT,							// type
		GL_FALSE,							// normalized?
		0,									// stride
		(void*)0							// array buffer offset
		);	GL_ERROR();

	
	glEnableVertexAttribArray(1);						   GL_ERROR();
	glBindBuffer(GL_ARRAY_BUFFER, this->color_buffer);	   GL_ERROR();
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,									// size (how many floats define vertex)
		GL_FLOAT,							// type
		GL_FALSE,							// normalized?
		0,									// stride
		(void*)0							// array buffer offset
		);	GL_ERROR();
	
	glDrawArrays(GL_TRIANGLES, 0, this->vertices->getVerticesNum());	GL_ERROR();

	glDisableVertexAttribArray(0);	GL_ERROR();
	glDisableVertexAttribArray(1);	GL_ERROR();
}

inline void Object3D::loadUniformsToGPU()
{
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, ControlInterface::getMVPData());
	glUniform3fv(object_position_id, 1, glm::value_ptr(position));

	if (uniforms)
		this->uniforms->loadToGPU(this->program_ID);
}

inline void Object3D::draw()
{
	if (this->program_ID)
		glUseProgram(this->program_ID);

	loadUniformsToGPU();

	loadVertexToGPU();

}

void Object3D::endObjectDefinition()
{
	glGenBuffers(1, &this->vertex_buffer);						GL_ERROR();

	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);			GL_ERROR();
	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesTotalSize(), this->vertices->getVerticesData(), GL_STATIC_DRAW);		GL_ERROR();

	glGenBuffers(1, &this->color_buffer);						GL_ERROR();

	glBindBuffer(GL_ARRAY_BUFFER, this->color_buffer);			GL_ERROR();
	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesTotalSize(), this->vertices->getVerticesColorData(), GL_STATIC_DRAW);		GL_ERROR();
}
