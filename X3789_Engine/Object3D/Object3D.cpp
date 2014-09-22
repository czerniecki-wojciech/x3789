
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
	, indices(NULL)
	, uniforms(NULL)
	, shader(-1)
{}


Object3D::~Object3D()
{}

void Object3D::loadVertexToGPU()
{
	if (!vertices)
		return;

#if defined(X3789_RENDER_VBO_TRI_STRIP)
	if (!indices)
		return;
#endif

#if (defined(X3789_RENDER_VAO) || defined(X3789_RENDER_VAO_GEOMETRY))
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
#endif

#if (defined(X3789_RENDER_VBO_TRI_STRIP))
	GLuint id = 999;
	id = glGetAttribLocation(shader, "vertex_position_modelspace"); GL_ERROR();

	glEnableVertexAttribArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer); GL_ERROR();
	glVertexAttribPointer(id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); GL_ERROR();

	id = glGetAttribLocation(shader, "inColor"); GL_ERROR();
	glEnableVertexAttribArray(id);
	glBindBufferARB(GL_ARRAY_BUFFER, color_buffer); GL_ERROR();
	glVertexAttribPointerARB(id, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); GL_ERROR();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer); GL_ERROR();

	glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_SHORT, (void*)0); GL_ERROR();
#endif
#if(defined(X3789_RENDER_VAO))
	glDrawArrays(GL_TRIANGLES, 0, this->vertices->getVerticesNum());	GL_ERROR();
	glDisableVertexAttribArray(posAttrib[0]);	GL_ERROR();
	glDisableVertexAttribArray(posAttrib[1]);	GL_ERROR();
#endif
#if(defined(X3789_RENDER_VAO_GEOMETRY))
	glDrawArrays(GL_POINTS, 0, this->vertices->getVerticesNum());	GL_ERROR();
#endif
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

	glGenBuffers(1, &this->vertex_buffer);						GL_ERROR;

	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);			GL_ERROR;
	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesTotalSize(), this->vertices->getVerticesData(), GL_STATIC_DRAW);		GL_ERROR;

	glGenBuffers(1, &this->color_buffer);						GL_ERROR;

	glBindBuffer(GL_ARRAY_BUFFER, this->color_buffer);			GL_ERROR;
	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesTotalSize(), this->vertices->getVerticesColorData(), GL_STATIC_DRAW);		GL_ERROR;

#if( defined(X3789_RENDER_VBO_TRI_STRIP))
	glGenBuffers(1, &this->indices_buffer);						GL_ERROR;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices_buffer);			GL_ERROR;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 14 * sizeof(GLushort), this->indices, GL_STATIC_DRAW);		GL_ERROR;

	/*
	printf("indices = ");
	for (int i = 0; i < 14; ++i)
	{
		printf("%d, ", indices[i]);
	}
	printf("\n");

	for (int i = 0; i < 8; i++)
	{
		VertexData* vd = vertices->getVerticesData();
		float* pos = vd[i].data;
		vd = vertices->getVerticesColorData();
		float* color = vd[i].data;
		printf("vertex[%d] = { %f, %f, %f, %f, %f, %f}\n", i, pos[0], pos[1], pos[2], color[0], color[1], color[2]);
	}
	*/
#endif
}
