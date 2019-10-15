#pragma once

#include <thrust/host_vector.h>
#include "declarations.h"
#include "util.h"

class ANN
{
private:
	size_t* layers;
	size_t number_of_layers;

	vector<vector<vector<NUMS>>> weights;
	vector<NUMS> biases;

	vector<vector<NUMS>> createWeightMatrix(size_t col, size_t row);
public:
	ANN(size_t size[], size_t len);
	~ANN();

	// vector<vector<NUMS>> forward_propogation(vector<vector<NUMS>> input);

	vector<vector<vector<NUMS>>> getWeight();
	vector<NUMS> getBiases();
};



