#include<iostream>
using namespace std;
int printASCII(char c)
{
	int askii;
	askii = c;
    cout << askii << endl;
	return askii;
}
int main()
{
	char value;
	cout << "Enter a character: "; cin >> value;
	printASCII(value);
	return 0;
}