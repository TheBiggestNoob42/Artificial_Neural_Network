#include "LinearRegression.h"

LinearRegression::LinearRegression(int input_size, int f_neurons, int s_neurons) 
{
	this->input_to_f_weight = vector<vector<NUMS>>(input_size);
	for (int i = 0; i < input_size; i++) {
		this->input_to_f_weight.ray[i] = vector<NUMS>(f_neurons);
		for (int j = 0; j < f_neurons; j++) {
			this->input_to_f_weight.ray[i].ray[j] = 1.0; // ((double)rand()) / ((double)RAND_MAX - 1);
		}
	}

	this->f_to_s_weight = vector<vector<NUMS>>(f_neurons);
	for (int i = 0; i < f_neurons; i++) {
		this->f_to_s_weight.ray[i] = vector<NUMS>(s_neurons);
		for (int j = 0; j < s_neurons; j++) {
			this->f_to_s_weight.ray[i].ray[j] = 1.0;
		}
	}

	first = 1.0;
	second = 1.0;
}

LinearRegression::~LinearRegression()
{
	input_to_f_weight.~vector();
	f_to_s_weight.~vector();
}

std::map<std::string, vector<vector<NUMS>>> LinearRegression::train(const vector<vector<NUMS>>& X_train, const vector<vector<NUMS>>& Y_train, 
	int num_of_epochs, NUMS learning_rate)
{
	std::map<std::string, vector<vector<NUMS>>> outputs;
	for (int i = 0; i < num_of_epochs; i++) {
		outputs = forward_propogation(X_train);
		NUMS c = cost(outputs["a2"], Y_train);

		backward_propogation(outputs, X_train, Y_train, learning_rate);
	}

	return outputs;
	
}

std::map<std::string, vector<vector<NUMS>>> LinearRegression::forward_propogation(const vector<vector<NUMS>>& inputs)
{
	std::map<std::string, vector<vector<NUMS>>> map;
	vector<vector<NUMS>> z1 = inputs * this->input_to_f_weight + this->first;
	vector<vector<NUMS>> a1 = sigmoid(z1);
	vector<vector<NUMS>> z2 = a1 * this->f_to_s_weight + this->second;
	vector<vector<NUMS>> a2 = sigmoid(z2);

	map["z1"] = z1;
	map["a1"] = a1;
	map["z2"] = z2;
	map["a2"] = a2;

	return map;
}

void LinearRegression::backward_propogation(std::map<std::string, vector<vector<NUMS>>>& cache, const vector<vector<NUMS>>& X, 
	const vector<vector<NUMS>>& Y, const NUMS learning_rate)
{
	vector<vector<NUMS>> dA2 = cache["a2"] - Y;
	vector<vector<NUMS>> dZ2 = mat_mult(sigmoid_derivative(cache["a2"]), dA2);
	// dB2 = dZ2
	vector<vector<NUMS>> dW2 = mat_mult(cache["a1"], dZ2);

	vector<vector<NUMS>> dA1 = dZ2 * T(this->f_to_s_weight);
	vector<vector<NUMS>> dZ1 = mat_mult(sigmoid_derivative(cache["a1"]), dA1);
	// dB1 = dZ2
	vector<vector<NUMS>> dW1 = mat_mult(X, dZ1);

	this->f_to_s_weight = this->f_to_s_weight - (learning_rate * dW2);
	this->input_to_f_weight = this->input_to_f_weight - (learning_rate * dW1);

	NUMS db1 = 0;
	for (size_t i = 0; i < dZ1.size; i++) {
		NUMS total = 0;
		for (size_t j = 0; j < dZ1.ray[i].size; j++) {
			total = total + dZ1.ray[i].ray[j];
		}
		total /= dZ1.ray[i].size;
		db1 += total;
	}
	db1 /= dZ1.size;

	NUMS db2 = 0;
	for (size_t i = 0; i < dZ2.size; i++) {
		NUMS total = 0;
		for (size_t j = 0; j < dZ2.ray[i].size; j++) {
			total = total + dZ2.ray[i].ray[j];
		}
		total /= dZ2.ray[i].size;
		db2 += total;
	}
	db2 /= dZ2.size;

	this->first = this->first - (learning_rate * db1);
	this->second = this->second - (learning_rate * db2);
}

NUMS LinearRegression::cost(const vector<vector<NUMS>>& a, const vector<vector<NUMS>>& y)
{
	if (!(a.size == y.size && a.ray[0].size == y.ray[0].size)) {
		__debugbreak();
	}

	NUMS cost = 0;
	for (size_t i = 0; i < a.size; i++) {
		for (size_t j = 0; j < a.ray[0].size; j++) {
			cost += (a.ray[i].ray[j] - y.ray[i].ray[j]) * (a.ray[i].ray[j] - y.ray[i].ray[j]);
		}
	}
	cost = cost / 2;
	return cost;
}
