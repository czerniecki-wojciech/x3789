
#include "stdafx.h"
#include "UniformStorage.h"
#include "UniformCreator.h"

const unsigned int UniformCreator::size_of_uniform_base = sizeof(UniformBase);
const unsigned int UniformCreator::size_of_float = sizeof(float);

UniformCreator::UniformCreator()
{
	//304
    temp_memory = (BYTE*)malloc(4 * (size_of_uniform_base + 16 * size_of_float);
}


UniformCreator::~UniformCreator()
{
	if (this->temp_memory)
		free(temp_memory);
}

void UniformCreator::begin_Structure()
{
	this->current_uniform = (Uniform*)temp_memory;
	this->total_size = 0;
}

UniformStorage* UniformCreator::end_structure()
{
	UniformStorage* us = new UniformStorage();

	BYTE* fixed_memory = (BYTE*)malloc(this->total_size);
	memcpy(fixed_memory, this->temp_memory, this->total_size);

	us->setUniformMemory(fixed_memory);
	us->uniforms_num = this->uniforms_num;

	this->uniforms_num = 0;
	free(this->temp_memory);
	this->temp_memory = NULL;

	return us;
}

void UniformCreator::add_float(char* name, float f0)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + size_of_float;
	this->current_uniform->type = GL_FLOAT;
	this->current_uniform->data[0] = f0;
	
	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}

void UniformCreator::add_vector2(char* name, float f0, float f1)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + 2 * size_of_float;
	this->current_uniform->type = GL_FLOAT_VEC2;
	this->current_uniform->data[0] = f0;
	this->current_uniform->data[1] = f1;

	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}

void UniformCreator::add_vector3(char* name, float f0, float f1, float f2)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + 3 * size_of_float;
	this->current_uniform->type = GL_FLOAT_VEC3;
	this->current_uniform->data[0] = f0;
	this->current_uniform->data[1] = f1;
	this->current_uniform->data[2] = f2;

	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}

void UniformCreator::add_vector4(char* name, float f0, float f1, float f2, float f3)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + 4 * size_of_float;
	this->current_uniform->type = GL_FLOAT_VEC4;
	this->current_uniform->data[0] = f0;
	this->current_uniform->data[1] = f1;
	this->current_uniform->data[2] = f2;
	this->current_uniform->data[3] = f3;

	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}

void UniformCreator::add_matrix2(char* name, float f0, float f1, float f2, float f3)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + 4 * size_of_float;
	this->current_uniform->type = GL_FLOAT_MAT2;
	this->current_uniform->data[0] = f0;
	this->current_uniform->data[1] = f1;
	this->current_uniform->data[2] = f2;
	this->current_uniform->data[3] = f3;

	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}

void UniformCreator::add_matrix3(char* name, float* data)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + 9 * size_of_float;
	this->current_uniform->type = GL_FLOAT_MAT3;

	memcpy(this->current_uniform->data, data, 9 * size_of_float);

	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}

void UniformCreator::add_matrix4(char* name, float* data)
{
	this->current_uniform->name = name;
	this->current_uniform->total_size = size_of_uniform_base + 16 * size_of_float;
	this->current_uniform->type = GL_FLOAT_MAT4;

	memcpy(this->current_uniform->data, data, 16 * size_of_float);

	this->total_size += this->current_uniform->total_size;
	this->current_uniform = (Uniform*)((BYTE*)this->current_uniform + this->current_uniform->total_size);
	this->uniforms_num++;
}
