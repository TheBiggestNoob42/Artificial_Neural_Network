#include "LinearRegression.h"


LinearRegression::LinearRegression(int input_size, int f_neurons, int s_neurons) 
{
	this->input_to_f_weight = vector<vector<NUMS>>(input_size);
	for (int i = 0; i < input_size; i++) {
		this->input_to_f_weight[i] = vector<NUMS>(f_neurons);
		for (int j = 0; j < f_neurons; j++) {
			this->input_to_f_weight[i][j] = ((double)rand()) / ((double)RAND_MAX - 1);
		}
	}

	this->f_to_s_weight = vector<vector<NUMS>>(f_neurons);
	for (int i = 0; i < f_neurons; i++) {
		this->f_to_s_weight[i] = vector<NUMS>(s_neurons);
		for (int j = 0; j < s_neurons; j++) {
			this->f_to_s_weight[i][j] = ((double)rand()) / ((double)RAND_MAX - 1);;
		}
	}

	this->first = ((double)rand()) / ((double)RAND_MAX - 1);

	this->second = ((double)rand()) / ((double)RAND_MAX - 1);
}

LinearRegression::~LinearRegression()
{
}

map<string, vector<vector<NUMS>>> LinearRegression::train(const vector<vector<NUMS>>& X_train, const vector<vector<NUMS>>& Y_train, 
	int num_of_epochs, NUMS learning_rate)
{
	cout << endl;
	map<string, vector<vector<NUMS>>> outputs;
	for (int i = 0; i < num_of_epochs; i++) {
		outputs = forward_propogation(X_train);
		NUMS c = cost(outputs["a2"], Y_train);
		cout << "Percentage correct in epoch " << i << ": " << c << "%" << endl;

		print_string(outputs["a2"]);
		cout << endl;
		print_string(Y_train);

		backward_propogation(outputs, X_train, Y_train, learning_rate);
	}

	return outputs;
	
}

map<string, vector<vector<NUMS>>> LinearRegression::forward_propogation(const vector<vector<NUMS>>& inputs)
{
	map<string, vector<vector<NUMS>>> map;
	vector<vector<NUMS>> z1 = (inputs * this->input_to_f_weight) + this->first;
	vector<vector<NUMS>> a1 = sigmoid(z1);
	vector<vector<NUMS>> z2 = (a1 * this->f_to_s_weight) + this->second;
	vector<vector<NUMS>> a2 = sigmoid(z2);

	map["z1"] = z1;
	map["a1"] = a1;
	map["z2"] = z2;
	map["a2"] = a2;

	return map;
}

void LinearRegression::backward_propogation(map<string, vector<vector<NUMS>>>& cache, const vector<vector<NUMS>>& X,
	const vector<vector<NUMS>>& Y, const NUMS learning_rate)
{
	vector<vector<NUMS>> dA2 = cache["a2"] - Y;
	vector<vector<NUMS>> dZ2 = mat_mult(cache["a2"], dA2);
	// dB2 = dZ2
	vector<vector<NUMS>> dW2 = T(cache["a1"]) * dZ2;

	vector<vector<NUMS>> dA1 = dZ2 * T(this->f_to_s_weight);
	vector<vector<NUMS>> dZ1 = mat_mult(sigmoid_derivative(cache["a1"]), dA1);
	// dB1 = dZ2
	vector<vector<NUMS>> dW1 = T(X) * dZ1;

	this->f_to_s_weight = this->f_to_s_weight - (learning_rate * dW2);
	this->input_to_f_weight = this->input_to_f_weight - (learning_rate * dW1);

	NUMS db2 = 0;
	for (int i = 0; i < dZ2.size(); i++) {
		for (int j = 0; j < dZ2[0].size(); j++) {
			db2 += dZ2[i][j];
		}
	}
	db2 /= (dZ2.size() * dZ2[0].size());
	
	NUMS db1 = 0;
	for (int i = 0; i < dZ1.size(); i++) {
		for (int j = 0; j < dZ1[0].size(); j++) {
			db1 += dZ1[i][j];
		}
	}
	db1 /= (dZ1.size() * dZ1[0].size());	

	this->first = this->first - (learning_rate * db1);
	this->second = this->second - (learning_rate * db2);
}

NUMS LinearRegression::cost(const vector<vector<NUMS>>& a, const vector<vector<NUMS>>& y)
{
	if (!(a.size() == y.size() && a[0].size() == y[0].size())) {
		__debugbreak();
	}

	NUMS cost = 0;
	if (a[0].size() == 1) {
		for (int i = 0; i < a.size(); i++) {
			cost += abs(a[i][0] - y[i][0]);
		}
		cost /= a.size();
		cost *= 100;
		return cost;
	}

	for (size_t i = 0; i < a.size(); i++) {
		size_t largest_of_y = 0;
		for (size_t j = 0; j < y[0].size(); j++) {
			if (y[i][j] > y[i][largest_of_y]) {
				largest_of_y = j;
			}
		}
		size_t largest_of_a = 0;
		for (size_t j = 0; j < a[0].size(); j++) {
			if (a[i][j] > a[i][largest_of_a]) {
				largest_of_a = j;
			}
		}
		if (largest_of_y == largest_of_a) {
			cost += 1.0;
		}
	}
	cost *= 100;
	cost /= (a.size() * a[0].size());
	return cost;
}
