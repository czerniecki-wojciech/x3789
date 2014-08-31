
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

int _tmain(int argc, _TCHAR* argv[])
{
	LoadLibrary("X3789_Engine");
	LoadLibrary("SandBox");

	ShaderInterface::getInstance();
	TextureStorage::init();

	Cube cube;
	cube.setShader(SHADER_DEFAULT_TEXTURED);
	Cube cube2;
	cube2.setShader(SHADER_DEFAULT_TEXTURED);
	cube2.setPosition(3, 0, 0);

	WindowInterface::SetCursorPosCenter();

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ControlInterface::getInstance()->computeMVP();
		cube.draw();
		cube2.draw();
		WindowInterface::endFrameDraw();
	} while(!WindowInterface::GetKey(GLFW_KEY_ESCAPE) && !WindowInterface::WindowShouldClose());

	return 0;
}
