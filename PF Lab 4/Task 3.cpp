#include<iostream>
using namespace std;
void calculatPower(int b,int p)
{
	int result=1;
	for (int i = 1; i <=p ; i++)
	{
		result *= b;
	}
	cout << b << "^" << p << " = " << result;
}
int main()
{
	int base, power;
	cout << "Enter base value: "; cin >> base;
	cout << "Enter power value: "; cin >> power;
	calculatPower(base, power);
	return 0;
}
