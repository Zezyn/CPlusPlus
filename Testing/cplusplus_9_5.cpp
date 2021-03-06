/*
Filename: project_9_5.cpp
Problem: Can't get a Dynamic array to work, and am getting seg faults
Author: Martin Hernandez 
Email: 7607920511m.h@gmail.com
Date: 11/20/2015
Description: Each user has a unique five-digit ID number. Whenever a user logs on, the user’s ID, lab  number,
and the computer station number are transmitted to your system. For example, if user 49193 logs onto station 
2 in lab 3, then your system receives (49193, 2, 3) as input data. Similarly, when a user logs off a station,
then your system receives the lab number and the computer station number.

Write a computer program that could be used to track, by lab, which user is logged onto which computer. For 
example, if user 49193 is logged into station 2 in lab 3 and user 99577 is logged into station 1 of lab 4, 
then your system might display the following:

                Lab# Computer Stations
                 1   1: empty 2: empty 3: empty 4: empty 5: empty
                 2   1: empty 2: empty 3: empty 4: empty 5: empty 6:empty
                 3   1: empty 2: 49193 3: empty 4: empty
                 4   1: 99577 2: empty 3: empty

Create a menu that allows the administrator to stimulate the transmission of information by manually typing 
in the login of logoff data. Whenever someone logs in or out, the display should be updated. Also write a 
search option so that the administrator can type in a user ID and the system will output what lab and 
station number that user is logged into, or “None” if the user ID is not logged into any computer station.

You should use a fixed array of length 4 for the labs. Each array entry points to a dynamic array that 
stores the user login information for each respective computer station.
*/


//Add libraries here
#include <iostream>
#include <string>

using namespace std;

const int TOTAL_LABS = 4;
const int TOTAL_STATIONS = 6;


void menu(string &id, int &cstation, int &lab, string labs[][TOTAL_STATIONS]);
void login(string &id, int &cstation, int &lab, string labs[][TOTAL_STATIONS]);
void fillarrays(string &id, int &lab, int &cstation, string labs[][TOTAL_STATIONS]);
void printarrays(string &id, int &cstation, int &lab, string labs[][TOTAL_STATIONS]);
void search(string labs[][TOTAL_STATIONS]);
void logout(string labs[][TOTAL_STATIONS]);

int main() {
    
	string id;
    int cstation;
    int lab;
    string labs[TOTAL_LABS][TOTAL_STATIONS];
	
   	fillarrays(id, cstation, lab, labs);
    menu(id, cstation, lab, labs);
    return 0;
}

void fillarrays(string &id, int &lab, int &cstation, string labs[][TOTAL_STATIONS]) {

    for(int row = 0; row<TOTAL_LABS;row ++) {
		for(int col=0; col<TOTAL_STATIONS; col++) {
			labs[row][col] = "Empty";
		}
    }	
}	
void printarrays(string &id, int &cstation, int &lab, string labs[][TOTAL_STATIONS]) {
	    
	cout << "\nLabs#" << "  " << "Computer Stations" << endl;;
	for(int rows=0 ;rows<TOTAL_LABS;rows++) {
		cout << " " << (rows+1) << ":    ";
	    for(int cols=0; cols<TOTAL_STATIONS;cols++) {
			cout << (cols+1) << ": ";
	        cout << labs[rows][cols] << "     ";
        }	
	cout << endl;
    }
	menu(id, cstation, lab, labs);
}

void menu(string &id, int &cstation, int &lab, string labs[][TOTAL_STATIONS])  {
    int decision = 0;
    do {
		cout << endl << endl << "********************************" << endl;
		cout << endl << "  Welcome to the computer lab." << endl << endl;
		cout << "********************************" << endl;
		cout << "       ((     MENU     ))    " << endl;
		cout << "********************************" << endl << endl;
		cout << "1. Login" << endl;
		cout << "2. Search I.D numbers" << endl;
		cout << "3. Lab Check" << endl;
		cout << "4. Logout" << endl << endl;
		cout << "5. Exit Program" << endl << endl;
		cout << "********************************" << endl << endl;
		cout << "Enter a number: ";
		cin >> decision;
    
        if(decision > 5 || decision <= 0) {
            cout << endl << endl << "Invalid entry." << endl << endl;
			menu(id, cstation, lab, labs);
		}
		else if(decision == 1)
            login(id, cstation, lab, labs);
        else if(decision == 2) 
            search(labs);
        else if(decision == 3)
            printarrays(id, lab, cstation, labs);
		else if(decision == 4)
			logout(labs);
        else if(decision == 5)
            cout << endl << "Exiting Program" << endl;
            return;
    } while(decision = 0);
}

void login(string &id, int &cstation, int &lab, string labs[][TOTAL_STATIONS]) {
   
	int id_len = 5;
   
	cout << endl << "Please enter your 5 digit I.D. Number: ";
	cin >> id;
	
	if(id.length() != id_len) {
		cout << endl << endl << '\t' << "****************************************************" << endl;
		cout << '\t' << "  Invalid ID. Please enter your 5 digit I.D Number" << endl;
		cout << endl << '\t' << "****************************************************" << endl;
		menu(id, cstation, lab, labs);
	}
     
	cout << endl << "Please enter the Lab Number: ";
    cin >> lab;
    if(lab > TOTAL_LABS) {
		cout << endl << '\t' << "****************************************************" << endl;
		cout << '\t' << "Invalid Lab" << endl;
		cout << endl << '\t' << "****************************************************" << endl;
		menu(id, cstation, lab, labs);      
    }
        
    cout << endl << "Please enter the Computer Station Number: ";
    cin >> cstation;
    if(cstation > TOTAL_STATIONS) { 
		cout << endl << '\t' << "****************************************************" << endl;
		cout << '\t' << "Invalid Computer Station" << endl; 
        cout << endl << '\t' << "****************************************************" << endl;
		menu(id, cstation, lab, labs); 
    }
    	
	cout << endl << "You entered: " << id << " Lab: " << lab << " Computer Station: " << cstation << endl << endl << endl;
	
	labs[lab][cstation] = id;
	menu(id, cstation, lab, labs);
}

void search(string labs[][TOTAL_STATIONS]) {
	
	string search;
	string found;
	
	cout << "Please enter ID to search for: ";
	cin >> search;
	
	for(int row = 0; row<TOTAL_LABS;row ++) {
		for(int col=0; col<TOTAL_STATIONS; col++) {
			if(labs[row][col] == search) {
				cout << endl << endl << "*************************" << endl;
				cout << "Lab: " << row << " Computer Station: " << col << endl;
				cout << endl << "*************************" << endl; 
			}
			else { cout << "None" << endl; }
		}
	}
}	
	
void logout(string labs[][TOTAL_STATIONS]) {
	
	string search;
	string found;
	
	cout << "Please enter ID to logout: ";
	cin >> search;
	
	for(int row = 0; row<TOTAL_LABS;row ++) {
		for(int col=0; col<TOTAL_STATIONS; col++) {
			if(labs[row][col] == search) {
				labs[row][col] = "Empty";
			}
		}
	}
}	


