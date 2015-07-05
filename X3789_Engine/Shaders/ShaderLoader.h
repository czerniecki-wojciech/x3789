
#pragma once

class DLL_INTERFACE ShaderLoader
{
public:
	ShaderLoader(){}
	static GLuint loadShader(const char * vertex_file_path, const char * fragment_file_path);
	
	static GLuint createShader();
	static bool combineWithShaderFile(GLuint shader_id, const char* file_path, GLuint shader_type);
	static bool linkShader(GLuint shader_id);
};
