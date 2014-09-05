
#include <stdafx.h>
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\Object3D\Object3D.h>
#include "Object3DDrawer.h"

Object3DDrawer* Object3DDrawer::instance = NULL;

inline void Object3DDrawer::addNewObject3D(Object3D* object)
{
	this->objects[allocated_object_num++] = object;
}

void Object3DDrawer::drawAll()
{
	GLuint current_shader = -1;
	Object3D* current_object = NULL;

	for (int i = 0; i < allocated_object_num; ++i)
	{
		current_object = objects[i];

		if (current_object->getShader() != current_shader)
		{
			current_object->draw();
			current_shader = current_object->getShader();
		}
		else
			current_object->draw(false);
	}
}
