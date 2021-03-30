#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int calculateFileSize(char name[])
{
	string s;
	int size = 0;
	ifstream file;
	file.open("name");
	{
		while (getline(file, s))
		{
			size =size+ s.size();
		}
	}
	cout << "the total numbers of chars are: " << size << endl;
	return size;
}
int main()
{
	char name[] = { "inputfile.txt" };
	calculateFileSize(name);
}