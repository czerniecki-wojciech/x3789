
#include "stdafx.h"
#include <Windows.h>

#include <X3789_Engine\X3789_Engine_Common.h>
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\Object3D\Object3D.h>
#include <X3789_Engine\Object3D\Primitives\Cube.h>
#include <X3789_Engine\WindowHolder.h>
#include <X3789_Engine\WindowInterface.h>
#include <X3789_Engine\Common\ControlInterface.h>
#include <X3789_Engine\Common\TextureStorage.h>
#include <X3789_Engine\Object3D\Object3DDrawer.h>

int _tmain(int argc, _TCHAR* argv[])
{
	LoadLibrary("X3789_Engine");
	LoadLibrary("SandBox");

	ShaderInterface::getInstance();
	TextureStorage::init();
	Object3DDrawer* object_drawer = Object3DDrawer::init();

	//Cube cube;
	//cube.setShader(SHADER_DEFAULT_TEXTURED);

#define TEST_CUBE_NUM_H 60
#define TEST_CUBE_NUM_V 60
	Cube* cubes = new Cube[TEST_CUBE_NUM_H * TEST_CUBE_NUM_V];

	for (int h = 0; h < TEST_CUBE_NUM_H; ++h)
	{
		for (int v = 0; v < TEST_CUBE_NUM_V; ++v)
		{
			object_drawer->addNewObject3D(&cubes[h + v * TEST_CUBE_NUM_H]);
			//cubes[h + v * TEST_CUBE_NUM_H].setPosition(-TEST_CUBE_NUM_H + h, -TEST_CUBE_NUM_V + v, 0.0f);
			//cubes[h + v * TEST_CUBE_NUM_H].setShader(SHADER_DEFAULT_SOLID);
			//cubes[h + v * TEST_CUBE_NUM_H].setShader(SHADER_DEFAULT_TEXTURED);
			cubes[h + v * TEST_CUBE_NUM_H].setShader(SHADER_GEOMETRY_CUBE);
			cubes[h + v * TEST_CUBE_NUM_H].setPosition(h, v, h - v);
		}
	}

	//Cube cube2;
	//cube2.setShader(SHADER_DEFAULT_TEXTURED);
	//cube2.setPosition(3, 0, 0);

	WindowInterface::SetCursorPosCenter();

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ControlInterface::getInstance()->computeMVP();
		//cube.draw();
		//cube2.draw();
		//for (int i = 0; i < TEST_CUBE_NUM_H * TEST_CUBE_NUM_V; ++i)
			//cubes[i].draw();

		object_drawer->drawAll();

		WindowInterface::endFrameDraw();
	} while(!WindowInterface::GetKey(GLFW_KEY_ESCAPE) && !WindowInterface::WindowShouldClose());

	delete[] cubes;

	return 0;
}
