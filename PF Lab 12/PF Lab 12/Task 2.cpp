#include<iostream>
using namespace std;
int* cube(int arr[])
{
	for (int i = 0; i < 50; i++)
	{
		arr[i] = arr[i] * arr[i] * arr[i];
	}
	return arr;
}
int main()
{
	int arr[50];
	for (int i = 0; i < 50; i++)
	{
		arr[i] = rand() % 100;
		if (arr[i]<50||arr[i]>99)
		{
			while (arr[i] < 50 || arr[i]>99)
			{
				arr[i] = rand() % 100;
			}
		}
	}
	int* ptr =cube(arr);
	for (int i = 0; i < 50; i++)
	{
		cout << *ptr+i << endl;
	}
	return 0;
}