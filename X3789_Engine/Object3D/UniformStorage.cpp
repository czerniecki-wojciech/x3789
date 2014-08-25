#include "stdafx.h"
#include "UniformStorage.h"


UniformStorage::UniformStorage()
	: uniforms_num(0)
	, uniforms_memory(NULL)
{
}


UniformStorage::~UniformStorage()
{
	if (this->uniforms_memory)
		free(uniforms_memory);
}


void UniformStorage::loadToGPU(GLuint program_id)
{
	if (!this->uniforms_memory)
		return;

	int current_uniform_num = 0;
	Uniform* current_uniform = (Uniform*)this->uniforms_memory;

	GLuint uniform_id;

	while (current_uniform_num < this->uniforms_num)
	{
		uniform_id = glGetUniformLocation(program_id, current_uniform->name);
		
		switch (current_uniform->type)
		{
		case GL_FLOAT:
			glUniform1fv(uniform_id, 1, current_uniform->data);
			break;
		case GL_FLOAT_VEC2:
			glUniform2fv(uniform_id, 1, current_uniform->data);
			break;
		case GL_FLOAT_VEC3:
			glUniform3fv(uniform_id, 1, current_uniform->data);
			break;
		case GL_FLOAT_VEC4:
			glUniform4fv(uniform_id, 1, current_uniform->data);
			break;
		case GL_FLOAT_MAT2:
			glUniformMatrix2fv(uniform_id, 1, GL_FALSE, current_uniform->data);
			break;
		case GL_FLOAT_MAT3:
			glUniformMatrix3fv(uniform_id, 1, GL_FALSE, current_uniform->data);
			break;
		case GL_FLOAT_MAT4:
			glUniformMatrix4fv(uniform_id, 1, GL_FALSE, current_uniform->data);
			break;
		}

		current_uniform = (Uniform*)((BYTE*)current_uniform + current_uniform->total_size);
		current_uniform_num++;
	}
}
