#include<iostream>
using namespace std;
int calculateBill(int Cbill, int Pbill, int units)
{ 
	float bill;
	if (Cbill>Pbill)
	{
		bill = Cbill - Pbill;
	}
	else
	{
		bill = Pbill - Cbill;
	}
	bill *= units;
	bill -= 10 / 100;
	cout << bill;
	return bill;
}
int main()
{
	int Cbill, Pbill;float Units;
	cout << "Enter current Bill: "; cin >> Cbill;
	cout << "Enter Previous Bill: "; cin >> Pbill;
	cout << "Enter unit price: "; cin >> Units;
	calculateBill(Cbill, Pbill, Units);
}