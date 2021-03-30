#include<iostream>
#include<fstream>
#include<string>
using namespace std;

char chart;
string line;
ifstream file;
int TotalWords = 0, RelatedWords = 0;
string sup[354];
int con = 0;

void GetUserInput()
{
	char name[443];
	cout << "Enter your file name: ";
	cin.getline(name, 100);
	cout << "Enter the character who's words you want to search: ";
	cin >> chart;
	file.open(name);
	if (!file)
	{
		cout << "ERROR!!" << endl;
		cout << "File dont exist" << endl;
	}
	/*else
	{
		getline(file, line);
	}*/
	
}
void ProessFile(char chart, string line)
{
	getline(file, line);
	int count = 0, counter = 0;
	int size = line.size();
	string words[453];
	string arr[344];
	/*string sup[354];*/
	/*int TotalWords = 0, RelatedWords = 0;*/

	for (int i = 0; i < size; i++)
	{
		if (line[i] == ' ')
		{
			TotalWords++;
		}
	}
	TotalWords += 1;
	for (int i = 0; i < size; i++)
	{
		if (line[i] == chart && line[i - 1] == ' ')
		{
			while (line[i] != ' ')
			{
				words[count] = line[i];
				arr[counter] += words[count];
				i++;
				count++;
			}
			counter++;
			RelatedWords++;
		}

		else if (line[i] != chart)
		{

			if (line[i] != ' ')
			{
				i++;
			}
		}
	}
	////	/cout << size;/
	////	cout << count << endl;
	//cout << counter << endl;
	//cout << count << endl;
	/*for (int i = 0; i < counter; i++)
	{
		cout << arr[i] << " ";
	}*/
	int  ind[100], lrn = 0;
	string uni[324];
	bool flag = 1;
	for (int i = 0; i < counter; i++)
	{
		for (int j = i + 1; j < counter; j++)
		{
			if (arr[i] == arr[j])
			{
				///*sup[con] = arr[i];*/
				//ind[con] = i;
				//con++;
				flag = 0;
			}
		}
		if (flag)
		{
			sup[con] = arr[i];
			con++;
		}
	}
	/*for (int i = 0; i < con; i++)
	{
		if (ind[i] == i)
		{
			sup[lrn] = arr[i];
			lrn++;
		}
	}*/
	/*for (int i = 0; i < con; i++)
	{
		
			
			cout << sup[i] << " ";
		
	}*/
	/*DisplayOuput(TotalWords, RelatedWords, sup);*/
}
void DisplayOuput(int Twords, int Rwords, string sup[],int lrn)
{
	cout << "------------------------------------" << endl;
	cout << "Total words found: " << Twords << endl;
	cout << "Total Related words found: " << Rwords << endl;
	cout << "List of (Unique)words is given below: " << endl;
	for (int i = 0; i <lrn ; i++)
	{
		cout << sup[i] << endl;
	}
}


int main()
{
	GetUserInput();
	ProessFile(chart, line);
	DisplayOuput(TotalWords, RelatedWords, sup, con);
	return 0;
}

