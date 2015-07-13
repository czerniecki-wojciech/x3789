#include "stdafx.h"
#include "ShaderLoader.h"

#include <X3789_Engine_Common.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


GLuint ShaderLoader::loadShader(const char * vertex_file_path, const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open())
	{
		std::string Line = "";
		while (getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();

		printf("End of reading vertex shader file.\n");
	}
	else
	{
		printf("ERROR: cant read vertex shader source file\n");
		return -1;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()){
		std::string Line = "";
		while (getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();

		printf("End of reading fragment shader file.\n");
	}
	else
	{
		printf("ERROR: cant read vertex shader source file\n");
		return -1;
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> VertexShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

	// Link the program
	fprintf(stdout, "Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage(std::max(InfoLogLength, int(1)));
	glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}

GLuint ShaderLoader::createShader()
{
	return glCreateProgram();
}

bool ShaderLoader::combineWithShaderFile(GLuint shader_id, const char* file_path, GLuint shader_type)
{
	// Create the shaders
	GLuint sub_shader_id = glCreateShader(shader_type);

	// Read the Shader code from the file
	std::string ShaderCode;
	std::ifstream ShaderStream(file_path, std::ios::in);
	if (ShaderStream.is_open())
	{
		std::string Line = "";
		while (getline(ShaderStream, Line))
			ShaderCode += "\n" + Line;
		ShaderStream.close();
	}
	else
	{
		printf("ERROR: cant read shader source file(%s).\n", file_path);
		return 0;
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Shader
	printf("Compiling shader : %s\n", file_path);
	char const * SourcePointer = ShaderCode.c_str();
	glShaderSource(sub_shader_id, 1, &SourcePointer, NULL);
	glCompileShader(sub_shader_id);

	// Check Shader
	glGetShaderiv(sub_shader_id, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(sub_shader_id, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(sub_shader_id, InfoLogLength, NULL, &ShaderErrorMessage[0]);
	if (ShaderErrorMessage[0])
		fprintf(stdout, "%s\n", &ShaderErrorMessage[0]);

	glAttachShader(shader_id, sub_shader_id);

	// Check the program
	glGetProgramiv(shader_id, GL_LINK_STATUS, &Result);
	glGetProgramiv(shader_id, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage(std::max(InfoLogLength, int(1)));
	glGetProgramInfoLog(shader_id, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	if (ProgramErrorMessage[0])
		fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

	//glDeleteShader(sub_shader_id);

	return true;
}

bool ShaderLoader::linkShader(GLuint shader_id)
{
	glLinkProgram(shader_id);

	return true;
}
