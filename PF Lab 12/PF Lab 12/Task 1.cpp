#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* ptr = &arr[0];
	for (int i = 0; i < 10; i++)
	{
		cout << *ptr + i << endl;
	}
	return 0;
}