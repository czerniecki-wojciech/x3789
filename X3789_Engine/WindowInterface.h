
#pragma once

class  WindowInterface
{
public:
	static int GetKey(char key)
	{
		return ::glfwGetKey(WindowHolder::getWindowHolder()->getWindow(), key);
	}

	void SetCursorPos(GLuint x, GLuint y){
		::glfwSetCursorPos(WindowHolder::getWindowHolder()->getWindow(), 1024 / 2, 768 / 2);
	}
};

