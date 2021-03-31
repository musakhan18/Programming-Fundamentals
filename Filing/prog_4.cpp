#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream in;
    ofstream out;
    in.open("chars.txt");
    if(!in){
        cout<<"File error: opening failed(1).\n";
        exit(0);
    }
    out.open("charsASCII.txt");
    if(!out){
        cout<<"File error: opening failed(2).\n";
        exit(0);
    }
    char input;
    int ascii;
    while(in){
        in >> input;    /// This will read only one char

        ascii = input;

        out << ascii << endl ;
    }
    in.close();
    out.close();
	return 0;
}
