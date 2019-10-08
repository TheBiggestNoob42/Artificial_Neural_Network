#pragma once
#define NUMS double

template <typename T>
class vector
{
private:
	T* ray;
public:
	size_t size;

	vector(size_t size);
	~vector();

	vector<T> operator*(const vector<T>& obj);
	vector<T> operator+(const vector<T>& obj);
	vector<T> operator+(NUMS bias);
	T operator[](int idx);

	vector<T> transpose();
};
