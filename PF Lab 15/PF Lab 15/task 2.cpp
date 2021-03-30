#include<iostream>
using namespace std;
int** createDynamic2D(int row, int col)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	return arr;
}
void poulateDynamic2D(int** a, int row, int col)
{
	cout << "Enter Array" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> a[i][j];
		}
	}
}
int main()
{
	int r = 0, c = 0;
	cout << "Enter Rows: "; cin >> r;
	cout << "Enter coloumns: "; cin >> c;
	int** base = createDynamic2D(r, c);
	cout << "Base Address: " << base << endl;
	poulateDynamic2D(base, r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << base[i][j]<<" ";
		}
		cout << endl;
	}
}