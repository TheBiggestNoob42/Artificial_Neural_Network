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
}

LinearRegression::~LinearRegression()
{

}

vector<NUMS> LinearRegression::cost(vector<NUMS>& a, vector<NUMS>& b)
{
	
	return vector<NUMS>();
}
