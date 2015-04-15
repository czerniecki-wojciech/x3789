#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

template<typename T>
class XThreadSafeQueue
{
private:
	std::queue<T> q;
	std::condition_variable cond;
	std::mutex mtx;

public:
	void push(const T& refe)
	{
		std::lock_guard<std::mutex> lg(mtx);
		q.push(refe);
		cond.notify_one();
	}

	void push(T&& refe)
	{
		lock_guard<std::mutex> lg(mtx);
		q.push(refe);
		cond.notify_one();
	}

	/*T& pop()
	{
		std::unique_lock<std::mutex> ul(mtx);

		while (q.empty())
			cond.wait(ul);

		T& refe = q.front();
		q.pop();
		return refe;
	}*/
	void pop(T& refe)
	{
		std::unique_lock<std::mutex> ug(mtx);

		while (q.empty()) // always while, couse it can be wakes up by the system call
			cond.wait(ug);

		refe = q.front();
		q.pop();
	}
};

/*

template<typename T>
class ThreadSafeQueue
{
private:
queue<T> q;
condition_variable cond;
mutex mtx;

public:
void push(const T& refe)
{
lock_guard<mutex> lg(mtx);
q.push(refe);
cond.notify_one();
}

void push(T&& refe)
{
lock_guard<mutex> lg(mtx);
q.push(refe);
cond.notify_one();
}

void pop(T& refe)
{
unique_lock<mutex> ug(mtx);

while (q.empty()) // always while, couse it can be wakes up by the system call
cond.wait(ug);

refe = q.front();
q.pop();
}
};
*/