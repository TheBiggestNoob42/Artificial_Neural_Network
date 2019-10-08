#include "vector.h"


template<typename T>
vector<T>::vector(size_t size)
{
	this.size = size;
	ray = (T*)malloc(sizeof(T) * size);
}

template<typename T>
vector<T>::~vector()
{
	delete ray;
}

template<typename T>
vector<T> vector<T>::operator*(const vector<T>& object)
{
	vector<T> obj = object.transpose();
	if (obj.size != size) {	__debugbreak();	}

	vector<T> mat(size);

	for (int i = 0; i < size; i++) {
		T total = 0;
		for (int j = 0; j < obj.size; j++) {
			total += ;
		}
		mat[i] = this[i] * obj[0]
	}
	return mat;
}

template<typename T>
vector<T> vector<T>::operator+(const vector<T>& obj)
{
	if (obj.size != size) { __debugbreak(); }

	vector<T> mat(size);
	for (int i = 0; i < size; i++) {
		mat[i] = this[i] + obj[i];
	}
	return mat;
}

template<typename T>
vector<T> vector<T>::operator+(NUMS bias)
{
	vector<T> mat(size);
	for (int i = 0; i < size; i++) {
		mat[i] = ray[i] + bias;
	}
	return mat;
}

template<typename T>
T vector<T>::operator[](int idx)
{
	return ray[i];
}

template<typename T>
vector<T> vector<T>::transpose()
{
	return vector<T>();
}
