#include<iostream>
using namespace std;
int sum(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int product(int arr[], int n)
{
	int product = 1;
	for (int i = 0; i < n; i++)
	{
		product *= arr[i];
	}
	return product;
}
int main()
{
	int arr[] = { 4,2,6,8,-4,-9,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "sum = " << sum(arr, n) << endl;
	cout << "product = " << product(arr, n) << endl;
	return 0;
}