#pragma once
#include <iostream>
#include <assert.h>
#define NUMS double
#define MAT_EQUAL_CHECK(X, Y) if (X.size() != Y.size()) { cout << "X.size: " << X.size() << "\tY.size: " << Y.size() << endl; __debugbreak(); }\
					 if (X[0].size() != Y[0].size()) { cout << "X[0].size: " << X[0].size() << "\tY[0].size: " << Y[0].size() << endl; __debugbreak(); }
#define MAT_DOT_CHECK(X, Y) if (X[0].size() != Y.size()) __debugbreak();

#include <stdlib.h>
#include <vector>
using namespace std;
