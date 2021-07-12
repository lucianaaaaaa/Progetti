//position.cpp
//how to use file-position pointers

#include <iostream>
#include <fstream>
using std::cout; using std::endl;
using std::cerr;
using std::ifstream; using std::ofstream;
using std::ios;

int main () {
    char* buffer = NULL;
    int length = 0;

    { //inner scope for is
    ifstream is("hello.txt");
    if (!is) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    is.seekg(0, ios::end); //move to end of file
    length = is.tellg(); 
    is.seekg(0, ios::beg); //move to beginning

    buffer = new char [length];

    //read file from pointer to length and store in buffer
    is.read (buffer,length);
    } //is goes out of scope and closes

    { //inner scope for os
    ofstream os ("hello2.txt");

    if (!os) {
        cerr << "Error opening file" << endl;
        delete [] buffer;
        return 1;
    }

    os.write(buffer,length);
    delete[] buffer;
    } //os goes out of scope and closes

}