#include "FillFunctions.h"
#include<fstream>
#include<iostream>

std::vector<int> fillFromFile(std::string fileName) {
	std::ifstream file("input.txt");
	if (!file.is_open()) {
		std::cout << "Can not open the file" << std::endl;
		std::vector<int> vec;
		return vec;
	}
	std::vector<int> vec{ std::istream_iterator<int>(file), std::istream_iterator<int>() };
	file.close();
	return vec;
}

std::vector<int> fillFromCin() {
	int num;
	std::vector<int> vec;
	while (std::cin >> num && num != 0) {
		vec.push_back(num);
	}
	if (vec.back() == 1) {
		std::vector<int>::iterator num;
		for (num = vec.begin(); num != vec.end();) {
			if (*num % 2 == 0) {
				num = vec.erase(num);
			}
			else ++num;
		}
	}
	else if (vec.back() == 2) {
		std::vector<int>::iterator num;
		for (num = vec.begin(); num != vec.end();) {
			if (*num % 3 == 0) {
				num = vec.insert(num + 1, 3, 1);
				num += 3;
			}
			else ++num;
		}
	}

	return vec;
}

void fillRandom(double* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
	}
}