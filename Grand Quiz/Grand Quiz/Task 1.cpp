#include<iostream>
#include<fstream>
using namespace std;
void cheak(int arr[],int count)
{
	int num[1000],c=0;
	for (int i = 0; i < count; )
	{
		if (arr[i]==arr[i+1])
		{
			while (arr[i]==arr[i+1])
			{
				num[c] = arr[i];
				i++;
			}
			c++;
		}
		else
		{
			i++;
		}
	}
	for (int i = 0; i < c; i++)
	{
		cout << num[i] << endl;
	}
}
int main()
{
	
	int  in = 0, array[1000];
	int arr[1000];
	ifstream file;
	file.open("Data.txt");
	while (!file.eof())
	{
		file>> arr[in];
		in++;
	}
	int count = 0;
	for (int i = 0; i < in; i++)
	{
		int rem;
		while (arr[i] != 0)
		{
			rem = arr[i] % 10;
			array[count] = rem;
			arr[i] /= 10;
			count++;
		}
	}
	cheak(array, count);
	return 0;
}