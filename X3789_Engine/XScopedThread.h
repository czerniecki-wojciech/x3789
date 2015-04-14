#pragma once
#include <thread>
class XScopedThread
{
	std::thread th;
public:
	XScopedThread(const XScopedThread&) = delete;
	XScopedThread& operator=(const XScopedThread&) = delete;

	XScopedThread& operator=(XScopedThread&& rval)
	{
		th = std::move(rval.th);
		return *this;
	}

	template<typename... T>
	XScopedThread(T&&... args)
		: th(std::forward<T>(args)...)
	{
	}

	XScopedThread(std::thread _th)
		: th(std::move(_th))
	{
	}

	~XScopedThread()
	{
		if (th.joinable())
			th.join();
	}
};

