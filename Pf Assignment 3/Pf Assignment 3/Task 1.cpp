#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string* arr=NULL;
string* regrow(string* arry, string value, int size);
int ReadWordByWord(ifstream& file);
string* SaveInReverse(string* arr, int size);
int main()
{
	char* temp=new char [50];
	cout << "Enter name of the file: "; cin >> temp;
	int in = 0;
	while (temp[in]!='\0')
	{
		in++;
	}
	cout << in << endl;
	temp[in] = '.'; temp[in + 1] = 't'; temp[in + 2] = 'x'; temp[in + 3] = 't'; temp[in + 4] = '\0';
	in += 5;
	char* name = new char[in];
	for (int i = 0; i < in; i++)
	{
		name[i]= temp[i];
	}
	delete[]temp;
	ifstream file;
	file.open(name);
	if (file)
	{
		cout << "File opened successfuly....." << endl<<endl;
		cout << "reading Data from file!!" << endl<<endl;
		int size = ReadWordByWord(file);
		cout << "Data in File:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i]<<" ";
		}
		
		string* rev= SaveInReverse(arr, size);
		cout << endl<<endl;
		cout << "Data after reversing:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << rev[i]<<" ";
		}
		cout << endl << endl;;
		char* temp = new char[50];
		cout << "Enter the name of file to save the new data: "; cin >> temp;
		int in = 0;
		while (temp[in] != '\0')
		{
			in++;
		}
		temp[in] = '.'; temp[in + 1] = 't'; temp[in + 2] = 'x'; temp[in + 3] = 't'; temp[in + 4] = '\0';
		in += 5;
		char* oname = new char[in];
		for (int i = 0; i < in; i++)
		{
			oname[i] = temp[i];
		}
		delete[]temp;
		ofstream write;
		write.open(oname);
		if (write)
		{
			cout << "File opened successfuly....." << endl << endl;
			for (int i = 0; i < size; i++)
			{
				write << rev[i] << " ";
			}
			cout << "Data is saved in the file!!" << endl;
		}
		else
		{
			cout << "No such file Exist!!" << endl;
		}
		write.close();
		file.close();
		delete[]arr;
	}	
	else
	{
		cout << "No such file Exist!!" << endl;
	}
	return 0;
}
string* regrow(string* arry, string value, int size)
{
	string* newarr;
	newarr = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arry[i];
	}
	newarr[size] = value;
	delete[]arry;
	return newarr;
}
int ReadWordByWord(ifstream& file)
{
	string read;

	int size = 0;
	arr = new string[size];
	int x = 0;

	while (!file.eof())
	{
		file >> read;
		arr = regrow(arr, read, size);
		size++;
	}

	return size;
}
string* SaveInReverse(string* arr, int size)
{{
	string* rev = new string [size];
	for (int i = 0,j=size-1; i < size,j>=0;j--, i++)
	{
		rev[i] = arr[j];
	}
	return rev;
}}