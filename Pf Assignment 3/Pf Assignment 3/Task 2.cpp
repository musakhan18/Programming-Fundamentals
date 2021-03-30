#include<iostream>
using namespace std;
int* regrow(int* arr,int value, int size);
void displayContents(int arr[], int size);
void SortInAscending(int arr[], int size);
void SortInDescending(int arr[], int size);
int* search(int arr[], int value, int size);
int main()
{
	int temp=0;
	int* arr;
	int size = 0, num, count = 0;
	int* find;
	int* ass;
	int* des;
	arr = new int[size];
	cout << "start Enter Array and press (-1) to finish..." << endl;
	while (temp != -1)
	{
		cin >> temp;
		if (temp!=-1)
		{
			arr = regrow(arr, temp, size);
			size++;
		}
	}
	cout << endl << "Enter any value to be searched: "; cin >> num;
	find = search(arr, num, size);
	cout << endl << "Array Before Sorting Display:" << endl;
	displayContents(arr, size);
	cout << endl;
	SortInAscending(arr, size);
	cout << endl << "Ascending order display:" << endl;
	displayContents(arr, size);
	cout << endl;
	SortInDescending( arr, size);
	cout << endl << "Descending order display:" << endl;
	displayContents(arr, size);
	cout << endl;
	count = find[0];
	if (count >= 1)
	{
		cout << endl << num << " found " << count << " times in the array at indexs" << endl;
		for (int i = 1; i <= count; i++)
		{
			cout << find[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << endl<< num << " is not present int array" << endl;
	}
	delete[]arr;
	return 0;
}
int* regrow(int* arr, int value, int size)
{
	int* newarr;
	newarr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[size] = value;
	delete[]arr;
	return newarr;
}
int* search(int arr[], int value, int size)
{
	int* ind;
	int x = 1;
	ind = new int[x];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			ind=regrow(ind, i, x);
			x++;
		}
	}
	ind[0] = x-1;
	return ind;
}
void displayContents(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
void SortInAscending(int arr[], int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void SortInDescending(int arr[], int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
