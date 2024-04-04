#include"InsertionSort.h"
#include"FillFunctions.h"
#include<chrono>
#include<algorithm>
#include<iostream>

void printVector(const std::vector<int>& arr) {
	std::vector<int>::const_iterator element = arr.begin();
		for (element; element != arr.end(); element.operator++()) {
			std::cout << *element << " ";
	}
		std::cout << std::endl;
}


int main(int argc, char* argv[]) {

	std::string inputFile = "input.txt";
	std::vector<int> vec1 = {12, 4, -5, 1, 0};
	std::vector<int> vec2 = vec1;
	//Чтение вектора из файла
	std::vector<int> vec3 = fillFromFile(inputFile);
	std::vector<int> vec4 = vec1;
	std::vector<int> vec5;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	//Сортировка вставками с использованием оператора доступа к элементам []
	start = std::chrono::steady_clock::now();
	insertionSortSquareBrakets(vec1);
	end = std::chrono::steady_clock::now();
	printVector(vec1);
	std::cout << "Insertion sort with brakets access: " << (end-start).count() << " s." << std::endl;

	//Сортировка вставками с использованием оператора доступа at()
	start = std::chrono::steady_clock::now();
	insertionSortAtOperator(vec2);
	end = std::chrono::steady_clock::now();
	printVector(vec2);
	std::cout << "Insertion sort with at access: " << (end - start).count() << " s." << std::endl;

	//Сортировка вставками с доступом по итераторам
	start = std::chrono::steady_clock::now();
	insertionSortIterator(vec3);
	end = std::chrono::steady_clock::now();
	printVector(vec3);
	std::cout << "Insertion sort with iterator access: " << (end - start).count() << " s." << std::endl;

	//Встроенная сортировка
	start = std::chrono::steady_clock::now();
	std::sort(vec4.begin(), vec4.end());
	end = std::chrono::steady_clock::now();
	printVector(vec4);
	std::cout << "Built-in std::sort : " << (end - start).count() << " s." << std::endl;

	//Чтение элементов в вектор из стандартного потока ввода
	std::cout << "Print elements to insert into the vector. 0 is \"end of input\" character." << std::endl;
	vec5 = fillFromCin();
	printVector(vec5);

	//Заполнение вектора псевдослучайными числами в диапазоне [-1, 1]
	std::vector<int> sizes = { 5, 10, 25, 50, 100 };

	for (int size : sizes) {
		std::vector<double> vec6(size);
		fillRandom(vec6.data(), size);

		std::cout << "Random-filled vector before sorting:" << std::endl;
		for (double val : vec6) {
			std::cout << val << " ";
		}
		std::cout << std::endl;

		insertionSortSquareBrakets(vec6);

		std::cout << "Random-filled vector after sorting:" << std::endl;
		for (double val : vec6) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}