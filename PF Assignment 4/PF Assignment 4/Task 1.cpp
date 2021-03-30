#include<iostream>
using namespace std;
int** createDynamic2D(int row, int col)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(arr+i) = new int[col];
	}
	return arr;
}

void poulateDynamic2D(int** a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Enter Row " << i+1 << " Col " << j+1 << endl; cin >> *(*(a + i) + j);
		}
	}
}

int** Multiply(int** mul, int** arr1, int** arr2, int row1, int col1, int col2)
{
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			*(*(mul+i)+j) = 0;
		}
	}
	for (int i = 0; i < row1; ++i)
	{
		for (int j = 0; j < col2; ++j)
		{
			for (int k = 0; k < col1; ++k)
			{
				*(*(mul+i)+j) += *(*(arr1+i)+k) * *(*(arr2+k)+j);
			}
		}
	}
	return mul;
}

void display(int** arr, int R, int C)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << *(*(arr+i)+j) << " ";
		}
		cout << endl;
	}
}

int main()
{
	int row1 = 0, col1 = 0, row2, col2;

	cout << "Enter Rows of matrix 1: "; cin >> row1;
	cout << "Enter coloumns of matrix 1: "; cin >> col1;

	int** arr1 = createDynamic2D(row1, col1);
	cout << endl;

	cout << "Enter Rows of matrix 2: "; cin >> row2;
	cout << "Enter coloumns of matrix 2: "; cin >> col2;
	while (row2!=col1)
	{
		cout << "Invalid Input!" << endl;
		cout << "Rows of matrix 2 must be equal coloumns of matrix 1!" << endl;
		cout << "Enter Rows of matrix 2: "; cin >> row2;
		cout << "Enter coloumns of matrix 2: "; cin >> col2;
	}

	int** arr2 = createDynamic2D(row2, col2);
	cout << endl;

	cout << "Enter matrinx 1" << endl;
	poulateDynamic2D(arr1, row1, col1);
	cout << endl;

	cout << "Enter matrinx 2" << endl;
	poulateDynamic2D(arr2, row2, col2);
	cout << endl;

	int** mul = createDynamic2D(row1, col2);
	mul = Multiply(mul, arr1, arr2, row1, col1, col2);

	cout << "matrix 1:" << endl;
	display(arr1, row1, col1);
	cout << endl;
	cout << "matrix 2:" << endl;
	display(arr2, row2, col2);
	cout << endl;
	cout << "Product:" << endl;
	display(mul, row1, col2);
	cout << endl;
	return 0;
}