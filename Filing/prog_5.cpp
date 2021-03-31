#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream in;
    ofstream out;
    in.open("strings.txt");
    if(!in){
        cout<<"File error: opening failed(1).\n";
        exit(0);
    }
    out.open("stringsCopy.txt");
    if(!out){
        cout<<"File error: opening failed(2).\n";
        exit(0);
    }
    string buffer;
    while(in){
        getline(in,buffer,'|'); /// This will read until '|'


        out << buffer << '\n' ;
    }
    in.close();
    out.close();
	return 0;
}
