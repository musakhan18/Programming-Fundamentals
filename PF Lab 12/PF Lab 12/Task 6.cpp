#include<iostream>
using namespace std;
int main()
{
	int num = 4;
	int* ptr = &num;
	cout << "Increment operation: " << ptr++ << endl;
	cout << "Decrement operation: " << ptr-- << endl;
	cout << "Increment on dereferenced pointer: " << ++(*ptr) << endl;
	cout << "decrement on dereferenced pointer: " << --(*ptr) << endl;
	cout << "Add N in pointer and display pointer address: " << ptr + 2 << endl;
	cout << "Add N in pointer and display its value: " << *ptr + 2 << endl;
	cout << "Subtract N in pointer and display pointer address: " << ptr - 2 << endl;
	cout << "Subtract N in pointer and display its value: " << *ptr - 2 << endl;
	return 0;
}