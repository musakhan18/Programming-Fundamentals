#include<iostream>
int* SortAscending(int arr[], int count)
{
	int temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}
using namespace std;

int main()
{
	int arr[100], count = 0;
	
	for (int i = 0; i < 100; i++)
	{
		arr[i]=rand();
		count++;
	}
	int* res;
	SortAscending(arr, count);
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
}