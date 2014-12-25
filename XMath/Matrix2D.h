
#ifndef __MATRIX_2D_H__
#define __MATRIX_2D_H__

#include "Matrix1D.h"
#include "XMathDataTypes.h"

template<typename T, uint width = 3, uint height = width>
class Matrix2D
{
private:
	Matrix1D<T, width> data[height];
public:
	Matrix2D();
	~Matrix2D();

	Matrix1D<T, width>& operator[](uint pos);
};

#include "Matrix2D.inl"

#endif
