#include<iostream>
#include<fstream>
using namespace std;

int SaveInFile(int** arr, int r, int c[]);

int main()
{
	int row, c;
	cout << "Enter number of Rows: "; cin >> row;
	int** arr = new int* [row];
	int* col = new int[row];
	for (int i = 0; i <row; i++)
	{
		cout << "Enter no. of columns in Row "<<i+1<<" :"; cin >> col[i];
		arr[i] = new int[col[i]];
		for (int j = 0; j < col[i]; j++)
		{
			arr[i][j] = rand() % 888 + 100;
		}
	}
	int sum = SaveInFile(arr, row, col);
	cout << endl;
	cout << "Array contents and Data is successfully saved in output.txt. " << endl;
}

int SaveInFile(int** arr, int r, int c[])
{
	int sum=0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c[i]; j++)
		{
			sum += arr[i][j];
		}
	}
	ofstream file;
	file.open("output.txt");
	for (int i = 0; i < r; i++)
	{
		file << "Row-" << i + 1 << " ";
		for (int j = 0; j < c[i]; j++)
		{
			file << arr[i][j] << " ";
		}
		file << endl;
	}
	file << endl;
	file << "Sum = " << sum << endl;
	return sum;
}