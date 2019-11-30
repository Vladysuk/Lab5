#include "Mylesson.h"

void InputArray(Array  arr[])
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> arr[i].matrix[j];
		}
}

void OutputArray(Array  arr[])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << setw(5) << arr[i].matrix[j] << "    ";
		cout << endl;
	}
}

void SortColumnsByMergingInDescending(Array arr[], int columns)
{
	for (int i = 0; i < columns; i++)
	{
		for (int sizeIterator = 1; sizeIterator < columns; sizeIterator *= 2)
		{
			for (int iterator = 0; iterator < columns - sizeIterator; iterator += 2 * sizeIterator)
			{
				int leftIterator = 0;
				int rightIterator = 0;
				int leftBorder = iterator;
				int midBorder = iterator + sizeIterator;
				int rightBorder = iterator + 2 * sizeIterator;
				rightBorder = (rightBorder < columns) ? rightBorder : columns;
				int* sortedBlock = new int[rightBorder - leftBorder];

				while (leftBorder + leftIterator < midBorder && midBorder + rightIterator < rightBorder)
				{
					if (arr[leftBorder + leftIterator].matrix[i] > arr[midBorder + rightIterator].matrix[i])
					{
						sortedBlock[leftIterator + rightIterator] = arr[leftBorder + leftIterator].matrix[i];
						leftIterator++;
					}
					else
					{
						sortedBlock[leftIterator + rightIterator] = arr[midBorder + rightIterator].matrix[i];
						rightIterator++;
					}
				}
				while (leftBorder + leftIterator < midBorder)
				{
					sortedBlock[leftIterator + rightIterator] = arr[leftBorder + leftIterator].matrix[i];
					leftIterator++;
				}
				while (midBorder + rightIterator < rightBorder)
				{
					sortedBlock[leftIterator + rightIterator] = arr[midBorder + rightIterator].matrix[i];
					rightIterator++;
				}

				for (int mergeIterator = 0; mergeIterator < leftIterator + rightIterator; mergeIterator++)
				{
					arr[leftBorder + mergeIterator].matrix[i] = sortedBlock[mergeIterator];
				}
				delete sortedBlock;

			}

		}
	}

}

long long int ArrayProductUnderAdditionalDiagonal(Array arr)
{
	long long int product = 1;

	for (int j = 4; j > iterator_; j--)
	{
		cout << arr.matrix[j] << "  ";
		product = product * arr.matrix[j];
	}
	cout << endl << product << endl;
	return product;
}

long long int ArrayAverageUnderAdditionalDiagonal(long long int arrayProduct[])
{
	long long int average = 0;
	for (int i = 0; i < columns; i++)
	{
		average = average + arrayProduct[i] / columns;
	}
	return average;
}

int main()
{
	Array  arr[rows]{}; //Creation of 2-dimension matrix
	cout << "Input elements of Array arr" << endl;
	InputArray(arr);
	cout << "\nInput Array arr " << endl;
	OutputArray(arr);
	SortColumnsByMergingInDescending(arr, columns);
	cout << "\nSorted Array arr " << endl;
	OutputArray(arr);

	cout << "\nProduct of Array under an additional diagonal" << endl;
	long long int arrayProduct[columns]{};
	for (int i = 1; i < rows; i++)
	{
		arrayProduct[i] = ArrayProductUnderAdditionalDiagonal(arr[i]);
		iterator_--;
	}
	cout << "ArrayAverageUnderAdditionalDiagonal = " << ArrayAverageUnderAdditionalDiagonal(arrayProduct) << endl;

	return 0;

