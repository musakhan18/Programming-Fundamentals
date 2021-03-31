#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream in; /// this will be used "to read" from files.

    /*  open a file:
        in.open() opens a file if it already exists
        but if file not exists, then this call does not creats a new file
    */
    in.open("MyFirstFile.txt");

    /* It is always a good practice to check, whether file opens or not
       to check this use as following
       In C++ some flags are auto attached to instances of ofstream/ifstream
       that's why, the following if-condition works.

    */
    if(!in){
        cout<<"File error: opening failed.\n";
        exit(0);
    }

    /// buffer to contain input from file

    char input[100]; /// you can use char array as well

    /* Now, read from file,
       for reading use "in" with conjuction of ">>" operator.
       reading will be done from file as "in" is attached to physical file.

    */
    cout<<"Data read from file:\n";
    while(in){ /// This will continue reading till the end of file.

        in >> input;    /// This will read until first white space is found.

        /// Display on console

        cout<<input<<" ";
    }
    cout<<endl;


    /*
        It is also a good practice to close files after you finish with them.
    */

    in.close();

	return 0;
}
