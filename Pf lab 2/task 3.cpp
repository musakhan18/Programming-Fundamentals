#include<iostream>
using namespace std;
int main()
{
	char string[20];
	int size = 0;
	bool flag = 0;
	cout << "Enter your string: "; cin >> string;
	size = strlen(string);
	for (int i = 0; i < size; i++)
	{
		if (string[i] != string[size - i - 1])
		{
			flag = 1;
		}
	}
	if (flag)
	{
		cout << string << " is not a palindrome" << endl;
	}
	else
	{
		cout << string << " is a palindrome" << endl;
	}
	return 0;
}