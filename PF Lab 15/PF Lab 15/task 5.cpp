#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int arr[100];
	int count=0,in=0;
	ifstream read;
	read.open("data.txt");
	while (!read.eof())
	{
		read >> arr[in];
		if (arr[in]==-99)
		{
			count++;
		}
		in++;
	}
	int countC = 0;
	int* C = new int[count];
	read.close();
	for (int i = 0; i < in; i++)
	{
		
	}
}