
#pragma once

class DLL_INTERFACE ShaderInterface
{
private:
	static ShaderInterface* instance;

	ShaderInterface();

public:
	static ShaderInterface* getInstance()
	{
		if (!instance)
			instance = new ShaderInterface();
		return instance;
	}

	GLuint loadBasicShader();

	~ShaderInterface();
};

