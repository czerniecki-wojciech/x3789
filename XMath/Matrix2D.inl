
#ifndef __MATRIX_2D_INL__
#define __MATRIX_2D_INL__

#include "Matrix2D.h"

template<typename T, uint width, uint height>
Matrix2D<T, width, height>::Matrix2D()
{
}

template<typename T, uint width, uint height>
Matrix2D<T, width, height>::~Matrix2D()
{
}

template<typename T, uint width, uint height>
Matrix1D<T, width>& Matrix2D<T, width, height>::operator[](uint pos)
{
	if (pos < height)
		return data[pos];
	//__debugbreak();
	return data[0];
}

#endif
