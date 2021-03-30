#include<iostream>
using namespace std;
int Cprime(int n)
{
		bool isPrime = true;
		if (n <= 1)
		{
			isPrime = false;
		}

		for (int i = 2; i < n  ; ++i)
		{
			if (n % i == 0)
			{
				isPrime = false;
			}
		}
		if (isPrime)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
}
int main()
{
	int num;
	cout << "Enter a number: "; cin >> num;
	Cprime(num);
	return 0;
}