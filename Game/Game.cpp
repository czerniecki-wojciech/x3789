
#include "stdafx.h"
#include <Windows.h>

#include <X3789_Engine\X3789_Engine_Common.h>
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\WindowHolder.h>
#include <X3789_Engine\WindowInterface.h>
#include <X3789_Engine\Common\ControlInterface.h>
#include <X3789_Engine\Common\TextureStorage.h>
#include <X3789_Engine\VBOTestClass.h>

#include <XMath\XMath.h>

int _tmain(int argc, _TCHAR* argv[])
{
	LoadLibrary("X3789_Engine");
	LoadLibrary("SandBox");

	ShaderInterface::getInstance();
	TextureStorage::init();

	VBOTestClass vbotc;
	vbotc.PreDraw();

	WindowInterface::SetCursorPosCenter();

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ControlInterface::getInstance()->computeMVP();

		vbotc.Draw(ShaderInterface::getInstance()->getShader(X3789_SHADER_DEFAULT_SOLID));// TEXTURED));

		WindowInterface::endFrameDraw();
	} while(!WindowInterface::GetKey(GLFW_KEY_ESCAPE) && !WindowInterface::WindowShouldClose());

	vbotc.PostDraw();

	return 0;
}
