
#include "stdafx.h"

#include "X3789_MACRO_VIEWER.h"

#include <X3789_Engine/X3789_Engine_Common.h>

//#pragma message(MACRO_VIEWER(DLL_INTERFACE))
//#pragma message(MACRO_VIEWER(SYSTEM_LINUX))

#include <X3789_Engine/X3789_Engine.h>
#include <X3789_Engine/ShaderInterface.h>
#include <X3789_Engine/WindowHolder.h>
#include <X3789_Engine/WindowInterface.h>
#include <X3789_Engine/Common/ControlInterface.h>
#include <X3789_Engine/Common/TextureStorage.h>
#include <X3789_Engine/VBOTestClass.h>
#include <X3789_Engine/VAOTestClass.h>

#include <XMath/XMath.h>


#include <X3789_Engine/Tools/Singleton.h>
#include <X3789_Engine/Vertex.h>
//#include <iostream>

//VertexQueue<uint, 0>* queue;

//--test1
#include <X3789_Engine/XScopedThread.h>
#include <X3789_Engine/XThreadSafeQueue.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>
//--end test1

void producer(std::shared_ptr<XThreadSafeQueue<float>> q)
{
    for (float i = 0.0f; i < 100.0f; ++i)
	{
		q->push(i);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void customer(std::shared_ptr<XThreadSafeQueue<float>> q, float id)
{
	for (;;)
	{
		float r;
		q->pop(std::ref(r));
		std::cout << "thread " << id << " takes " << r << std::endl;
	}
}

void doNothing(int i)
{
	std::cout << i << std::endl;
}

    XThreadSafeQueue<float> q;
void test1()
{
	XThreadSafeQueue<float> q;

	std::shared_ptr<XThreadSafeQueue<float>> p(&q);

	XScopedThread th1(producer, p);
	XScopedThread th2(customer, p, 1);
	XScopedThread th3(customer, p, 2);
	XScopedThread th4(customer, p, 3);
}


class TestOne
{
public:
    static int number;
    TestOne()
    {
        number = 0;
    }
    void increment()
    {
        ++number;
    }
    void printIt()
    {
        std::cout << number << std::endl;
    }
};

void tests()
{
	//test1();

	class TestOne
	{
	private:
		unsigned int number;
	public:
		TestOne() : number(0)
		{}
		void increment()
		{
			++number;
		}
		void print()
		{
			std::cout << number << std::endl;
		}

		friend class Singleton < TestOne > ;
	};


	Singleton<TestOne>::getInstance()->print();
	Singleton<TestOne>::getInstance()->increment();

	Singleton<TestOne>::getInstance()->print();
	Singleton<TestOne>::getInstance()->increment();

	Singleton<TestOne>::getInstance()->print();
	Singleton<TestOne>::getInstance()->increment();
}
#ifndef SYSTEM_LINUX
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

void getCurrentDirectory(){
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	printf("The current working directory is %s", cCurrentPath);
}

int main(int argc, char* argv[])
{
	getCurrentDirectory();
    X3789_Engine_start();

	tests();

	//queue = VertexQueue<uint, 0>::getQueue();

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
