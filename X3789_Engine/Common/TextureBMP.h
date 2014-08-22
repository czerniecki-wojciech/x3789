#pragma once
class TextureBMP
{
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
	unsigned char* data;
	GLuint texture_ID;
	GLuint sampler_ID;
	GLuint uniform_ID;
public:
	TextureBMP()
		:dataPos(0)
		, width(0)
		, height(0)
		, imageSize(0)
		, data(0)
	{}
	TextureBMP(char* filename);
	~TextureBMP();

	inline unsigned char* getData()
	{
		return data;
	}
	inline unsigned int getWidth()
	{
		return width;
	}
	inline unsigned int getHeight()
	{
		return height;
	}
	inline bool isLoaded()
	{
		return (data) ? true : false;
	}
	inline GLuint getTextureID()
	{
		return texture_ID;
	}
	inline void bindToProgram(GLuint program_ID, char* sampler_name)
	{
		this->sampler_ID = sampler_ID;
		uniform_ID = glGetUniformLocation(program_ID, sampler_name);
	}
	inline void loadToUniform(){
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_ID);
		glUniform1i(sampler_ID, 0);
	}
};

