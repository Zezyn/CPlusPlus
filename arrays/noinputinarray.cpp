/*
    Filename: testscores.cpp
    Problem:
    Author: Martin Hernandez 
    Email: 7607920511m.h@gmail.com
    Date: 10/27/2015
    Description: Arrays in class 
*/

#include <iostream>

using namespace std;
int const SIZE=500;
int main() {
    //Declare An array of 6 variables
    //int score[SIZE];
    //int ar[] = {23,45,23,45};
    //char s[] = {'a','b','c','d','e','f','g','\0'};
    int mysize;
    cout << "Enter the size: ";
    cin >> mysize;
    int score[mysize];
    score[0] = 90;
    score[1] = 89;
    score[2] = 80;
    score[3] = 70;
    score[4] = 60;

    for(int i=0; i<5;i++)

        //cout << (score[i] + 1) << " ";
        score[i] += 1;

        for(int i=0;i<SIZE;i++) //columns
        {
            cout << (score[i] + 1) << " ";
            if( (i+1) % 5 == 0 )
                cout << endl;
        }

    cout << endl;

    char word[6];
    word[0] = 'h';
    word[1] = 'e';
    word[2] = 'l';
    word[3] = 'l';
    word[4] = 'o';
    word[5] = '\0';

   // cout << word << endl;
    //cout << score << endl;

    return 0;
}
