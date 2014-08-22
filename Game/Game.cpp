// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>


//GLFWwindow* window;

//#include "Common/ShaderLoader.h"
//#include "Common\ControlInterface.h"
//#include "VertexAttrib.h"
#include <X3789_Engine\X3789_Engine_Common.h>
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

	// Get a handle for our "MVP" uniform
	/*GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	if (programID == -1)
	{
		glfwTerminate();
		return -1;
	}

	
	static const GLfloat g_vertex_buffer_data[] = {
		0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};

	VertexAttrib attrib(18);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	
	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	//GLuint programID = 0;

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	WindowInterface::SetCursorPos(window, 1024 / 2, 768 / 2);

	do
	{

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glUseProgram(programID);


		calculateMVP();
		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		glEnableVertexAttribArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle

		glDisableVertexAttribArray(0);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);
	*/

	while (WindowInterface::GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS //&&
		)//glfwWindowShouldClose() == 0)
	{

	}

	return 0;
}

