#pragma once
#define NUMS double
#define MAT_EQUAL_CHECK(X, Y) if (X.size != Y.size) __debugbreak();\
					 if (X.ray[0].size != Y.ray[0].size) __debugbreak();
#define MAT_DOT_CHECK(X, Y) if (X.ray[0].size != Y.size) __debugbreak();

#include <stdlib.h>

template <typename T>
struct vector {
	size_t size;
	T* ray;

	vector() {
		size = sizeof(T);
		ray = (T*)malloc(size);
	}

	vector(size_t s) {
		ray = (T*)malloc(sizeof(T) * s);
		size = s;
	}

	~vector() {
		delete[] ray;
		ray = NULL;
	}
};
