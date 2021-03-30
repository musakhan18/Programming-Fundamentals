#include <iostream>
using namespace std;
int main()
{
	int arr[10], arr2[10], num, find, times=0;
	bool flag = 0;
	cout << "Enter array." << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the number you want cheak in the array: "; cin >> num;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == num)
		{
			arr2[times] = i;
			times++;
			flag = 1;
		}
	}
	cout << endl;
	if (flag)
	{
		cout << num<<" is present " << times << " times in the array." << endl;
		cout << "The indexes at which"<<num<<" is present are: " << endl;
		for (int i = 0; i < times-1; i++)
		{
			cout << arr2[i] << ",";
		}
	}
	else
	{
		cout << "Your respected number is not present in the array." << endl;
	}
	return 0;
}