
#ifndef __MATRIX_3D_H__
#define __MATRIX_3D_H__

#include "Matrix2D.h"
#include "XMathDataTypes.h"

template<typename T, uint width = 3, uint height = width, uint depth = height>
class Matrix3D
{
private:
	Matrix2D<T, width, height> data[depth];
public:
	Matrix3D();
	~Matrix3D();

	Matrix2D<T, width, height>& operator[](uint pos);
};

#include "Matrix3D.inl"

#endif
