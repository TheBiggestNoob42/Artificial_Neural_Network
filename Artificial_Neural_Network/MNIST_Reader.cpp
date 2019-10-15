#include "MNIST_Reader.h"
#define NORMALIZING_CONSTANT 255.0

vector<vector<NUMS>> MNIST_Reader::mnist_images(bool is_train)
{
	auto reverseInt = [](int number) {
		unsigned char c1, c2, c3, c4;
		c1 = number & 255, c2 = (number >> 8) & 255, c3 = (number >> 16) & 255, c4 = (number >> 24) & 255;

		return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
	};

	vector<vector<NUMS>> mat;
	if (is_train) {
		mat = vector<vector<NUMS>>(number_of_training_sets);
		if (!input_train_data.is_open()) {
			input_train_data.open("train-images.idx3-ubyte", ios::binary);
		}

		int magic_number = 0, n_rows = 0, n_cols = 0, number_of_images = 0;
		input_train_data.read((char*)& magic_number, sizeof(magic_number)), magic_number = reverseInt(magic_number);

		if (magic_number != IMAGE_MAGIC) { __debugbreak(); }

		input_train_data.read((char*)& number_of_images, sizeof(number_of_images)), number_of_images = reverseInt(number_of_images);
		input_train_data.read((char*)& n_rows, sizeof(n_rows)), n_rows = reverseInt(n_rows);
		input_train_data.read((char*)& n_cols, sizeof(n_cols)), n_cols = reverseInt(n_cols);

		if (number_of_images != 60000) {
			cerr << "ERROR: NUMBER OF IMAGES IN TRAINING DATA SET MEASURED AT " << number_of_images <<
				" INSTEAD OF 60,000" << endl;
			__debugbreak();
		}

		int image_size = n_rows * n_cols;

		char c;
		for (int i = 0; i < number_of_training_sets; i++) {
			try {
				mat[i] = vector<NUMS>(n_rows * n_cols);
			} catch (std::bad_alloc &e) {
				cout << "Wassup with it; it's the system's fault" << endl;
			}
			for (int j = 0; j < n_rows * n_cols; j++) {
				input_train_data.read((char*)& c, sizeof(c)), mat[i][j] = (double)((int)c) / NORMALIZING_CONSTANT;
			}
			cout << endl;
		}

		input_train_data.close();

		return mat;
	} else {
		mat = vector<vector<NUMS>>(number_of_testing_sets);
		if (!input_test_data.is_open()) {
			input_test_data.open("t10k-images.idx3-ubyte", ios::binary);
		}

		int magic_number = 0, n_rows = 0, n_cols = 0, number_of_images;
		input_test_data.read((char*)& magic_number, sizeof(magic_number)), magic_number = reverseInt(magic_number);

		if (magic_number != LABEL_MAGIC) { __debugbreak(); }

		input_test_data.read((char*)& number_of_images, sizeof(number_of_images)), number_of_images = reverseInt(number_of_images);
		input_test_data.read((char*)& n_rows, sizeof(n_rows)), n_rows = reverseInt(n_rows);
		input_test_data.read((char*)& n_cols, sizeof(n_cols)), n_cols = reverseInt(n_cols);

		if (number_of_images != 10000) {
			cerr << "ERROR: NUMBER OF IMAGES IN TESTING DATA SET MEASURED AT " << number_of_images <<
				" INSTEAD OF 10,000" << endl;
			__debugbreak();
		}

		int image_size = n_rows * n_cols;

		char c;
		for (int i = 0; i < number_of_testing_sets; i++) {
			mat[i] = vector<NUMS>(n_rows * n_cols);
			for (int j = 0; j < n_rows * n_cols; j++) {
				input_test_data.read((char*)& c, sizeof(c)), mat[i][j] = (double)((int)c) / NORMALIZING_CONSTANT;
			}
		}


		return mat;
	}
}

