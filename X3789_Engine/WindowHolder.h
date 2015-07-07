
#ifndef __WINDOW_HOLDER_H__
#define __WINDOW_HOLDER_H__

#include "Tools/Singleton.h"

class DLL_INTERFACE _WindowHolder
{
    static _WindowHolder* instance;
	GLFWwindow* window;
protected:
    //static WindowHolder* m_istance;
	//WindowHolder(const WindowHolder&);
	//WindowHolder& operator=(const WindowHolder&);
public:
    _WindowHolder(void);
    ~_WindowHolder()
	{}

    GLFWwindow* getWindow()
	{
		return window;
	}

	void setWindow(GLFWwindow* new_window)
	{
		window = new_window;
	}

    friend class Singleton<_WindowHolder>;
};

typedef Singleton<_WindowHolder> WindowHolder;

#endif

