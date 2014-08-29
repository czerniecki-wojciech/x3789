
#pragma once

class  WindowInterface
{
public:
	static int GetKey(int key)
	{
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		return ::glfwGetKey(window, key);
	}

	static void SetCursorPos(GLuint x, GLuint y){
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		::glfwSetCursorPos(window, 1024 / 2, 768 / 2);
	}

	static void GetCursorPos(float &x, float &y)
	{
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		double _x, _y;

		glfwGetCursorPos(window, &_x, &_y);
		x = _x;
		y = _y;
	}

	static void SetCursorPosCenter()
	{
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		glfwSetCursorPos(window, SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	}

	static int WindowShouldClose()
	{
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		return ::glfwWindowShouldClose(window);
	}

	static void endFrameDraw()
	{
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
};

