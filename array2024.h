#pragma once
#include<fstream>
#include <iostream>

using std::cout;
using std::endl;
// Тип данных, представляющий собой индексированный массив
// фиксированного размера с элементами типа float
// ЗАМЕЧАНИЕ: индексацию элементов будем начинать с 1 (не с 0 !)
class array2024 {
public:
	array2024() : data(nullptr), size_(0) {}		// конструтор по умолчаию
	array2024(size_t);								// конструктор по размеру
	array2024(const array2024&);					// конструктор копирования
	~array2024();									// деструктор

	bool generate(float inf, float sup);			// заполнение массива
	void clear();									// очистка массива
	void print();									// вывод
	void invert();									// инверсия
	void swap(size_t, size_t);						// "обмен"
	void SaveToFile(const char*);
	void LoadFromFile(const char*);

	float& operator()(size_t i);
	array2024& operator=(const array2024&);
	size_t size() { return size_; }

private:
	bool resize(size_t);
	float* data;
	size_t size_;
};



////// Constructrs ////////
array2024::array2024(size_t n) : data(nullptr), size_(0) { resize(n); }

array2024::array2024(const array2024& A) : data(nullptr), size_(0) {
	if (resize(A.size_))
		for (size_t i = 0; i < size_; ++i) data[i] = A.data[i];
}

array2024::~array2024() { resize(0); }


////// FUNCs /////////

bool array2024::resize(size_t new_size) {
	if (new_size == size_) return true;
	if (data != nullptr) {
		delete[]data;
		data = nullptr;
		size_ = 0;
	}
	if (new_size > 0) {
		try {
			data = new float[new_size];
		}
		catch (...) {
			return false;
		}
		size_ = new_size;
	}
	return true;
}


bool array2024::generate(float inf = 0.0f, float sup = 1.0f) {
	array2024 A(*this);
	if (resize(A.size_)) {
		float K = (sup - inf) / RAND_MAX;
		for (size_t i = 0; i < size_; ++i) data[i] = inf + std::rand() * K;
		return true;
	}
	return false;
}


void array2024::clear() { resize(0); }


void array2024::invert() {
	array2024 A(*this);
	float tmp = data[0];
	for (size_t i = 0; i < A.size_; i++) data[i] = data[(A.size_ - 1) - i];
	data[A.size_ - 1] = tmp;
}


void array2024::swap(size_t i, size_t j) {

	if (i < 1 || j < 1 || i > size_ || j > size_) {
		throw std::out_of_range("Index out of range in swap");
	}

	float tmp = data[i - 1];
	data[i - 1] = data[j - 1];
	data[j - 1] = tmp;
}


void array2024::print() {
	array2024 A(*this);
	for (size_t i = 0; i < A.size_; i++) {
		cout << data[i] << ", ";
		if (((i + 1) % 10) == 0) cout << "\n";
	}

}


void array2024::SaveToFile(const char* filename) {
	if (size_ == 0 || data == nullptr) return;

	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Ошибка при открытии файла!" << std::endl;
		return;
	}

	for (size_t i = 1; i < size_; ++i) {
		file << data[i];
		if (i < size_ - 1) file << '\n';
	}
}

void array2024::LoadFromFile(const char* filename) {
	std::ifstream file(filename);
	if (file) {
		size_t i, n(0);
		float tmp;
		while (file.good()) {
			file >> tmp;
			++n;
		}
		file.seekg(0);
		resize(n);
		for (i = 0; i < size_; ++i) file >> data[i];
	}
}

////// Operators ////////

array2024& array2024::operator=(const array2024& A) {
	if (this != &A) {
		if (resize(A.size_))
			for (size_t i = 0; i < size_; ++i) data[i] = A.data[i];
	}
	return *this;
}



float& array2024::operator()(size_t i) {
	if (i == 0 || i > size_) throw("invalid_index_in_operator()");
	return data[ i - 1];


}





