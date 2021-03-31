#include<iostream>
#include<fstream>
using namespace std;
char* regrow_cols(char* data, int& size)
{
    char* temp = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    size++;
    delete[]data;
    return temp;
}
char** regrow_row(char** data, int& size)
{
    char** temp = new char* [size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    size++;
    delete[]data;
    return temp;
}
char* linee(ifstream& fin)
{
    char* line = nullptr, letter;
    int size = 0;
    while (fin.get(letter) && letter != '\n')
    {
        line = regrow_cols(line, size);
        line[size - 1] = letter;

    }
    if (size > 0)
    {
        line = regrow_cols(line, size);
        line[size - 1] = '\0';
    }



    return line;
}
void display(char** data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i];
        cout << endl;
    }
}
char** read_file(ifstream& fin, int& rowsize)
{
    char** file = nullptr, * line = nullptr;
    int size = 0;
    line = linee(fin);
    while (line != nullptr)
    {
        file = regrow_row(file, size);
        file[size - 1] = line;



        line = linee(fin);



    }
    /*if (size > 0)
    {
        file = regrow_row(file, size);
        file[size - 1] = '\0';
    }
*/
    rowsize = size;
    return file;
}
int main()
{
    ofstream file;
    file.open("Text.txt");
    file << "My name is musa" << endl;
    file << "Im a student" << endl;
    file << "I do study" << endl;
    file.close();

    char** data = nullptr;
    int rowsize = 0;
    ifstream fin;
    fin.open("Text.txt", ios::in);
    data = read_file(fin, rowsize);
    display(data, rowsize);
    fin.close();

    return 0;
}