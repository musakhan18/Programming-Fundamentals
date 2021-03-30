#include<iostream>
using namespace std;
char* rev(char* arr, int size)
{
	char array[1000];
	for (int i = 0,j=size; i <= size,j>=0; i++,j--)
	{
		array[i] = arr[j];
	}
	return array;
}
int main()
{
	char arr[1000];
	int size = 0;
	cout << "Enter your string: "; cin.getline(arr, 1000);
	while (arr[size]!='\0')
	{
		size++;
	}
	char* ptr = &arr[0];
	char*prt=rev(ptr, size);
	for (int i = 0; i <= size; i++)
	{
		cout << *(prt + i);
	}
}