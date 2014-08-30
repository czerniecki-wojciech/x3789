
#pragma once

class DLL_INTERFACE ShaderInterface
{
private:
	static ShaderInterface* instance;
	GLuint shaders_id[2];
	ShaderInterface();

	void loadShaders();

public:
	static ShaderInterface* getInstance()
	{
		if (!instance)
			instance = new ShaderInterface();
		return instance;
	}

	GLuint getShader(unsigned short shader_name)
	{
		return shaders_id[shader_name];
	}

	~ShaderInterface();
};

