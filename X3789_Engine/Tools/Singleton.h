
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <memory>
#include <mutex>

template<typename T>
class Singleton
{
private:
	static std::once_flag once_flag;
	static std::shared_ptr<T> instance;

	static void initialize()
	{
		instance = std::make_shared<T>();
	}

public:
	static std::shared_ptr<T> getInstance()
	{
		std::call_once(once_flag, initialize);
		if (instance)
			return instance;
		else
			return getInstance();
	}
};

template<typename T>
std::shared_ptr<T> Singleton<T>::instance;

template<typename T>
std::once_flag Singleton<T>::once_flag;

#endif
