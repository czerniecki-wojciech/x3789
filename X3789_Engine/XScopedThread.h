#pragma once
#include <thread>
#include <mutex>
/*
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

	XScopedThread(XScopedThread&& rval)
	{
		th = std::move(rval.th);
	}

	~XScopedThread()
	{
		if (th.joinable())
			th.join();
	}
};
*/

using namespace std;

class XScopedThread
{
	thread th_;
public:
	XScopedThread(const XScopedThread&) = delete;
	XScopedThread& operator=(const XScopedThread&) = delete;

	XScopedThread(XScopedThread&& rval) // = default
	{
		th_ = move(rval.th_);
	}
	XScopedThread& operator=(XScopedThread&& rval)
	{
		th_ = move(rval.th_);
		return *this;
	}

	template<typename... T>
	XScopedThread(T&&... args) : th_(forward<T>(args)...)
	{
	}

	XScopedThread(thread th) : th_(move(th))
	{
	}

	~XScopedThread()
	{
		if (th_.joinable())
			th_.join();
	}
};
