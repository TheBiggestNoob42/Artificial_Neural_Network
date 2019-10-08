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

std::map<std::string, vector<vector<NUMS>>> LinearRegression::train(vector<vector<NUMS>> X_train, vector<vector<NUMS>> Y_train, int num_of_epochs)
{
	std::map<std::string, vector<vector<NUMS>>> map;
	for (int i = 0; i < num_of_epochs; i++) {
		map = forward_propogation(X_train);

		auto c = cost(map["a2"], Y_train);

		auto
	}
	return map;
	
}

std::map<std::string, vector<vector<NUMS>>> LinearRegression::forward_propogation(vector<vector<NUMS>>& inputs)
{
	std::map<std::string, vector<vector<NUMS>>> map;
	vector<vector<NUMS>> z1 = mat_add(mat_dot(inputs, this->input_to_f_weight), this->first);
	vector<vector<NUMS>> a1 = sigmoid(z1);
	vector<vector<NUMS>> z2 = mat_add(mat_dot(a1, this->f_to_s_weight), this->second);
	vector<vector<NUMS>> a2 = sigmoid(z2);

	map["z1"] = z1;
	map["a1"] = a1;
	map["z2"] = z2;
	map["a2"] = a2;

	return map;
}

void LinearRegression::backward_propogation(std::map<std::string, vector<vector<NUMS>>>& cache, vector<vector<NUMS>>& X, vector<vector<NUMS>>& Y)
{

}

NUMS LinearRegression::cost(vector<vector<NUMS>>& a, vector<vector<NUMS>>& y)
{
	vector<NUMS>;
	return 0.0;
}
