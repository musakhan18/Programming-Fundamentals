#include<iostream>
using namespace std;
int** createJaggedDynamic2D(int row, int col[])
{
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[4];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			arr[i][j] = rand()%100;
		}
	}
	return arr;
}
int main()
{
	int r=4, c[4];
	cout << "Enter array" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> c[i];
	}
	int** arr = createJaggedDynamic2D(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c[i]; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}
}