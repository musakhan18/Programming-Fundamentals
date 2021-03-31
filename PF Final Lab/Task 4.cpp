#include <iostream>
#include<fstream>
using namespace std;
void print(char*, int, int);
int* for_column(int*);
int counting_letter(char** ary, int rows, char letter, int* col)
{
    int counter = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j <= col[i]; ++j)
        {
            if (ary[i][j] == letter)
            {
                counter++;
            }
        }
    }
    return counter;
}
int main()
{
    char letter = '\0';
    int counter = 0;
    int rows = 0;
    int* col = new int[rows];
    char var = '\0';
    col = for_column(col);
    char* ptr = NULL;
    char** ary = new char* [rows];
    ifstream fin;
    fin.open("data.txt");
    fin >> rows;
    for (int i = 0; i < rows; i++)
    {
        int column = col[i] + 1;
        ptr = new char[column];
        fin.getline(ptr, column);
        ary[i] = ptr;
    }
    fin.close();
    cout << "ENTER THE LETTER YOU WANT TO GET COUNT OF : "; cin >> letter;
    counter = counting_letter(ary, rows, letter, col);
    cout << "count = " << counter;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j <= col[i]; ++j)
        {
            cout << ary[i][j];
        }
        cout << endl;
    }

    //deleting memory allocated
    for (int i = 0; i < rows; ++i)
    {
        delete[] ary[i];
    }
    delete[] ary;
    delete[] col;



    return 0;
}







int* for_column(int* col)
{
    char temp[10000];
    int index = 0;
    int counter = 0;
    ifstream fin;
    fin.open("data.txt");
    while (fin.getline(temp, 99999))
    {
        counter = 0;
        for (int i = 0; i < temp[i] != '\0'; i++)
        {

            counter++;
        }
        col[index] = counter;
        index++;
    }
    fin.close();
    return col;
}