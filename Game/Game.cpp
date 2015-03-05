
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
#include <X3789_Engine/VAOTestClass.h>

#include <XMath/XMath.h>
#include "LibraryLoader.h"


#include <X3789_Engine/Tools/Singleton.h>
#include <X3789_Engine/VerticesList.h>
#include <X3789_Engine/Vertex.h>
//#include <iostream>

//VertexQueue<uint, 0>* queue;

void tests()
{
	typedef Singleton<VerticesList<Vertex_RGB, 0>, int> singl;

	VerticesList<Vertex_RGB, 0>* vertices_list = singl::getInstance();
}

int main(int argc, char* argv[])
{
	LibraryLoader library_loader;
	library_loader.loadAll();

	tests();

	//queue = VertexQueue<uint, 0>::getQueue();

	//LoadLibrary("X3789_Engine");
	//LoadLibrary("SandBox");

	ShaderInterface::getInstance();
	TextureStorage::init();

	/*VBOTestClass vbotc;
	vbotc.PreDraw();*/

	VAOTestClass vaotc;
	vaotc.PreDraw();

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

	vaotc.PostDraw();

	return 0;
}
