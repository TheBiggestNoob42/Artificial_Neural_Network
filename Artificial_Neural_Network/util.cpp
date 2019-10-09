#include "util.h"
#include <iostream>
#include <cmath>

vector<vector<NUMS>> operator*(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_DOT_CHECK(a1, a2);
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};

	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a2.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a2.ray[0].size),
		};
		for (int j = 0; j < a2.ray[0].size; j++) {
			NUMS total = 0;
			for (int k = 0; k < a2.size; k++) {
				total += a1.ray[i].ray[k] * a2.ray[k].ray[j];
			}
			mat.ray[i].ray[j] = total;
		}
	}
	return mat;
}

vector<vector<NUMS>> mat_mult(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2)
{
	MAT_EQUAL_CHECK(a1, a2);
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[i].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[i].size),
		};
		#pragma ivdep
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] * a2.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1)
{
	MAT_EQUAL_CHECK(a1, b1);
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};

	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[0].size),
		};
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] + b1.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};

	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[0].size),
		};
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] + b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator+(const NUMS& a1, const vector<vector<NUMS>>& b1)
{
	vector<vector<NUMS>> mat = {
		b1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * b1.size),
	};

	for (int i = 0; i < b1.size; i++) {
		mat.ray[i] = {
			b1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * b1.ray[0].size),
		};
		for (int j = 0; j < b1.ray[i].size; j++) {
			mat.ray[i].ray[j] = b1.ray[i].ray[j] + a1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1)
{
	MAT_EQUAL_CHECK(a1, b1);
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[0].size),
		};
		for (int j = 0; j < a1.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] - b1.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const NUMS& b1)
{
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[0].size),
		};
		for (int j = 0; j < a1.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] - b1;
		}
	}
	return mat;
}

vector<vector<NUMS>> operator-(const NUMS& a1, const vector<vector<NUMS>>& b1)
{
	vector<vector<NUMS>> mat = {
		b1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * b1.size),
	};
	for (int i = 0; i < b1.size; i++) {
		mat.ray[i] = {
			b1.ray[0].size,
			(NUMS*)malloc(sizeof(NUMS) * b1.ray[0].size),
		};
		for (int j = 0; j < b1.ray[0].size; j++) {
			mat.ray[i].ray[j] = a1 - b1.ray[i].ray[j];
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid(const vector<vector<NUMS>>& a1)
{
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[i].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[i].size),
		};
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = 1 / 1 + exp(-a1.ray[i].ray[j]);
		}
	}
	return mat;
}

vector<vector<NUMS>> sigmoid_derivative(const vector<vector<NUMS>>& a1)
{
	// a1 must have been passed through the sigmoid function
	vector<vector<NUMS>> mat = {
		a1.size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * a1.size),
	};
	for (int i = 0; i < a1.size; i++) {
		mat.ray[i] = {
			a1.ray[i].size,
			(NUMS*)malloc(sizeof(NUMS) * a1.ray[i].size),
		};
		for (int j = 0; j < a1.ray[i].size; j++) {
			mat.ray[i].ray[j] = a1.ray[i].ray[j] * (1 - a1.ray[i].ray[j]);
		}
	}
	return mat;
}

void delete_vector(vector<vector<vector<NUMS>>>& a1)
{
	for (int i = 0; i < a1.size; i++) {
		delete_vector(a1.ray[i]);
	}
}

void delete_vector(vector<vector<NUMS>>& a1)
{
	for (int i = 0; i < a1.size; i++) {
		delete_vector(a1.ray[i]);
	}
}

void delete_vector(vector<NUMS>& a1)
{
	delete[] a1.ray;
}
