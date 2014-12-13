
#include "stdafx.h"
#include <X3789_Engine\Object3D\VertexStorage.h>
//#include "UniformStorage.h"
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\Object3D\Object3D.h>
#include "Cube.h"


Cube::Cube()
	: Object3D()
{

#if( defined(X3789_RENDER_VAO) && defined(X3789_SURFACE_MODE_COLOR))
	vertices = new VertexStorage(36);
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
#endif

#if( defined(X3789_RENDER_VAO) && defined(X3789_SURFACE_MODE_TEXTURE))
	vertices = new VertexStorage(36);
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

#ifdef X3789_RENDER_VAO_GEOMETRY
	vertices = new VertexStorage(1);
	vertices->newVertex(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
#endif

#if ( defined(X3789_RENDER_VBO_TRIANGLE) || defined(X3789_RENDER_VBO_GEOMETRY) || defined(X3789_RENDER_VBO_TRIANGLE))
	vertices = new VertexStorage(8);

	vertices->newVertex( CUBE_SIZE_2,	 CUBE_SIZE_2,	CUBE_SIZE_2, 1.0f, 0.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE_2,	 CUBE_SIZE_2,	CUBE_SIZE_2, 0.0f, 1.0f, 0.0f);
	vertices->newVertex(-CUBE_SIZE_2,	-CUBE_SIZE_2,	CUBE_SIZE_2, 0.0f, 0.0f, 1.0f);
	vertices->newVertex( CUBE_SIZE_2,	-CUBE_SIZE_2,	CUBE_SIZE_2, 1.0f, 1.0f, 0.0f);

	vertices->newVertex( CUBE_SIZE_2,	 CUBE_SIZE_2, -CUBE_SIZE_2, 1.0f, 0.0f, 1.0f);
	vertices->newVertex(-CUBE_SIZE_2,	 CUBE_SIZE_2, -CUBE_SIZE_2, 0.0f, 1.0f, 1.0f);
	vertices->newVertex(-CUBE_SIZE_2,	-CUBE_SIZE_2, -CUBE_SIZE_2, 1.0f, 1.0f, 1.0f);
	vertices->newVertex( CUBE_SIZE_2,	-CUBE_SIZE_2, -CUBE_SIZE_2, 0.0f, 0.0f, 0.0f);
#endif

#if ( defined(X3789_RENDER_VBO_TRIANGLE))

#endif

#if( defined(X3789_RENDER_VBO_TRI_STRIP) )
	indices = new GLushort[14];

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 3;
	indices[3] = 2;

	indices[4] = 6;
	indices[5] = 1;
	indices[6] = 5;
	indices[7] = 4;
	
	indices[8] = 6;
	indices[9] = 7;
	indices[10] = 3;
	indices[11] = 4;
	
	indices[12] = 0;
	indices[13] = 1;
#endif

	this->endObjectDefinition();
}


Cube::~Cube()
{
}

