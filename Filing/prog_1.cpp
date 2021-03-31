#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(){

    ofstream out; /// this will be used "to write" to files.

    /*  open a file:
        out.open() opens a file if it already exists
        but if file not exists, then this call creats a new file in the same directory.
    */
    out.open("MyFirstFile.txt");

    /* It is always a good practice to check, whether file opens or not
       to check this use as following
       In C++ some flags are auto attached to instances of ofstream/ifstream
       that's why, the following if-condition works.

    */
    if(!out){
        cout<<"File error: opening failed.\n";
        exit(0);
    }
    char input[50];
    cout<<"Enter some input which you want to send to file: ";
    cin>>input;

    /* Now, write to file,
       for writing use "out" with conjuction of "<<" operator.
       wrting will be on file as "out" is attached to physical file.

    */

    out << input;

    /*
        It is also a good practice to close files after you finish with them.
    */

    out.close();
    /*
        Go to same directory (from your program is running) and see
        whether there is a file namely "MyFirstFile.txt".
        Also observe its contents.
    */
	return 0;
}
