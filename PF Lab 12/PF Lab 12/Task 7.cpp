#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int arr[100];
	int size = 0;
	ifstream file;
	file.open("Input.txt");
	while (!file.eof())
	{
		file >> arr[size];
		size++;
	}
	int* ptr = &arr[0];
	for (int i = 0; i < size; i++)
	{
		*(ptr + i) *= 2;
	}
	ofstream write;
	write.open("Input.txt");
	for (int i = 0; i < size; i++)
	{
		write << *(ptr + i)<<endl;
	}
}