#include "ANN.h"

#include <fstream>
#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
using namespace std;

int main() {
	srand(1);
	//int size[] = {28 * 28, 100, 100, 10};
	size_t size[] = { 3, 4, 4, 2 };
	ANN network(size, 4);
	
	cout << "Weight Matrices" << endl;
	cout << "===================" << endl;
	auto weight = network.getWeight();
	for (int mat = 0; mat < weight.size; mat++) {
		for (int row = 0; row < weight.ray[mat].size; row++) {
			for (int col = 0; col < weight.ray[mat].ray[row].size; col++) {
				cout << weight.ray[mat].ray[row].ray[col] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "Bases Vectors" << endl;
	cout << "===================" << endl;
	auto biases = network.getBiases();
	for (int col = 0; col < biases.size; col++) {
		cout << biases.ray[col] << " ";
	}
	cout << endl;
	cout << endl;

	size_t N;
	cout << "Enter in the number of inputs cases: ";
	cin >> N;

	vector<vector<NUMS>> input = {
		N,
		(vector<NUMS>*)malloc(sizeof(vector<NUMS>) * N),
	};

	string raw_input;
	NUMS value;

	getline(cin, raw_input);

	for (int i = 0; i < N; i++) {
		input.ray[i] = {
			size[0],
			(NUMS*)malloc(sizeof(NUMS) * size[0]),
		};
		getline(cin, raw_input);
		stringstream ss(raw_input);
		int j = 0;
		while (ss >> value) {
			input.ray[i].ray[j++] = value;
		}
	}

	input = network.forward_propogation(input);
	for (int i = 0; i < input.size; i++) {
		for (int j = 0; j < input.ray[i].size; j++) {
			cout << input.ray[i].ray[j] << " ";
		}
		cout << endl;
	}
	/*
	vector<double> a = {
		10000000,
		(double*)malloc(sizeof(double) * 10000000),
	};
	vector<double> b = {
		10000000,
		(double*)malloc(sizeof(double) * 10000000),
	};
	for (int i = 0; i < 10000000; i++) {
		a.ray[i] = i + 1.0;
		b.ray[i] = i + 1.0;
	}

	cout << "Taking the dot product of two vectors, ones that I created, with 10,000,000 elements each." << endl;

	vector<double> c = {
		10000000,
		(double*)malloc(sizeof(double) * 10000000),
	};
	double sum = 0.0;
	auto t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < a.size; i++) {
		c.ray[i] = a.ray[i] * b.ray[i];
	}
	auto t2 = chrono::high_resolution_clock::now();
	auto reg = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Regular time: " << reg << " microseconds" << endl;
	delete c.ray;

	c = {
		10000000,
		(double*)malloc(sizeof(double) * 10000000),
	};
	sum = 0.0;
	t1 = chrono::high_resolution_clock::now();
	#pragma loop(no_vector)
	for (int i = 0; i < a.size; i++) {
		c.ray[i] = a.ray[i] * b.ray[i];
	}
	t2 = chrono::high_resolution_clock::now();
	reg = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Non-vectorized time: " << reg << " microseconds" << endl;
	delete c.ray;

	c = {
		10000000,
		(double*)malloc(sizeof(double) * 10000000),
	};
	sum = 0.0;
	t1 = chrono::high_resolution_clock::now();
	#pragma ivdep
	for (int i = 0; i < a.size; i++) {
		c.ray[i] = a.ray[i] * b.ray[i];
	}
	t2 = chrono::high_resolution_clock::now();
	reg = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Vectorized time: " << reg << " microseconds" << endl;
	delete c.ray;
	*/
	return 0;
}