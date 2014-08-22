#include "stdafx.h"

#include "TextureBMP.h"
#include "TextureStorage.h"

TextureBMP* TextureStorage::textures[8];

void TextureStorage::bindTexture(GLuint program_ID, char* sampler_name, short texture_index)
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
}


TextureStorage::~TextureStorage()
{
	for (int i = 0; i < loaded_textures; i++)
	{
		textures[i]->~TextureBMP();
	}
}
