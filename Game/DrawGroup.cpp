
#include "stdafx.h"

#ifdef VALID

#include "VertexAttrib.h"
//#include "Common\TextureBMP.h"
//#include <Common\TextureStorage.h>
#include "DrawGroup.h"


void DrawGroup::draw()
{
	for (int i = 0; i < vertex_attrib_num; i++)
		vertex_attribs[i]->copyDataToGPU(i);

	texture_storage.loadToUnifom();
}

void DrawGroup::addTexture(char* filename, char* sampler_name)
{
	texture_storage.loadBMPTexture(filename);
	texture_storage.bindTexture(program_ID, sampler_name, texture_storage.getLoadedTextureNum());
}

void DrawGroup::addVertexAttrib(VertexAttrib* new_va)
{
	if (new_va)
		vertex_attribs[vertex_attrib_num++] = new_va;
}

#endif
