#pragma once
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define NUMS double
#define MAT_EQUAL_CHECK(X, Y) if (X.size() != Y.size()) { cout << "X.size: " << X.size() << "\tY.size: " << Y.size() << endl; __debugbreak(); }\
					 if (X[0].size() != Y[0].size()) { cout << "X[0].size: " << X[0].size() << "\tY[0].size: " << Y[0].size() << endl; __debugbreak(); }
#define MAT_DOT_CHECK(X, Y) if (X[0].size() != Y.size()) __debugbreak();

/*
template<typename T>
class vector<T> {
	T* ray;
	size_t size;

	vector(size_t s) {
		size = s;
		ray = new T[size];
	}

	vector() {
		size = 1;
		ray = new T[1];
	}

	~vector() {
		delete[] ray;
	}

	vector<T> operator=(vector<T>& vec){
		delete[] ray;

		size = vec.size;
		ray = new T[size];
		for (size_t i = 0; i < size; i++) {
			ray[i] = vec[i];
		}

		return *this
	}

	T operator[](int idx) {
		if (idx >= 0 && idx < size) {
			return ray[idx];
		} else {
			throw std::runtime_error("Index out of bounds");
		}
	}
};
*/