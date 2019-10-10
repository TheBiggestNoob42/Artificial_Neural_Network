#pragma once
#include "declarations.h"
#include <fstream>
#include <iostream>
using namespace std;

class MNIST_Reader
{
private:
	int number_of_training_sets;
	int number_of_testing_sets;

	ifstream input_train_data, input_train_label;
	ifstream input_test_data, input_test_label;

	static const int LABEL_MAGIC = 2049;
	static const int IMAGE_MAGIC = 2051;

	vector<vector<NUMS>> mnist_images(bool is_train);
	vector<vector<NUMS>> mnist_labels(bool is_train);
public:
	MNIST_Reader(int n_of_train_set, int n_of_test_set);
	~MNIST_Reader();

	vector<vector<NUMS>> get_training_images();
	vector<vector<NUMS>> get_training_labels();
};