vector<vector<NUMS>> MNIST_Reader::mnist_labels(bool is_train)
{
	auto reverseInt = [](int number) {
		unsigned char c1, c2, c3, c4;
		c1 = number & 255, c2 = (number >> 8) & 255, c3 = (number >> 16) & 255, c4 = (number >> 24) & 255;

		return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
	};

	if (is_train) {
		vector<vector<NUMS>> mat = vector<vector<NUMS>>(number_of_training_sets);
		if (!input_train_label.is_open()) {
			input_train_label.open("train-labels.idx1-ubyte", ios::binary);
		}

		int magic_number = 0, number_of_labels = 0;
		input_train_label.read((char*)& magic_number, sizeof(magic_number)), magic_number = reverseInt(magic_number);

		if (magic_number != LABEL_MAGIC) { __debugbreak(); }

		input_train_label.read((char*)& number_of_labels, sizeof(number_of_labels)), number_of_labels = reverseInt(number_of_labels);

		if (number_of_labels != 60000) {
			cerr << "ERROR: NUMBER OF LABELS IN TRAINING LABEL SET MEASURED AT " << number_of_labels <<
				" INSTEAD OF 60,000" << endl;
			__debugbreak();
		}

		char c;
		int f;
		for (int i = 0; i < number_of_training_sets; i++) {
			mat[i] = vector<NUMS>(10);
			input_train_label.read((char*)& c, sizeof(c)), f = (int)c;
			for (int j = 0; j < 10; j++) {
				mat[i][j] = 0.0;
			}
			mat[i][f] = 1.0;
		}
		return mat;
	}
	else {
		vector<vector<NUMS>> mat = vector<vector<NUMS>>(number_of_testing_sets);
		if (!input_test_label.is_open()) {
			input_test_label.open("t10k-labels.idx1-ubyte", ios::binary);
		}

		int magic_number = 0, number_of_labels = 0;
		input_test_label.read((char*)& magic_number, sizeof(magic_number)), magic_number = reverseInt(magic_number);

		if (magic_number != LABEL_MAGIC) {	__debugbreak();	}

		input_test_label.read((char*)& number_of_labels, sizeof(number_of_labels)), number_of_labels = reverseInt(number_of_labels);

		if (number_of_labels != 10000) {
			cerr << "ERROR: NUMBER OF LABELS IN TESTING LABEL SET MEASURED AT " << number_of_labels <<
				" INSTEAD OF 10,000" << endl;
			__debugbreak();
		}

		char c;
		int f;
		for (int i = 0; i < number_of_training_sets; i++) {
			mat[i] = vector<NUMS>(10);
			input_train_label.read((char*)& c, sizeof(c)), f = (int)c;
			for (int j = 0; j < 10; j++) {
				mat[i][j] = 0.0;
			}
			mat[i][f] = 1.0;
		}
		return mat;
	}
}

MNIST_Reader::MNIST_Reader(int n_of_train_set, int n_of_test_set)
{
	number_of_training_sets = n_of_train_set;
	number_of_testing_sets = n_of_test_set;

	input_train_data = ifstream("train-images.idx3-ubyte", ios::binary);
	input_train_label = ifstream("train-labels.idx1-ubyte", ios::binary);

	input_test_data = ifstream("t10k-images.idx3-ubyte", ios::binary);
	input_test_label = ifstream("t10k-labels.idx1-ubyte", ios::binary);
}

MNIST_Reader::~MNIST_Reader()
{
	if (input_train_data.is_open())
		input_train_data.close();

	if (input_train_label.is_open())
		input_train_label.close();

	if (input_test_data.is_open())
		input_test_data.close();

	if (input_test_label.is_open())
		input_test_label.close();
}

vector<vector<NUMS>> MNIST_Reader::get_training_images()
{
	return mnist_images(true);
}

vector<vector<NUMS>> MNIST_Reader::get_training_labels()
{
	return mnist_labels(true);
}
