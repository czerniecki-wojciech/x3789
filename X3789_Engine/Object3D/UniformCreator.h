
#pragma once

class DLL_INTERFACE UniformCreator
{
	BYTE* temp_memory;
	static const unsigned int size_of_uniform_base;
	static const unsigned int size_of_float;
	Uniform* current_uniform;
	unsigned int total_size;
	unsigned int uniforms_num;
public:
	UniformCreator();
	~UniformCreator();

	void begin_Structure();
	UniformStorage* end_structure();

	void add_float(char* name, float f0);
	void add_vector2(char* name, float f0, float f1);
	void add_vector3(char* name, float f0, float f1, float f2);
	void add_vector4(char* name, float f0, float f1, float f2, float f3);
	void add_matrix2(char* name, float f0, float f1, float f2, float f3);
	void add_matrix3(char* name, float* data);
	void add_matrix4(char* name, float* data);
};

