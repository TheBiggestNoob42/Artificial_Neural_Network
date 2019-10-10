#pragma once
#include "declarations.h"
#include "util.h"
#include <map>
#include <string>


class LinearRegression
{
private:
	vector<vector<NUMS>> input_to_f_weight;
	vector<vector<NUMS>> f_to_s_weight;
	NUMS first;
	NUMS second;

public:
	LinearRegression(int input_size, int f_neurons, int s_neurons);
	~LinearRegression();

	map<string, vector<vector<NUMS>>> train(const vector<vector<NUMS>>& X_train, const vector<vector<NUMS>>& Y_train, 
		int num_of_epochs, NUMS learning_rate);

	map<string, vector<vector<NUMS>>> forward_propogation(const vector<vector<NUMS>>& inputs);
	void backward_propogation(map<string, vector<vector<NUMS>>>& cache, const vector<vector<NUMS>>& X, const vector<vector<NUMS>>& Y, 
		NUMS learning_rate);

	NUMS cost(const vector<vector<NUMS>>& a, const vector<vector<NUMS>>& y);
};

