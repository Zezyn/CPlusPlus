/*
    Filename: bitshifting.cpp
    Problem:
    Author: Martin Hernandez 
    Email: 7607920511m.h@gmail.com
    Date: 11/03/2015
    Description: 
*/
//Add libraries here
#include <iostream>

using namespace std;

//Declare functions here

//Declare global variables here

int main() {
    
    unsigned int f=0x1;
    while(f > 0)
    {
         cout << f << endl;
        f<<= 0x1;
    }
    return 0;
}

//Insert user defined functions here

