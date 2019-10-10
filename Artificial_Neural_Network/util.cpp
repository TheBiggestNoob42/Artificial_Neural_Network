#include "util.h"
#include <iostream>
#include <cmath>

vector<vector<NUMS>> operator*(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_DOT_CHECK(a1, a2);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a2.ray[0].size);
		for (size_t j = 0; j < a2.ray[0].size; j++) {
			NUMS total = 0;
			for (size_t k = 0; k < a2.size; k++) {
				total += a1.ray[i].ray[k] * a2.ray[k].ray[j];
			}
			mat.ray[i].ray[j] = total;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator*(const NUMS& a1, const vector<vector<NUMS>>& a2)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a2.size);
	for (size_t i = 0; i < a2.size; i++) {
		mat.ray[i] = vector<NUMS>(a2.ray[0].size);
		for (size_t j = 0; j < a2.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1 * a2.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> mat_mult(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_EQUAL_CHECK(a1, a2);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[i].size);
		#pragma ivdep
		for (size_t j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] * a2.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1)
{
	MAT_EQUAL_CHECK(a1, b1);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[0].size);
		for (size_t j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] + b1.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[0].size);
		for (size_t j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] + b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const NUMS& a1, const vector<vector<NUMS>>& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(b1.size);
	for (size_t i = 0; i < b1.size; i++) {
		mat.ray[i] = vector<NUMS>(b1.ray[0].size);
		for (size_t j = 0; j < b1.ray[i].size; j++) {
			mat.ray[i].ray[j] = b1.ray[i].ray[j] + a1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1)
{
	MAT_EQUAL_CHECK(a1, b1);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[0].size);
		for (size_t j = 0; j < a1.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] - b1.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[0].size);
		for (size_t j = 0; j < a1.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] - b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const NUMS& a1, const vector<vector<NUMS>>& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(b1.size);
	for (size_t i = 0; i < b1.size; i++) {
		mat.ray[i] = vector<NUMS>(b1.ray[0].size);
		for (size_t j = 0; j < b1.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1 - b1.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid(const vector<vector<NUMS>>& a1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[0].size);
		for (size_t j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = 1 / 1 + exp(-a1.ray[i].ray[j]);
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid_derivative(const vector<vector<NUMS>>& a1)
{
	// a1 must have been passed through the sigmoid function
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size);
	for (size_t i = 0; i < a1.size; i++) {
		mat.ray[i] = vector<NUMS>(a1.ray[0].size);
		for (size_t j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] * (1 - a1.ray[i].ray[j]);
		}
	}
	return mat;
}

vector<vector<NUMS>> T(const vector<vector<NUMS>>& a1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.ray[0].size);
	for (size_t i = 0; i < a1.ray[0].size; i++) {
		mat.ray[i] = vector<NUMS>(a1.size);
		for (size_t j = 0; j < a1.size; j++) {
			mat.ray[i].ray[j] = a1.ray[j].ray[i];
		}
	}
	return mat;
}
