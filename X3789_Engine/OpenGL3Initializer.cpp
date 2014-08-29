#include "stdafx.h"

#include <../X3789_Engine/WindowHolder.h>
#include "OpenGL3Initializer.h"


//GLFWwindow* window;

OpenGL3Initializer::OpenGL3Initializer()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}
	printf("DATE: %s\n", __TIMESTAMP__);

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //We don't want the old OpenGL

	// Open a window and create its OpenGL context
	//GLFWwindow* window; // (In the accompanying source code, this variable is global)
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

	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK)
	{
	fprintf(stderr, "Failed to initialize GLEW\n");
	return;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	WindowHolder::getWindowHolder()->setWindow(window);
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
}

OpenGL3Initializer::~OpenGL3Initializer()
{
}
