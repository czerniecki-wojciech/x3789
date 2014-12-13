
#include "stdafx.h"
#include "Matrices.h"

template<typename T>
T Vector<T>::operator[](unsigned int index)
{
	if (index < size_x)
		return data[index];
	DebugBreak();
}

template<typename T>
Vector<T>::Vector(unsigned int size_x, unsigned int size_y, unsigned int size_z)
	: size_x(size_x)
{
	if (!size_x)
		DebugBreak();

	data = (T*)malloc(sizeof(T*) * size_x);
	memset(data, 0, sizeof(T*) * size_x);
}

template<typename T>
Vector<T>::~Vector()
{
	free(data);
}

template<typename T>
Vector<T> Matrix2D<T>::operator[](unsigned int index)
{
	if (index < size_x)
		return vertices[index];
	DebugBreak();
}

template<typename T>
Matrix2D<T>::Matrix2D(unsigned int size_x, unsigned int size_y)
	: size_x(size_x)
	, size_y(size_y)
{
	if (!size_x)
		DebugBreak();

	vertices = (Vector*)malloc(sizeof(Vector*) * size_x);

	for (int i = 0; i < size_x; i++)
	{
		vertices[i] = new Vector<T>(size_y);
	}
}

template<typename T>
Matrix2D<T>::~Matrix2D()
{
	for (int i = 0; i < size_x; i++)
	{
		delete vertices[i];
	}
	free(vertices);
}


template<typename T>
Matrix2D<T> Matrix3D<T>::operator[](unsigned int index)
{
	if(index < size_x)
		return matrices2d[index];
	DebugBreak();
}

template<typename T>
Matrix3D<T>::Matrix3D(unsigned int size_x, unsigned int size_y, unsigned int size_z)
	: size_x(size_x)
	, size_y(size_y)
	, size_z(size_z)
{
	if (!size_x)
		DebugBreak();

	matrices2d = (Matrix2D*)malloc(sizeof(Matrix2D*) * size_x);

	for (int i = 0; i < size_x; i++)
	{
		matrices2d[i] = new Matrix2D<T>(size_y, size_z);
	}
}

template<typename T>
Matrix3D<T>::~Matrix3D()
{
	for (int i = 0; i < size_x; i++)
	{
		delete matrices2d[i];
	}
	free(matrices2d);
}
