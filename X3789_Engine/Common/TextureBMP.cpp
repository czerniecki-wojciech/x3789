#include "stdafx.h"

#include <X3789_Engine_Common.h>
#include "TextureBMP.h"
#include <fstream>


TextureBMP::TextureBMP(char* filename)
	:data(0)
{
	FILE* file = fopen(filename, "rb");

	if (!file)
	{
		printf("Could not load %s texture file.\n", filename);
		return;
	}

	if (fread(header, 1, 54, file) != 54){
		printf("Not a correct BMP header.\n");
		return;
	}

	if (header[0] != 'B' || header[1] != 'M'){
		printf("Not a correct BMP file.\n");
		return;
	}

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (imageSize == 0)    imageSize = width*height * 3;
	if (dataPos == 0)      dataPos = 54;

	data = new unsigned char[imageSize];

	fread(data, 1, imageSize, file);

	fclose(file);

	glGenTextures(1, &texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	
	delete[] data;

//#define TRILINEAR_FILTERING
#ifdef TRILINEAR_FILTERING
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
#else
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
#endif
}


TextureBMP::~TextureBMP()
{
	if (data)
	{
		delete[] data;
		data = 0;
	}

	if (sampler_ID > -1)
	{
		glDeleteTextures(1, &sampler_ID);
		sampler_ID = -1;
	}	
}
