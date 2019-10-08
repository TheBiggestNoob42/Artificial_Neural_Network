#pragma once
#include "declarations.h"

class LinearRegression
{
private:
	vector<vector<NUMS>> input_to_f_weight;
	vector<vector<NUMS>> f_to_s_weight;
	vector<vector<NUMS>> s_to_o_weight;
	vector<NUMS> biases;
public:
	LinearRegression(int input_size, int f_neurons, int s_neurons);
	~LinearRegression();

	vector<NUMS> cost(vector<NUMS>& a, vector<NUMS>& b);
};

