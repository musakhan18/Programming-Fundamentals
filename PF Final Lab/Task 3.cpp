#include<iostream>
#include<fstream>
using namespace std;
int* regrow(int* arr, int num, int size);
int count(int* arr, int s, int num)
{
	int flag = 0;
	for (int i = 0; i < s; i++)
	{

		if (arr[i] == num)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}

	}
	return flag;
}
int main()
{
	int* arr;
	int size = 0;
	 arr = new int[size];
	 int flag = 0;
	ifstream file;
	file.open("input.txt");
	if (file)
	{
		while (flag != 1)
		{
			file >> arr[size];
			arr = regrow(arr, arr[size], size);
			if (arr[size]==-99)
			{
				flag = 1;
			}
			size++;
		}

		for (int i = 0; i < size; i++)
		{
			int f = 0;
			int counter = 1;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] == arr[j])
				{
					counter++;
				}
			}
			int num = arr[i];
			f = count(arr, i, num);
			if (f == 0&&arr[i]!=-99)
			{
				cout << arr[i] << "\t" << counter << endl;
			}
		}
	}
}

int* regrow(int* arr, int num, int size)
{
	int* newarr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[size] = num;
	return newarr;
}
