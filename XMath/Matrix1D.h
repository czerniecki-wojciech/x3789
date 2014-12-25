 
#ifndef __MATRIX_1D_H__
#define __MATRIX_1D_H__

template<typename T, unsigned int width = 3>
class Matrix1D
{
private:
	T data[width];
public:
	Matrix1D();
	~Matrix1D();

	T& operator[](unsigned int pos);
};

#include "Matrix1D.inl"

#endif
