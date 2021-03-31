#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream in;
    ofstream out;
    in.open("integers.txt");
    if(!in){
        cout<<"File error: opening failed(1).\n";
        exit(0);
    }
    out.open("integerSums.txt");
    if(!out){
        cout<<"File error: opening failed(2).\n";
        exit(0);
    }
    int input;
    int sum=0;
    while(in){
        in >> input;    /// This will read only one int

        if(input == -1){    /// Write one line's sum on sumation file
            out << sum << endl;
            sum=0;          /// make sum zero to get summation of next line
        }
        else{
            sum += input;
        }
    }
    in.close();
    out.close();
	return 0;
}
