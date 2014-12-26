
#ifndef __MATRIX_3D_INL__
#define __MATRIX_3D_INL__

#include "Matrix3D.h"

template<typename T, uint width, uint height, uint depth>
Matrix3D<T, width, height, depth>::Matrix3D()
{
}

template<typename T, uint width, uint height, uint depth>
Matrix3D<T, width, height, depth>::~Matrix3D()
{
	
}

template<typename T, uint width, uint height, uint depth>
Matrix2D<T, width, height>& Matrix3D<T, width, height, depth>::operator[](uint pos)
{
	if (pos < depth)
		return data[pos];
	__debugbreak();
	return data[0];
}

#endif
