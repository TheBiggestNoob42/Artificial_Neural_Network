#include "LinearRegression.h"

LinearRegression::LinearRegression(int input_size, int f_neurons, int s_neurons)
{
	this->input_to_f_weight = {
		input_size,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * input_size),
	};
	for (int i = 0; i < input_size; i++) {
		this->input_to_f_weight.ray[i] = {
			f_neurons,
			(NUMS*)malloc(sizeof(NUMS) * f_neurons),
		};
		for (int j = 0; j < f_neurons; j++) {
			this->input_to_f_weight.ray[i].ray[j] = 1.0; // ((double)rand()) / ((double)RAND_MAX - 1);
		}
	}

	this->f_to_s_weight = {
		f_neurons,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * f_neurons),
	};
	for (int i = 0; i < f_neurons; i++) {
		this->f_to_s_weight.ray[i] = {
			s_neurons,
			(NUMS*)malloc(sizeof(NUMS) * s_neurons),
		};
		for (int j = 0; j < s_neurons; j++) {
			this->f_to_s_weight.ray[i].ray[j] = 1.0;
		}
	}

	first = 1.0;
	second = 1.0;
}

LinearRegression::~LinearRegression()
{
	delete_vector(input_to_f_weight);
	delete_vector(f_to_s_weight);
}

std::map<std::string, vector<vector<NUMS>>> LinearRegression::train(const vector<vector<NUMS>>& X_train, const vector<vector<NUMS>>& Y_train, int num_of_epochs)
{
	std::map<std::string, vector<vector<NUMS>>> outputs;
	for (int i = 0; i < num_of_epochs; i++) {
		outputs = forward_propogation(X_train);
		NUMS c = cost(outputs["a2"], Y_train);

		backward_propogation(outputs, X_train, Y_train);
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

void LinearRegression::backward_propogation(std::map<std::string, vector<vector<NUMS>>>& cache, const vector<vector<NUMS>>& X, const vector<vector<NUMS>>& Y)
{
	vector<vector<NUMS>> dA2 = cache["a2"] - Y;
	//sigmoid derivative
	vector<vector<NUMS>> dZ2 = mat_mult(sigmoid_derivative(cache["a2"]), dA2);
	vector<vector<NUMS>> dB2 = dZ2 - 0;
	vector<vector<NUMS>> dW2 = mat_mult(cache["a1"], dZ2);

	vector<vector<NUMS>> dA1 = mat_mult(cache["a1"], dZ2);
	vector<vector<NUMS>> dZ1 = np.dot();
}

NUMS LinearRegression::cost(const vector<vector<NUMS>>& a, const vector<vector<NUMS>>& y)
{
	if (!(a.size == y.size && a.ray[0].size == y.ray[0].size)) {
		__debugbreak();
	}

	NUMS cost = 0;
	for (int i = 0; i < a.size; i++) {
		for (int j = 0; j < a.ray[0].size; j++) {
			cost += (a.ray[i].ray[j] - y.ray[i].ray[j]) * (a.ray[i].ray[j] - y.ray[i].ray[j]);
		}
	}
	cost = cost / 2;
	return cost;
}
