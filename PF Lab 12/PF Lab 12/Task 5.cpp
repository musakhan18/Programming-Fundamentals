#include<iostream>
using namespace std;
int main()
{
	int arr[100], X, Y;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 500;
		cout << i << ")" << arr[i] << endl;
	}
	cout << "X: "; cin >> X;
	cout << "Y: "; cin >> Y;
	int* ptr = &arr[0];
	for (int i = 0; i <100; i++)
	{
		if (i % 2 == 0)
		{
			if (*(ptr+i)>=X&&*(ptr+i)<=Y)
			{
				cout << *(ptr + i) << endl;
			}
		}
	}
}