#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	string line,words[100];
	int i = 0, j = 0;
	ifstream file;
	file.open("check.txt");
	while (file>>line)
	{
		
			words[j] = line;
			j++;
		
	}
	
	for (int i = 0; i < j; i++)
	{
		cout << words[i] << " ";
	}
}