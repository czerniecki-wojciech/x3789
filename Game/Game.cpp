
#include "stdafx.h"
#include <Windows.h>

#include <X3789_Engine\X3789_Engine_Common.h>
#include <X3789_Engine\Object3D\Object3D.h>
#include <X3789_Engine\Object3D\Primitives\Cube.h>
#include <X3789_Engine\WindowHolder.h>
#include <X3789_Engine\WindowInterface.h>
#include <X3789_Engine\ShaderInterface.h>
#include <X3789_Engine\Common\ControlInterface.h>

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
		ControlInterface::getInstance()->computeMVP();
		cube.draw();
		cube2.draw();
		WindowInterface::endFrameDraw();
	} while (WindowInterface::GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && WindowInterface::WindowShouldClose() == 0);

	return 0;
}

