
#include "stdafx.h"
#include <X3789_Engine\Object3D\VertexStorage.h>
//#include "UniformStorage.h"
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\Object3D\Object3D.h>
#include "Cube.h"


Cube::Cube()
	: Object3D()
{
	vertices = new VertexStorage(12);
#define CUBE_USE_TEXTURE
#ifndef CUBE_USE_TEXTURE
	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f,-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 1.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 1.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);

	
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 0.0f, 1.0f);

	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 0.0f, 1.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);


	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 1.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 1.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 1.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 1.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 1.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 1.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 1.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 1.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 1.0f);
#else
	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);


	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);


	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 1.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);


	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 0.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 0.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);


	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 1.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);


	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,		1.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);

	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f,	0.0f, 0.0f, 0.0f);
	vertices->newVertex(CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		1.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE * 0.5f, -CUBE_SIZE * 0.5f, CUBE_SIZE * 0.5f,		0.0f, 1.0f, 0.0f);
#endif
	this->endObjectDefinition();
}


Cube::~Cube()
{
}

