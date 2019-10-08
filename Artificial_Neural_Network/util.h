#pragma once

#include "declarations.h"
#include <type_traits>

vector<vector<NUMS>> mat_dot(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2);
vector<vector<NUMS>> mat_mult(const vector<vector<NUMS>>& a1, const vector<vector<NUMS>>& a2);

vector<vector<NUMS>> mat_add(const vector<vector<NUMS>>& a1, const NUMS& b1);

vector<vector<NUMS>> sigmoid(const vector<vector<NUMS>>& a1);

void delete_vector(vector<vector<vector<NUMS>>>& a1);

void delete_vector(vector<vector<NUMS>>& a1);

void delete_vector(vector<NUMS>& a1);