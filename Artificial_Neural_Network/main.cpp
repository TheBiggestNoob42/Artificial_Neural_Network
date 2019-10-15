#include "ANN.h"
#include "LinearRegression.h"
#include "MNIST_Reader.h"
#include <iostream>
#include <chrono>
#include <string>
#include <iostream>
using namespace std;

int main() {
	// cl::Platform platform;
	srand(1);
	MNIST_Reader reader(5, 1000);
	vector<vector<NUMS>> X_train = reader.get_training_images();
	vector<vector<NUMS>> Y_train = reader.get_training_labels();
	
	/*
	auto encoder = [](NUMS n) {
		return (n < 0.05) ? '.' : (n < 0.2) ? '+' : '#';
	};
	for (size_t i = 0; i < X_train.size(); i++) {
		for (int j = 0; j < Y_train[i].size(); j++) {
			cout << Y_train[i][j] << " ";
		}
		cout << endl;
		for (int j = 0; j < 28*28; j++) {
			cout << encoder(X_train[i][j]);
			if (j % 28 == 27) {
				cout << endl;
			}
		}
		cout << endl;
		cout << endl;
	}
	*/

	
	LinearRegression lr(784, 200, 10);
	lr.train(X_train, Y_train, 1000, 1);

	/*
	auto f = [](vector<NUMS> x) {
		NUMS cost = 0;
		for (int i = 0; i < x.size(); i++) {
			cost += x[i];
		}
		return cost / x.size();
	};
	vector<vector<NUMS>> X_exp = vector<vector<NUMS>>(1);
	vector<vector<NUMS>> Y_exp = vector<vector<NUMS>>(1);
	for (int i = 0; i < 1; i++) {
		X_exp[i] = vector<NUMS>(3);
		for (int j = 0; j < 3; j++) {
			X_exp[i][j] = ((double)rand())/((double)RAND_MAX);
		}
		Y_exp[i] = vector<NUMS>(1);
		Y_exp[i][0] = f(X_exp[i]);
	}

	LinearRegression lr2(3, 4, 1);
	lr2.train(X_exp, Y_exp, 10000, 0.1);

	//int size[] = {28 * 28, 100, 100, 10};
	*/

	/*
	ANN network(size, 4);
	*/

	return 0;
}