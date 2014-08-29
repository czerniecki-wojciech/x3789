// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>


//GLFWwindow* window;

//#include "Common/ShaderLoader.h"
//#include "Common\ControlInterface.h"
//#include "VertexAttrib.h"
#include <X3789_Engine\X3789_Engine_Common.h>
//#include <X3789_Engine\Object3D\VertexStorage.h>
//#include <X3789_Engine\Object3D\UniformStorage.h>
#include <X3789_Engine\Object3D\Object3D.h>
#include <X3789_Engine\Object3D\Primitives\Cube.h>
#include <X3789_Engine\WindowHolder.h>
#include <X3789_Engine\WindowInterface.h>
#include <X3789_Engine\ShaderInterface.h>

glm::mat4 MVP;

float x = 4;
float z = 4;

/*void calculateMVP()
{
	computeMatricesFromInputs();
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
}
*/
int _tmain(int argc, _TCHAR* argv[])
{
	LoadLibrary("X3789_Engine");
	LoadLibrary("SandBox");

	GLuint programID = ShaderInterface::getInstance()->loadBasicShader();

	Cube cube;
	Cube cube2;
	cube.setProgram(programID);
	cube2.setProgram(programID);
	cube2.setPosition(3, 0, 0);

	WindowInterface::SetCursorPosCenter();

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		cube.draw();
		cube2.draw();
		WindowInterface::endFrameDraw();

		if (WindowInterface::GetKey(GLFW_KEY_UP) == GLFW_PRESS || WindowInterface::GetKey(GLFW_KEY_W) == GLFW_PRESS){
			cube.Move(GLFW_KEY_UP);
			cube2.Move(GLFW_KEY_UP);
		}
		if (WindowInterface::GetKey(GLFW_KEY_DOWN) == GLFW_PRESS || WindowInterface::GetKey(GLFW_KEY_S) == GLFW_PRESS){
			cube.Move(GLFW_KEY_DOWN);
			cube2.Move(GLFW_KEY_DOWN);
		}
		if (WindowInterface::GetKey(GLFW_KEY_LEFT) == GLFW_PRESS || WindowInterface::GetKey(GLFW_KEY_A) == GLFW_PRESS){
			cube.Move(GLFW_KEY_LEFT);
			cube2.Move(GLFW_KEY_LEFT);
		}
		if (WindowInterface::GetKey(GLFW_KEY_RIGHT) == GLFW_PRESS || WindowInterface::GetKey(GLFW_KEY_D) == GLFW_PRESS){
			cube.Move(GLFW_KEY_RIGHT);
			cube2.Move(GLFW_KEY_RIGHT);
		}
		if (WindowInterface::GetKey(GLFW_KEY_SPACE) == GLFW_PRESS){
			cube.Move(GLFW_KEY_SPACE);
			cube2.Move(GLFW_KEY_SPACE);
		}
		if (WindowInterface::GetKey(GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
			cube.Move(GLFW_KEY_LEFT_CONTROL);
			cube2.Move(GLFW_KEY_LEFT_CONTROL);
		}
	} while (WindowInterface::GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && WindowInterface::WindowShouldClose() == 0);

	return 0;
}

