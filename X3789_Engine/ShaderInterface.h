
#pragma once
#include "X3789_MACRO_VIEWER.h"
#include "Tools/Singleton.h"

//#pragma message(MACRO_VIEWER(DLL_INTERFACE))

class DLL_INTERFACE _ShaderInterface
{
private:
    GLuint shaders_id[SHADER_TOTAL_NUM];

    void loadShaders();

public:
    _ShaderInterface();

	GLuint getShader(Shader shader_name)
	{
		return shaders_id[shader_name];
	}

    ~_ShaderInterface();

    friend class Singleton<_ShaderInterface>;
};

typedef Singleton<_ShaderInterface> ShaderInterface;
