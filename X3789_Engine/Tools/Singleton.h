
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <memory>
#include <mutex>

template<typename T, typename... Arguments>
class Singleton
{
private:
    static std::shared_ptr<T> instance;
    static std::once_flag is_initialized;
    void initializeNew(Arguments... args)
    {
        instance = std::make_shared<T>(args...);
    }

public:
    static std::shared_ptr<T> getInstance()
    {
        return instance;
    }

    Singleton(Arguments... args)
    {
        std::call_once(is_initialized, initializeNew, args...);
    }
    ~Singleton()
    {
        delete instance;
    }
};

template<typename T, typename... Arguments>
std::shared_ptr<T> Singleton<T, Arguments...>::instance;

#endif
