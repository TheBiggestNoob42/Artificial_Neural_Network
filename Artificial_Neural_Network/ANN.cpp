#include "ANN.h"
#include <iostream>

vector<vector<NUMS>> ANN::createWeightMatrix(size_t row, size_t col)
{
	vector<vector<NUMS>> mat = vector<vector<NUMS>>(row);
	for (size_t i = 0; i < row; i++) {
		mat.ray[i] = vector<NUMS>(col);
		for (size_t j = 0; j < col; j++) {
			mat.ray[i].ray[j] = ((double)rand()) / ((double)RAND_MAX - 1);
		}
	}
	return mat;
}

ANN::ANN(size_t sizes[], size_t len)
{
	this->layers = sizes;
	number_of_layers = len;

	this->weights = vector<vector<vector<NUMS>>>(len - 1);
	this->biases = vector<NUMS>(len - 1);
	for (size_t i = 0; i < len - 1; i++) {
		this->weights.ray[i] = this->createWeightMatrix(sizes[i], sizes[i + 1]);
		this->biases.ray[i] = ((double)rand()) / ((double)RAND_MAX - 1);
	}
}

ANN::~ANN()
{
}

/*
vector<vector<NUMS>> ANN::forward_propogation(vector<vector<NUMS>> input) {
	int num_of_inputs = input.size;
}
*/

vector<vector<vector<NUMS>>> ANN::getWeight()
{
	return this->weights;
}

vector<NUMS> ANN::getBiases()
{
	return this->biases;
}
