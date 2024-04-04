#include"InsertionSort.h"

template<class T>
void insertionSortSquareBrakets(std::vector<T>& arr) {
	if (arr.size() > 1) {
		for (int i = 1; i < arr.size(); i++) {
			int j = i;
			while (j > 0 && arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
				j--;
			}
		}
	}
}

void insertionSortAtOperator(std::vector<int>& arr) {
	if (arr.size() > 1) {
		for (int i = 1; i < arr.size(); i++) {
			int j = i;
			while (j > 0 && arr.at(j) < arr.at(j - 1)) {
				std::swap(arr.at(j), arr.at(j - 1));
				j--;
			}
		}
	}
}


void insertionSortIterator(std::vector<int>& arr) {
	if (arr.size() > 1) {
		std::vector<int>::iterator current = arr.begin() + 1;
		std::vector<int>::iterator temp;
		for (current; current != arr.end(); ++current) {
			temp = current;
			while (temp != arr.begin() && *(temp - 1) > *temp) {
				std::swap(*temp, *(temp - 1));
				--temp;
			}
		}
	}
}