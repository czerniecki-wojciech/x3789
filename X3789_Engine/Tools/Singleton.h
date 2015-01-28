
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template<typename T, typename... Arguments>
class Singleton
{
private:
	static T* instance;
public:
	static T* getInstance();
	Singleton(Arguments... args);
	~Singleton();
};


template<typename T, typename... Arguments>
Singleton<T, Arguments...>::Singleton(Arguments... args)
{
	if (!instance)
		instance = new T(args...);
}

template<typename T, typename... Arguments>
Singleton<T, Arguments...>::~Singleton()
{
	
}

template<typename T, typename... Arguments>
T* Singleton<T, Arguments...>::getInstance()
{
	return instance;
}

template<typename T, typename... Arguments>
T* Singleton<T, Arguments...>::instance = 0;

#endif
