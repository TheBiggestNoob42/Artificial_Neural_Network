#include "ANN.h"
#include <iostream>

vector<vector<NUMS>> ANN::createWeightMatrix(size_t row, size_t col)
{
	vector<vector<NUMS>> mat = {
		row,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * row),
	};
	for (int i = 0; i < row; i++) {
		mat.ray[i] = {
			col,
			(NUMS*)malloc(sizeof(NUMS) * col),
		};
		for (int j = 0; j < col; j++) {
			mat.ray[i].ray[j] = ((double)rand()) / ((double)RAND_MAX - 1);
		}
	}
	return mat;
}

ANN::ANN(size_t sizes[], size_t len)
{
	this->layers = sizes;
	number_of_layers = len;

	this->weights = {
		len - 1,
		(vector<vector<NUMS>>*)malloc(sizeof(vector<vector<NUMS>>) * (len - 1)),
	};
	this->biases = {
		len - 1,
		(NUMS*)malloc(sizeof(NUMS) * (len - 1)),
	};

	for (size_t i = 0; i < len - 1; i++) {
		this->weights.ray[i] = this->createWeightMatrix(sizes[i], sizes[i + 1]);
		this->biases.ray[i] = ((double)rand()) / ((double)RAND_MAX - 1);
	}
}

ANN::~ANN()
{
	delete_vector(weights);
	delete_vector(biases);
}

vector<vector<NUMS>> ANN::forward_propogation(vector<vector<NUMS>> input) {
	int num_of_inputs = input.size;

	vector<vector<NUMS>> new_input;
	for (int i = 0; i < weights.size; i++) {
		new_input = sigmoid(mat_add(mat_dot(input, weights.ray[i]), biases.ray[i]));
		delete_vector(input);
		input = new_input;
	}

	return input;
}

vector<vector<vector<NUMS>>> ANN::getWeight()
{
	return this->weights;
}

vector<NUMS> ANN::getBiases()
{
	return this->biases;
}
