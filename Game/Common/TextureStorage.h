#pragma once

class TextureStorage
{
private:
	static TextureBMP* textures[8];
	unsigned short loaded_textures;
public:
	bool loadBMPTexture(char* filename);

	void bindTexture(GLuint program_ID, char* samplerName, short texture_index);

	inline void loadToUnifom(){
		for (int i = 0; i < loaded_textures; i++)
		{
			textures[i]->loadToUniform();
		}
	}

	unsigned short getLoadedTextureNum()
	{
		return loaded_textures;
	}

	TextureStorage()
		:loaded_textures(0)
	{}

	~TextureStorage();
};

