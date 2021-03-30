#include<iostream>
using namespace std;
char performanceCalculator(int* marks)
{
	
	if (*marks >= 85)
	{
		*marks = 'A';
	}
	else if (*marks >= 80)
	{
		*marks = 'Bp';
	}
	else if (*marks >= 75)
	{
		*marks = 'B';
	}
	else if (*marks >= 70)
	{
		*marks = 'C';
	}
	else if (*marks >= 65)
	{
		*marks = 'D';
	}
	else if (*marks >= 60)
	{
		*marks = 'E';
	}
	else if (*marks < 60)
	{
		*marks = 'F';
	}
	return *marks;
}
int main()
{
	int English, Urdu, Maths, Gsci;
	float* arr[4];
	cout << "English: "; cin >> English;
	int* eng = &English;
	cout << "Urdu: "; cin >> Urdu;
	int* urd = &Urdu;
	cout << "Maths: "; cin >> Maths;
	int* math = &Maths;
	cout << "Gsci: "; cin >> Gsci;
	int* gsci = &Gsci;
	cout << endl;
	cout << "English: " << performanceCalculator(eng) << endl;
	cout << "Urdu: " << performanceCalculator(urd) << endl;
	cout << "Maths: " << performanceCalculator(math) << endl;
	cout << "Gsci: " << performanceCalculator(gsci) << endl;
}