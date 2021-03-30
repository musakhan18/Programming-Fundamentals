#include<iostream>
using namespace std;
int** createDynamic2D(int row, int col)
{
	int** arr = new int* [row];
	for (int i = 0; i < row ; i++)
	{
		arr[i] = new int[col];
	}
	return arr;
}
int main()
{
	int r=0, c=0;
	cout << "Enter Rows: "; cin >> r;
	cout << "Enter coloumns: "; cin >> c;
	int** base = createDynamic2D( r,  c);
	cout << "Base Address: " << base << endl;
}