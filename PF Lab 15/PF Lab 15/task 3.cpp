#include<iostream>
using namespace std;
void freeDynamic2D(int**& a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}
int main()
{
	int row = 4, col = 4;
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	cout << "Enter array" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}
	freeDynamic2D(arr, row, col);
	
}