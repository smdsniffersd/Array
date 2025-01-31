#include <iostream>
#include "array2024.h"
#include "sort1.h"
#include "intro.h"
#include <ctime>
#include <chrono> 
#include <fstream> 
#include <Windows.h>
using std::cout;
using std::endl;

void probel();

int main()
{



	setlocale(LC_ALL, ".1251");


	intro();
	clock_t t;
	size_t size_, var = 1;
	size_t size_factor = 30000 * var;
	size_t iter_count = 30;
	size_ = size_factor;
	iter_count = iter_count++;

	float totalBubbleSortTime = 0.0f;
	float totalSelectSortTime = 0.0f;
	float totalInsertSortTime = 0.0f; 


	array2024 A(size_), B(size_), BubbleSortTime(iter_count), SelectSortTime(iter_count), InsertSortTime(iter_count), Size(iter_count), Iterations(iter_count);

	A.generate(0.1, 2);


	array2024 F(10);
	F.generate();
	F.print();
	InsertSort(F);
	F.print();
	InsertSort(F, false);
	F.print();

	for (size_t iter = 0; iter < iter_count; ++iter) {
		progressbar(iter, iter_count);
		size_t size = size_factor * iter;
		Size(iter + 1) = size;
		Iterations(iter + 1) = iter;
		B = A;
		t = clock();
		BubbleSort(B);
		t = clock() - t;
		totalBubbleSortTime += float(t) / CLOCKS_PER_SEC;
		BubbleSortTime(iter + 1) = totalBubbleSortTime;
	}
	for (size_t iter = 0; iter < iter_count; ++iter) {
		progressbar(iter, iter_count);
		B = A;
		t = clock();
		SelectSort(B);
		t = clock() - t;
		totalSelectSortTime += float(t) / CLOCKS_PER_SEC;
		SelectSortTime(iter + 1) = totalSelectSortTime;
	}
	for (size_t iter = 0; iter < iter_count; ++iter) {
		progressbar(iter, iter_count);
		B = A;
		t = clock();
		InsertSort(B);
		t = clock() - t;
		totalInsertSortTime += float(t) / CLOCKS_PER_SEC;
		InsertSortTime(iter + 1) = totalInsertSortTime;
	}

		

	BubbleSortTime.SaveToFile("BubbleSortTime.txt");
	SelectSortTime.SaveToFile("SelectSortTime.txt");
	InsertSortTime.SaveToFile("InsertSortTime.txt");
	Iterations.SaveToFile("Iterations.txt");
	Size.SaveToFile("Size.txt");

}


















































	//setlocale(LC_ALL, ".1251");
	//clock_t t;
	//intro();
	//
	//size_t size, var = 1;
	//size_t size_factor = 15 * var; // множитель размера массива
	//size_t iter_count = 30; // кол-во итераций
	//size = size_factor;
	//array2024 A(size), B(size), BubbleSortTime(iter_count);
	//

	////create array
	//A.generate(1, 2);
	////BubbleSort
	//std::cout << "BubbleSore.1" << std::endl;
	//clock_t start_time = clock();
	//BubbleSort(A, true);
	//clock_t end_time = clock(); //  онец измерени€ времени
	//cout << end_time << endl;
	//BubbleSortTime = float(end_time - start_time) / CLOCKS_PER_SEC;
	//BubbleSortTime.print();
	//BubbleSortTime.SaveToFile("BubbleSortTime.txt");
	//A.print();
	//probel();
	//std::cout << "BubbleSore.2" << std::endl;
	//BubbleSort(A, false);
	//A.print();

	//probel();
	//probel();

	////SelectSort
	//std::cout << "SelectSort.1" << std::endl;
	//t = clock();
	//SelectSort(A, true);
	//t = clock() - t;
	//BubbleSortTime = float(t) / CLOCKS_PER_SEC;
	//BubbleSortTime.SaveToFile("SelectTime.txt");
	//A.print();
	//probel();
	//std::cout << "SelectSort.2" << std::endl;
	//SelectSort(A, false);
	//A.print();

	//probel();
	//probel();

	////InsertSort
	//std::cout << "InsertSort.1" << std::endl;
	//t = clock();
	//InsertSort(A, true);
	//t = clock() - t;
	//BubbleSortTime = float(t) / CLOCKS_PER_SEC;
	//BubbleSortTime.SaveToFile("InsertTime.txt");
	//A.print();
	//probel();
	//std::cout << "InsertSort.2" << std::endl;
	//InsertSort(A, false);
	//A.print();











	/*t = clock();
	BubbleSort(A, true);
	A.print();
	t = clock() - t;
	BubbleSortTime(iter_count) = float(t) / CLOCKS_PER_SEC;
	BubbleSortTime.SaveToFile("time.txt");

	probel();

	BubbleSort(B, false);
	B.print();*/


	//for (size_t iter = 1; iter <= iter_count; ++iter)
	//{
	//	cout << "¬ыполн€етс€ " << iter << "-€ итераци€ из " << iter_count << endl;
	//	size = size_factor * iter; 
	//	Size(iter) = size;
	//	A.generate(size);
	//	// тестирование пузырька
	//	B = A;
	//	t = clock();
	//	BubbleSort(B);
	//	t = clock() - t;
	//	BubbleSortTime(iter) = float(t) / CLOCKS_PER_SEC;


	//	//тестирование алгоритма выбора элемента
	//	B = A;
	//	t = clock();
	//	SelectSort(B);
	//	t = clock() - t;
	//	SelectSortTime(iter) = float(t) / CLOCKS_PER_SEC;


	//	//тестирование вставок 
	//	B = A;
	//	t = clock();
	//	InsertSort(B);
	//	t = clock() - t;
	//	InsertSortTime(iter) = float(t) / CLOCKS_PER_SEC;

	//	cout << "size = \t" << size << "\t [b]time = " << BubbleSortTime(iter) << endl;
	//	cout << "size = \t" << size << "\t [s]time = " << SelectSortTime(iter) << endl;
	//	cout << "size = \t" << size << "\t [i]time = " << InsertSortTime(iter) << endl;
	//	cout << "\t\t\t\t\ttotal time= " << BubbleSortTime(iter) + SelectSortTime(iter) + InsertSortTime(iter) << endl;
	//}
	//Size.SaveToFile("size.txt");

	//BubbleSortTime.SaveToFile("BubbleTime.txt");
	//SelectSortTime.SaveToFile("SelectSort.txt");
	//InsertSortTime.SaveToFile("InsertSortTime.txt");



void probel() {

	cout << "\n\n";

}