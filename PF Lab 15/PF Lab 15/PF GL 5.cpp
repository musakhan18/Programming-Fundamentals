#include<iostream>
using namespace std;
void FillArrayRandomly(int arr[][5])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = rand() % 50 + 50;
		}
	}
}
void SortRowWise(int arr[][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < col - j - 1; k++)
			{
				if (arr[i][k]<arr[i][k+1])
				{
					int temp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = temp;
				}
			}
		}
	}
}
void display(int arr[][5])
{
	cout << "array after sorting" << endl;
	cout << "-----------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int arr[3][5];
	FillArrayRandomly(arr);
	cout << "array before sorting" << endl;
	cout << "-----------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	SortRowWise(arr, 3, 5);
	display(arr);
	return 0;
}