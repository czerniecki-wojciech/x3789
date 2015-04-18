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
	XThreadSafeQueue() {}
	XThreadSafeQueue(const XThreadSafeQueue<T>& r)
		: q(std::move(r.q))
		, cond(std::move(r.cond))
		, mtx(std::move(r.mtx))
	{

	}
	void push(const T& refe)
	{
		std::lock_guard<std::mutex> lg(mtx);
		q.push(refe);
		cond.notify_one();
	}

	void push(T&& refe)
	{
        std::lock_guard<std::mutex> lg(mtx);
		q.push(refe);
		cond.notify_one();
	}
	void pop(T& refe)
	{
		std::unique_lock<std::mutex> ug(mtx);

		while (q.empty()) // always while, couse it can be wakes up by the system call
			cond.wait(ug);

		refe = q.front();
		q.pop();
	}

	XThreadSafeQueue<T>& ref()
	{
		return *this;
	}
};


//template<typename T>
//class ThreadSafeQueue
//{
//private:
//std::queue<T> q;
//std::condition_variable cond;
//std::mutex mtx;
//
//public:
//void push(const T& refe)
//{
//std::lock_guard<std::mutex> lg(mtx);
//q.push(refe);
//cond.notify_one();
//}
//
//void push(T&& refe)
//{
//std::lock_guard<std::mutex> lg(mtx);
//q.push(refe);
//cond.notify_one();
//}
//
//void pop(T& refe)
//{
//std::unique_lock<std::mutex> ug(mtx);
//
//while (q.empty()) // always while, couse it can be wakes up by the system call
//cond.wait(ug);
//
//refe = q.front();
//q.pop();
//}
//};
//
