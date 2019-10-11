#include "util.h"
#include <iostream>
#include <cmath>

vector<vector<NUMS>> operator*(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_DOT_CHECK(a1, a2);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a2[0].size());
		for (size_t j = 0; j < a2[0].size(); j++) {
			NUMS total = 0;
			for (size_t k = 0; k < a2.size(); k++) {
				total += a1[i][k] * a2[k][j];
			}
			mat[i][j] = total;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator*(const NUMS& a1, const vector<vector<NUMS>>& a2)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a2.size());
	for (size_t i = 0; i < a2.size(); i++) {
		mat[i] = vector<NUMS>(a2[0].size());
		for (size_t j = 0; j < a2[0].size(); j++) {
			mat[i][j] = a1 * a2[i][j];
		}
	}
	return mat;
}

vector<vector<NUMS>> mat_mult(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_EQUAL_CHECK(a1, a2);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[i].size());
		#pragma ivdep
		for (size_t j = 0; j < a1[i].size(); j++) {
			mat[i][j] = a1[i][j] * a2[i][j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1)
{
	MAT_EQUAL_CHECK(a1, b1);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[0].size());
		for (size_t j = 0; j < a1[i].size(); j++) {
			mat[i][j] = a1[i][j] + b1[i][j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[0].size());
		for (size_t j = 0; j < a1[i].size(); j++) {
			mat[i][j] = a1[i][j] + b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const NUMS& a1, const vector<vector<NUMS>>& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(b1.size());
	for (size_t i = 0; i < b1.size(); i++) {
		mat[i] = vector<NUMS>(b1[0].size());
		for (size_t j = 0; j < b1[i].size(); j++) {
			mat[i][j] = b1[i][j] + a1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1)
{
	MAT_EQUAL_CHECK(a1, b1);
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[0].size());
		for (size_t j = 0; j < a1[0].size(); j++) {
			mat[i][j] = a1[i][j] - b1[i][j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[0].size());
		for (size_t j = 0; j < a1[0].size(); j++) {
			mat[i][j] = a1[i][j] - b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const NUMS& a1, const vector<vector<NUMS>>& b1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(b1.size());
	for (size_t i = 0; i < b1.size(); i++) {
		mat[i] = vector<NUMS>(b1[0].size());
		for (size_t j = 0; j < b1[0].size(); j++) {
			mat[i][j] = a1 - b1[i][j];
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid(const vector<vector<NUMS>>& a1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[0].size());
		for (size_t j = 0; j < a1[i].size(); j++) {
			mat[i][j] = 1 / (1 + exp(-a1[i][j]));
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid_derivative(const vector<vector<NUMS>>& a1)
{
	// a1 must have been passed through the sigmoid function
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1.size());
	for (size_t i = 0; i < a1.size(); i++) {
		mat[i] = vector<NUMS>(a1[0].size());
		for (size_t j = 0; j < a1[i].size(); j++) {
			mat[i][j] = a1[i][j] * (1 - a1[i][j]);
		}
	}
	return mat;
}

vector<vector<NUMS>> T(const vector<vector<NUMS>>& a1)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(a1[0].size());
	for (size_t i = 0; i < a1[0].size(); i++) {
		mat[i] = vector<NUMS>(a1.size());
		for (size_t j = 0; j < a1.size(); j++) {
			mat[i][j] = a1[j][i];
		}
	}
	return mat;
}

void print_string(const vector<vector<NUMS>>& a1)
{
	for (size_t i = 0; i < a1.size(); i++) {
		for (size_t j = 0; j < a1[0].size(); j++) {
			cout << a1[i][j] << " ";
		}
		cout << endl;
	}
}
