#include "ANN.h"
#include "LinearRegression.h"
#include "MNIST_Reader.h"
#include <iostream>
#include <chrono>
#include <string>
#include <iostream>
using namespace std;

int main() {
	srand(1);
	MNIST_Reader reader(100, 1000);
	vector<vector<NUMS>> X_train = reader.get_training_images();

	auto encoder = [](NUMS n) {
		return (n < 127) ? '.' : '#';
	};
	for (size_t i = 0; i < X_train.size; i++) {
		for (int j = 0; j < 28*28; j++) {
			cout << encoder(X_train.ray[i].ray[j]);
			if (j % 28 == 27) {
				cout << endl;
			}
		}
		cout << endl;
		cout << endl;
	}
	//int size[] = {28 * 28, 100, 100, 10};
	/*
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
	*/

	return 0;
}