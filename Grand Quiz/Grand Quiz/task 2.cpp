#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	char name[100],Nwords[1000];
	string words;
	int s = 0,in=0,ind[1000];
	cout << "Enter name of file: "; cin.getline(name, 100);
	ifstream file;
	file.open(name);
	if (file)
	{
		while (!file.eof())
		{
			file >> words[in];
			if (words[in] == ' ' || words[in] == ',' || words[in] == ';')
			{

				ind[s] = s;
				s++;
			}
			in++;
		}
			
	}
	for (int i = 0; i < in; i++)
	{
		if (i!=ind[i])
		{
			Nwords[i] = words[i];
		}
		cout << Nwords[i];
	}
	
	cout <<endl<< s + 1;
}