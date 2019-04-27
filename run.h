#ifndef RUN_H
#define RUN_H

using namespace std;



void create();          //to store details of the hotel in a file

void initialize();      // initializes the values of global variables everytime the code is run 

void check_in();        //to book a room

void check_out();       //to leave a room

void display();         //to display the customer record

void rooms();           //to display allotted rooms

int check(int);         //to check room status

int checkID(char [10]);    // to check HKID

void modify(int); //to modify the record

void delete_rec(int); //to delete a record



#endif