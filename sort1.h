#pragma once

#include"array2024.h"


// Реализует алгоритм пузырьковой сортировки
// dir -- флаг направления сортировки
// по умолчанию dir = true -- сортировка по возрастанию
void BubbleSort(array2024& A, bool dir = true) {
	size_t n = A.size() + 1;
	for (size_t end = n; end > 0; --end) {
		for (size_t i = 2; i < end; ++i) {
			if (dir) {
				if (A(i) < A(i - 1)) {
					A.swap(i, i - 1);
				}
			}
			else {
				if (A(i) > A(i - 1)) {
					A.swap(i, i - 1);
				}
			}
		}
	}
}

void SelectSort(array2024& A, bool dir=true) {
	size_t i, pos, n;
	float temp;
	for (n = A.size(); n > 1; --n) {
		for (pos = 1, temp = A(pos), i = 2; i <= n; ++i) {
			if (dir) {
				if (temp < A(i)) {
					pos = i;
					temp = A(pos);
				}
			}
			else {

				if (temp > A(i)) {
					pos = i;
					temp = A(pos);
				}

			}
		}
		A.swap(pos, n);
	}
}

void InsertSort(array2024& A, bool dir=true) {


	size_t i, j, n = A.size();

	for (i = 2; i <= n; ++i) {
		j = i;
		while (j > 1) {
			if (dir) {
				if (A(j - 1) > A(j)) {
					A.swap(j, j - 1);
					--j;
				}
				else j = 1;
			}
			else {
				if (A(j) > A(j-1)) {
					A.swap(j, j - 1);
					--j;
				}
				else j = 1;


			}
		}
	}
}