#pragma once

class TextureBMP;

class DLL_INTERFACE TextureStorage
{
private:
	static TextureStorage* instance;
	static TextureBMP* textures[TOTAL_TEXTURE_NUM];
	unsigned short loaded_textures;
	TextureStorage();
	
public:
	/*
	bool loadBMPTexture(char* filename);
	void bindTexture(GLuint program_ID, char* samplerName, short texture_index);

	inline void loadToUnifom(){
		for (int i = 0; i < loaded_textures; i++)
		{
			textures[i]->loadToUniform();
		}
	}
	*/

	unsigned short getTextureNum()
	{
		return TOTAL_TEXTURE_NUM;
	}

	static void useTexture(Texture texture, GLuint shader, char* sampler_name = "texture0");

	static TextureStorage* init()
	{
		if (!instance)
			instance = new TextureStorage();
		return instance;
	}

	~TextureStorage();
};

