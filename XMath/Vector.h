
#ifndef __VECTOR_H__
#define __VECTOR_H__

#define ELEMENT_NUM 32

template<typename T>
class Vector
{
private:
	T* data;
	unsigned int current_size;
	unsigned int current_index;

	void alloc();
	void realloc();

public:
	Vector();
	Vector(unsigned int element_num);
	Vector(T* data, unsigned int num);
	~Vector();

	T* getData();
	unsigned int getLength();
	unsigned int getAllocSize();
	unsigned int getSize();

	T* pushBack(T element);

	void erease();
	void trim();

	T& operator[] (unsigned int index);
};

#include "Vector.inl"

#endif
