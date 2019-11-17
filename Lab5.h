#pragma once
#include <iostream>
#include <iomanip> // для ф-ії setw, що вставляє кожний ел. в певну комірку

using namespace std;

const int Cols = 5;
const int Rows = 5;

int k = 3;//

//Створення класу 1-мірного масиву
class Array
{
private:
	long long int arr[Cols];
public:

	friend void InputArray(Array  A[]);
	friend void OutputArray(Array  A[]);
	friend void SortColsByMergingInDescending(Array  A[], int l);
	friend long long int FooProduct(Array A);
};
