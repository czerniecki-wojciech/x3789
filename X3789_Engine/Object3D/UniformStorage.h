
#pragma once

class DLL_INTERFACE UniformStorage
{
private:
	BYTE* uniforms_memory;
public:
	unsigned int uniforms_num;

	UniformStorage();
	~UniformStorage();

	void loadToGPU(GLuint program_id);

	void setUniformMemory(BYTE* memory)
	{
		this->uniforms_memory = memory;
	}
};

