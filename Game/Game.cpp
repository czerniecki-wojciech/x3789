
#include "stdafx.h"

#include "X3789_MACRO_VIEWER.h"

#include <X3789_Engine/X3789_Engine_Common.h>

//#pragma message(MACRO_VIEWER(DLL_INTERFACE))
//#pragma message(MACRO_VIEWER(SYSTEM_LINUX))

#include <X3789_Engine/ShaderInterface.h>
#include <X3789_Engine/WindowHolder.h>
#include <X3789_Engine/WindowInterface.h>
#include <X3789_Engine/Common/ControlInterface.h>
#include <X3789_Engine/Common/TextureStorage.h>
#include <X3789_Engine/VBOTestClass.h>
#include <X3789_Engine/X3789_Engine.h>
//#include <X3789_Engine/VertexQueue.h>

#include <XMath/XMath.h>



#include <X3789_Engine/Tools/Singleton.h>
//#include <iostream>

//VertexQueue<uint, 0>* queue;

void tests()
{
	class TestClass
	{
	public:
		TestClass(int a)
		{
            //std::cout << a << std::endl;
		}
	};
	typedef Singleton<TestClass, int> singl;

	singl a(3);
	TestClass *p = a.getInstance();
}

int main(int argc, char* argv[])
{
	X3789_Engine_start();
	tests();

	//queue = VertexQueue<uint, 0>::getQueue();

	//LoadLibrary("X3789_Engine");
	//LoadLibrary("SandBox");

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
