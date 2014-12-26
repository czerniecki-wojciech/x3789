
#ifndef __MATRIX_1D_INL__
#define __MATRIX_1D_INL__
#include "Matrix1D.h"

template<typename T, unsigned int width>
Matrix1D<T, width>::Matrix1D()
{
}


template<typename T, unsigned int width>
Matrix1D<T, width>::~Matrix1D()
{
}

template<typename T, unsigned int width>
T& Matrix1D<T, width>::operator[](unsigned int pos)
{
	if (pos < width)
		return data[pos];
	__debugbreak();
	return data[0];
}

#endif
