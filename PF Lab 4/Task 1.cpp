#include<iostream>
using namespace std;
int table(int x)
{
	for (int i = 1; i <=10 ; i++)
	{
		cout << x << " X " << i << " = " << x * i << endl;
	}
	return x;
}
int main()
{
	int num;
	cout << "Enter the number of which table you want: "; cin >> num;
	table(num);
	return 0;
}