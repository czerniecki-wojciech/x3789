
#ifndef __WINDOW_HOLDER_H__
#define __WINDOW_HOLDER_H__

class DLL_INTERFACE WindowHolder
{
	static WindowHolder* instance;
	GLFWwindow* window;
protected:
	//static WindowHolder* m_istance;
	WindowHolder(void);
	//WindowHolder(const WindowHolder&);
	//WindowHolder& operator=(const WindowHolder&);
public:

    static WindowHolder* getInstance()
	{
		if (!instance)
			instance = new WindowHolder();
		return instance;
	}
	~WindowHolder()
	{}

    GLFWwindow* getWindow()
	{
		return window;
	}

	void setWindow(GLFWwindow* new_window)
	{
		window = new_window;
	}
};

#endif

