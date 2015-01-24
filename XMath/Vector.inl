
#ifndef __VECTOR_INL__
#define __VECTOR_INL__

#include "Vector.h"

#include <cstring>

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
	{
		this->erease();

		free(data);
		data = 0;
	}
}

template<typename T>
void Vector<T>::alloc()
{
	data = (T*)malloc(sizeof(T) * current_size);
	memset(data, 0, sizeof(T) * current_size);
}

template<typename T>
void Vector<T>::realloc()
{
	current_size *= 2;

	T* new_data = (T*)malloc(sizeof(T) * current_size);

	memset(new_data + sizeof(T) * current_index, 0, sizeof(T) * (current_size - current_index));
	memcpy(new_data, data, sizeof(T) * current_index);

	free(data);

	data = new_data;
}

template<typename T>
T* Vector<T>::getData()
{
	return data;
}

template<typename T>
unsigned int Vector<T>::getLength()
{
	return current_index;
}

template<typename T>
unsigned int Vector<T>::getAllocSize()
{
	return current_size;
}

template<typename T>
unsigned int Vector<T>::getSize()
{
	return current_index * sizeof(T);
}

template<typename T>
T* Vector<T>::pushBack(T element)
{
	if (current_index + 1 == current_size)
		realloc();

	data[current_index++] = element;
}

template<typename T>
void Vector<T>::erease()
{
	memset(data, 0, sizeof(T) * current_index);
	current_index = 0;
}

template<typename T>
void Vector<T>::trim()
{
	current_size = current_index;

	T* new_data = (T*)malloc(sizeof(T) * current_size);

	memset(new_data + sizeof(T) * current_index, 0, sizeof(T) * (current_size - current_index));
	memcpy(new_data, data, sizeof(T) * current_index);

	free(data);

	data = new_data;
}

template<typename T>
T& Vector<T>::operator[] (unsigned int index)
{
	return data[index];
}

#endif
