#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int count(char word);
int main()
{
	char word;
	int times = 0;
	cout << "Kindly enter the character whos count you want to know:\t"; cin >> word;
	times = count(word);
	cout << endl;
	if (times > 0)
	{
		cout << word << " found " << times << " times in the file" << endl;
	}
}
int count(char word)
{
	ifstream read;
	read.open("name.txt");
	int counter = 0;
	if (!read)
	{
		cout << "ERROR!!" << endl;
		cout << "File not Exist" << endl;
	}
	else
	{
		string arr;
		while (!read.eof())
		{
			getline(read, arr);
			/*int s = arr.size();
			if (arr[s]==word)
			{
				counter++;
			}*/
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i] == word)
				{
					counter++;
				}
			}
		}
	}
	return counter;
}