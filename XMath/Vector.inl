
#ifndef __VECTOR_INL__
#define __VECTOR_INL__

#include "Vector.h"

template<typename T>
Vector<T>::Vector()
	: current_size(ELEMENT_NUM)
	, current_index(0)
{
	this->alloc();
}

template<typename T>
Vector<T>::Vector(unsigned int element_num)
	: current_size(element_num)
	, current_index(0)
{
	this->alloc();
}

template<typename T>
Vector<T>::~Vector()
{
	if (this->data)
		this->erease();
}

template<typename T>
void Vector<T>::alloc()
{

}

template<typename T>
void Vector<T>::realloc()
{

}

template<typename T>
T* Vector<T>::getData()
{

}

template<typename T>
unsigned int Vector<T>::getLength()
{

}

template<typename T>
unsigned int Vector<T>::getAllocSize()
{

}

template<typename T>
unsigned int Vector<T>::getSize()
{

}

template<typename T>
T* Vector<T>::pushBack(T element)
{

}

template<typename T>
void Vector<T>::erease()
{

}

template<typename T>
void Vector<T>::trim()
{

}

template<typename T>
T& Vector<T>::operator[] (unsigned int index)
{

}

#endif
