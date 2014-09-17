#include "stdafx.h"

#include <../X3789_Engine/WindowHolder.h>
#include "OpenGL3Initializer.h"

OpenGL3Initializer::OpenGL3Initializer()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}
	printf("DATE: %s\n", __TIMESTAMP__);

	glfwWindowHint(GLFW_SAMPLES, 8); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //We don't want the old OpenGL

	GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();

	char title[70];

	sprintf(title, "X3789 by ArkiNis, Compilation %s", __TIMESTAMP__);
	
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title, NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
	fprintf(stderr, "Failed to initialize GLEW\n");
	return;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	WindowHolder::getWindowHolder()->setWindow(window);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	glfwSwapInterval(VSYNC_ENABLED);
}

OpenGL3Initializer::~OpenGL3Initializer()
{
}
