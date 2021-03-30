#include<iostream>
#include<fstream>
#include<string>
using namespace std;
char* GenerateRandomWords(int num, int minL, int maxL)
{
	const int size = 10000;
	int Smin, Smax, Smid, Mcount = minL, HowMuch, MxCount = maxL, MdCount = minL + 1, SmidW;
	char max[size], min[size], mid[size], name[size];
	int flag = 0;
	string words[size];
	if (minL+1<maxL||minL%3==0)
	{
		HowMuch = num / 3;
		flag = 1;
	}
	else
	{
		HowMuch = num / 2;
	}
	Smin = HowMuch * minL;
	for (int i = 0; i < Smin; i++)
	{
		min[i] = rand() % 100;
		if (min[i] < 65 || min[i]>90)
		{
			while (min[i] < 65 || min[i]>90)
			{
				min[i] = rand() % 100;
			}
		}
	}
	int SminW = HowMuch;
	for (int i = 0,j=0; i <SminW,j<Smin; i++)
	{
		while (Mcount != 0)
		{
			words[i] += min[j];
			Mcount--;
			j++;
		}
		Mcount = minL;
	}
	if (flag==1)
	{
		Smid = HowMuch * (minL + 1);
		for (int i = 0; i < Smid; i++)
		{
			mid[i] = rand() % 100;
			if (mid[i] < 65 || mid[i]>90)
			{
				while (mid[i] < 65 || mid[i]>90)
				{
					mid[i] = rand() % 100;
				}
			}
		}
	     SmidW = HowMuch * 2;
		for (int i = HowMuch, j = 0; i < SmidW, j < Smid; i++)
		{
			while (MdCount != 0)
			{
				words[i] += mid[j];
				MdCount--;
				j++;
			}
			MdCount = minL+1;
		}
	}
	else
	{
		 SmidW = HowMuch;
	}
	Smax =( HowMuch * maxL)*2;
	for (int i = 0; i < Smax; i++)
	{
		max[i] = rand() % 100;
		if (max[i] < 65 || max[i]>90)
		{
			while (max[i] < 65 || max[i]>90)
			{
				max[i] = rand() % 100;
			}
		}
	}
	for (int i = SmidW, j = 0; i < num, j < Smax; i++)
	{
		while (MxCount != 0)
		{
			words[i] += max[j];
			MxCount--;
			j++;
		}
		MxCount = maxL;
	}
	int s = 0;
	ofstream file;
	file.open("Output.txt");
	if (file)
	{
		for (int i = 0; i < num; i++)
		{
			file << words[i] << " " << endl;
			
		}
		cout << "Data Is Saved Successfully In The File......" << endl << endl;
		file.close();
		return name;
	}
	else
	{
		cout << "No Such File Exist....." << endl;
		return 0;
	}
}
void IdentifyDuplicateWords(string arr[],int size)
{
	int c = 0;
	string arrr[10000];
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[i]==arr[j])
			{
				arrr[c] = arr[i];
				c++;
			}
		}
	}
	cout << "The number of Dublicate Words: " << c << endl;
	cout << "List Of these words is:" << endl;;
	for (int i = 0; i < c; i++)
	{
		cout << arrr[i] << " ";
	}
	cout << endl; 
}
int main()
{
	const int size = 10000;
	int num, min, max,in=0;
	string line,words[size];
	cout << "How many words you want to genrate: "; cin >> num;
	if (num<1000)
	{
		while (num < 1000)
		{
			cout << "Enter more then 1000..." << endl;
			cout << "How many words you want to genrate: "; cin >> num;
		}
	}
	cout << "What should be the min lengh of word: "; cin >> min;
	cout << "What should be the maximum length of word: "; cin >> max;
	cout << endl;
	GenerateRandomWords(num, min, max);
	ifstream file;
	file.open("Output.txt");
	while (file>>line)
	{
		words[in] = line;
		in++;
	}
	IdentifyDuplicateWords(words,in);
	
}
