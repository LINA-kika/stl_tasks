#include <iostream>
#include <fstream>
#include <string>


int distinctSymbols(const char* source, size_t size) {
	int count = 0;
	bool isUnique;

	for (int i = 0; i < size; i++) {
		bool isUnique = true;

		for (int j = 0; j < i; j++) {
			if (source[i] == source[j]) {
				isUnique = false;
				break;
			}
		}

		if (isUnique) {
			count++;
		}
	}

	return count;
}

int distinctSymbols(const std::string& source) {
	int count = 0;
	bool isUnique;

	for (int i = 0; i < source.length(); i++) {
		isUnique = true;
		for (int j = 0; j < i; j++) {
			if (source[i] == source[j]) {
				isUnique = false;
				break;
			}
		}

		if (isUnique) {
			count++;
		}
	}

	return count;
}


int main() {

	std::ifstream file("C:/Users/alina/source/repos/SymbolFind/SymbolFind/input.txt");
	std::string cppString = "";
	size_t stringSize;
	if (!file.is_open())
	{
		std::cerr << "File can not be opened\n";
		return 1;
	}

	
	try {
		while (!file.eof()) {
			file >> stringSize;
			file >> std::ws;
			char* cString = new char[stringSize + 1];
			file.getline(cString, stringSize + 1);
			cppString = std::string(cString);
			std::cout << "Amount of distinct symbols in ";
			for (int i = 0; i < stringSize + 1; i++) std::cout << *(cString + i);
			std::cout << " (cString): " << distinctSymbols(cString, stringSize) << "\n";
			std::cout << "Amount of distinct symbols in " << cppString << " (cppString): " << distinctSymbols(cppString) << "\n";
			delete[] cString;
		}
	}
	catch (...) {
		std::cout << "Array allocation error/n";
	}
	
	file.close();

}