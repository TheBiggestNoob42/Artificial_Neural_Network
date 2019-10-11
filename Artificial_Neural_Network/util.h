#pragma once

#include "declarations.h"
#include <string>
#include <type_traits>

vector<vector<NUMS>> operator*(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2);
vector<vector<NUMS>> operator*(const NUMS& a1, const vector<vector<NUMS>>& a2);
vector<vector<NUMS>> mat_mult(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2);

vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1);
vector<vector<NUMS>> operator+(const vector<NUMS>& a1, const vector<vector<NUMS>>& b1);
vector<vector<NUMS>> operator+(const vector<vector<NUMS>>& a1, const vector<NUMS>& b1);

vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& b1);
vector<vector<NUMS>> operator-(const vector<vector<NUMS>>& a1, const NUMS& b1);
vector<vector<NUMS>> operator-(const NUMS& a1, const vector<vector<NUMS>>& b1);

vector<vector<NUMS>> operator-(const vector<NUMS>& a1, const vector<NUMS>& b1);

vector<vector<NUMS>> sigmoid(const vector<vector<NUMS>>& a1);
vector<vector<NUMS>> sigmoid_derivative(const vector<vector<NUMS>>& a1);

vector<vector<NUMS>> T(const vector<vector<NUMS>>& a1);

void print_string(const vector<vector<NUMS>>& a1);
