#include "stdafx.h"

#include "TextureBMP.h"
#include "TextureStorage.h"

TextureStorage* TextureStorage::instance = NULL;
TextureBMP* TextureStorage::textures[TOTAL_TEXTURE_NUM];

/*void TextureStorage::bindTexture(GLuint program_ID, char* sampler_name, short texture_index)
{
	textures[texture_index]->bindToProgram(program_ID, sampler_name);
}

bool TextureStorage::loadBMPTexture(char* filename)
{
	textures[loaded_textures] = new TextureBMP(filename);
	if (textures[loaded_textures]->isLoaded()){
		loaded_textures++;
		return true;
	}
	return false;
}*/


TextureStorage::~TextureStorage()
{
	for (int i = 0; i < TOTAL_TEXTURE_NUM; ++i)
	{
		textures[i]->~TextureBMP();
	}
}

TextureStorage::TextureStorage()
	:loaded_textures(0)
{
	textures[TEXTURE_TEST] = new TextureBMP("Texture/metal.bmp");
	textures[TEXTURE_SKY] = new TextureBMP("Texture/sky.bmp");
}

void TextureStorage::useTexture(Texture texture, GLuint shader, char* sampler_name)
{
	textures[texture]->bindToProgram(shader, sampler_name);
	textures[texture]->loadToUniform();
}
