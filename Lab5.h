#pragma once
#include <iostream>
#include <iomanip> // used for setw function which inserts each element into a specific cell 
using namespace std;

const int columns = 5;
const int rows = 5;

int iterator_ = 3;

//Class's creation of 1-dimension matrix 
class Array
{
private:
	long long int matrix[columns];
public:

	friend void InputArray(Array  arr[]);
	friend void OutputArray(Array  arr[]);
	friend void SortColumnsByMergingInDescending(Array  arr[], int columns);
	friend long long int ArrayProductUnderAdditionalDiagonal(Array arr);
};
