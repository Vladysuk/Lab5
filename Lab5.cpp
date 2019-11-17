#include "Mylesson.h"

//�-�� ����� ������
void InputArray(Array  A[])
{
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> A[i].arr[j];
		}
}

//�-�� ������ ������
void OutputArray(Array  A[])
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
			cout << setw(5) << A[i].arr[j] << "    ";
		cout << endl;
	}
}

//�-�� ���������� �������� ������ ������� �� ��������
void SortColsByMergingInDescending(Array A[], int Cols)
{
	for (int i = 0; i < Cols; i++)
	{
		for (int SizeIterator = 1; SizeIterator < Cols; SizeIterator *= 2)
		{
			for (int Iterator = 0; Iterator < Cols - SizeIterator; Iterator += 2 * SizeIterator)
			{
				int LeftIterator = 0;
				int RightIterator = 0;
				int LeftBorder = Iterator;
				int MidBorder = Iterator + SizeIterator;
				int RightBorder = Iterator + 2 * SizeIterator;
				RightBorder = (RightBorder < Cols) ? RightBorder : Cols;
				int* SortedBlock = new int[RightBorder - LeftBorder];

				while (LeftBorder + LeftIterator < MidBorder && MidBorder + RightIterator < RightBorder)
				{
					if (A[LeftBorder + LeftIterator].arr[i] > A[MidBorder + RightIterator].arr[i])
					{
						SortedBlock[LeftIterator + RightIterator] = A[LeftBorder + LeftIterator].arr[i];
						LeftIterator++;
					}
					else
					{
						SortedBlock[LeftIterator + RightIterator] = A[MidBorder + RightIterator].arr[i];
						RightIterator++;
					}
				}
				while (LeftBorder + LeftIterator < MidBorder)
				{
					SortedBlock[LeftIterator + RightIterator] = A[LeftBorder + LeftIterator].arr[i];
					LeftIterator++;
				}
				while (MidBorder + RightIterator < RightBorder)
				{
					SortedBlock[LeftIterator + RightIterator] = A[MidBorder + RightIterator].arr[i];
					RightIterator++;
				}

				for (int MergeIterator = 0; MergeIterator < LeftIterator + RightIterator; MergeIterator++)
				{
					A[LeftBorder + MergeIterator].arr[i] = SortedBlock[MergeIterator];
				}
				delete SortedBlock;

			}

		}
	}

}

//�-��, �� ���� ������� ��. �� ��������� ���������
long long int FooProduct(Array A)
{
	long long int Product = 1;

	for (int j = 4; j > k; j--)
	{
		cout << A.arr[j] << "  ";
		Product = Product * A.arr[j];
	}
	cout << endl << Product << endl;
	return Product;
}
//�-��, �� ���� �����.�����������
long long int FooAvg(long long int ArrayProduct[])
{
	long long int Avg = 0;
	for (int i = 0; i < Cols; i++)
	{
		Avg = Avg + ArrayProduct[i] / Cols;
	}
	return Avg;
}

int main()
{
	Array  A[Rows]{}; // ��������� 2-������ ������
	cout << "Input elements of Array A" << endl;
	InputArray(A);
	cout << "\nInput Array A " << endl;
	OutputArray(A);
	SortColsByMergingInDescending(A, Cols);
	cout << "\nSorted Array A " << endl;
	OutputArray(A);

	cout << "\nProduct of Array A under additional " << endl;
	long long int ArrayProduct[Cols]{};// ��������� ������, �� ������� ������� ��. �� ��������� ���������
	for (int i = 1; i < Rows; i++)
	{
		ArrayProduct[i] = FooProduct(A[i]);
		k--;
	}
	cout << "FooAvg = " << FooAvg(ArrayProduct) << endl;

	return 0;

}
