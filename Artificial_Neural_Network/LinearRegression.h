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

	std::map<std::string, vector<vector<NUMS>>> train(vector<vector<NUMS>> X_train, vector<vector<NUMS>> Y_train, int num_of_epochs);

	std::map<std::string, vector<vector<NUMS>>> forward_propogation(vector<vector<NUMS>>& inputs);
	void backward_propogation(std::map<std::string, vector<vector<NUMS>>>& cache, vector<vector<NUMS>>& X, vector<vector<NUMS>>& Y);

	NUMS cost(vector<vector<NUMS>>& a, vector<vector<NUMS>>& y);
};

