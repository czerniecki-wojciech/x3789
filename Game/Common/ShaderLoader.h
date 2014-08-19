
#pragma once

class ShaderLoader
{
public:
	ShaderLoader(){}
	static GLuint loadShader(const char * vertex_file_path, const char * fragment_file_path);
};
