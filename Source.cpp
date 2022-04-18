/*
Написать перегруженные функции и проте-
стировать их в основной программе:
■ Нахождения максимального значения в одномерном
массиве; Нахождения максимального значения в двумерном
массиве;
■ Нахождения максимального значения в трёхмерном
массиве;
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void createElements(int* pElements, int const SIZE) {
	for (int i = 0; i < SIZE; i++) {
		*(pElements + i) = rand() % 11 + 1;
	}
}

void createElements(int** pElements, int const SIZE) {
	for (int i = 0; i < SIZE; i++) {
		*(pElements + i) = new int[SIZE];
		createElements(*(pElements + i), SIZE);
	}
}



void showElements(int* pElements, int const SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << *(pElements + i) << " ";
	}
	cout << endl;
}
void showElements(int** pElements, int const SIZE) {
	for (int i = 0; i < SIZE; i++) {
		showElements(*(pElements + i), SIZE);
	}
}



int* maxNumderElements(int* pElements, int const SIZE) {
	int* max = pElements;
	for (int i = 1; i < SIZE; i++) {
		if (*(pElements + i) > *max) {
			*max = *(pElements + i);
		}
		return max;
	}
};

int* maxNumderElements(int** pElements, int const SIZE) {
	int* max = *pElements;
	for (int i = 1; i < SIZE; i++) {
		if (*max < *maxNumderElements(*(pElements + i), SIZE)) {
			*max = *maxNumderElements(*(pElements + i), SIZE);
		}
	}
	return max;
};

void deleteElements(int* pElements, int const SIZE) {
	delete[] pElements;
}

void deleteElements(int** pElements, int const SIZE) {
	for (int i = 0; i < SIZE; i++) {
		deleteElements(*(pElements + i), SIZE);
	}
	delete[] pElements;
}

int main() {
	setlocale(LC_ALL, "RUS");
	
	srand(time(NULL));

	int const SIZE = 10;

	int* elements = new int[SIZE];
	int** twoElements = new int*[SIZE];
	int*** tryElements = new int** [SIZE];

	// Одномерный массив
	createElements(elements, SIZE);
	showElements(elements, SIZE);
	cout << "\nМаксимальный элемент: " << *maxNumderElements(elements, SIZE);
	deleteElements(elements, SIZE);
	
	// Двумерный массив
	createElements(twoElements, SIZE);
	showElements(twoElements, SIZE);
	cout << "\nМаксимальный элемент: " << *maxNumderElements(twoElements, SIZE);
	deleteElements(twoElements, SIZE);


	return 0;
}