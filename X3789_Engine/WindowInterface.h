
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

	static void showFramerate()
	{
		static unsigned int frame_count;
		static double current_time;
		static char title[100];
		static float mspf;

		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		static double last_time = glfwGetTime();
		current_time = glfwGetTime();

		if (current_time - last_time < 1.0f)
		{
			++frame_count;
		}
		else
		{
			mspf = 1000.0 / (float)frame_count;
			sprintf(title, "%d fps(%2.3f msec/frame) [X3789 by ArkiNis, Compilation %s]", frame_count, mspf, __TIMESTAMP__);
			glfwSetWindowTitle(window, title);

			frame_count = 1;
			last_time = current_time;
		}
	}

	static void endFrameDraw()
	{
		static GLFWwindow* window = WindowHolder::getWindowHolder()->getWindow();
		glfwSwapBuffers(window);
		glfwPollEvents();

		showFramerate();
	}
};
