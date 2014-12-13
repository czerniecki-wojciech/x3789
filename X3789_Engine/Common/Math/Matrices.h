
#pragma once

template<typename T>
class Vector
{
	T* data;
	unsigned int size_x;

public:
	T operator[](unsigned int index);

	Vector(unsigned int size_x);
	~Vector();

	unsigned int GetSizeX()
	{
		return size_x;
	}

	unsigned int GetSizeY()
	{
		return size_y;
	}
};


template<typename T>
class Matrix2D
{
	Vector* vertices;
	unsigned int size_x, size_y;

public:
	Vector<T> operator[](unsigned int index);

	Matrix2D(unsigned int size_x, unsigned int size_y);
	~Matrix2D();

	unsigned int GetSizeX()
	{
		return size_x;
	}

	unsigned int GetSizeY()
	{
		return size_y;
	}
};


template<typename T>
class Matrix3D
{
	Matrix2D* matrices2d;
	unsigned int size_x, size_y, size_z;
public:
	Matrix2D<T> operator[](unsigned int index);

	Matrix3D(unsigned int size_x, unsigned int size_y, unsigned int size_z);
	~Matrix3D();

	unsigned int GetSizeX()
	{
		return size_x;
	}

	unsigned int GetSizeY()
	{
		return size_y;
	}

	unsigned int GetSizeZ()
	{
		return size_z;
	}
};
