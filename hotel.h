#ifndef HOTEL_H
#define HOTEL_H

#include"hoteldetails.h"

class hotel : public hoteldeets

{
    int room_no,btimes,ltimes,dtimes,gtimes,rtype;

    int indate,outdate,inmonth,inyear,outyear,outmonth;

    int type;

    int days;

    char name[30],address[100],phone[10];
public:

    hotel()
    {

        gtimes=0;

        btimes=0;

        ltimes=0;

        dtimes=0;
    }

	void sort();				//sorts the room numbers in ascening order

    void main_menu();           //to display the main menu

    void edit();                //to edit the customer record

    void input(int);            //to take input from user

    void show();                //to show the details per record

    void net_bill();            //to show the net bill

    int Rroom_no();             //to return room no of guest

    char * Rname();             //to return name of guest

    char *  Radd();             //to return address of guest

    char * Rphno();             //to return phone number of guest

    void breakfast();           //to bill breakfast

    void lunch();               //to bill lunch

    void Rtype();               //to display type of room

    void dinner();              //to bill a dinner meal

    void wash(int);             //to bill a laundry wash

    void checkindate(int,int,int);  //to take in checkin date

    void checkoutdate(int,int,int); //to take in checkout date

    unsigned long long food_bill(); // to return the net food bill

    unsigned long long wash_bill(); //to return the net laundry bill

    float service_charge_bill();        //to return the net vat bill

    unsigned long long rent_bill();    //calculates and returns rent bill

    int Rindate();                     //returns in date

    int Rinmonth();                    //returns in month

    int Rinyear();                     //returns in year

    int Routdate();                    //returns out date

    int Routmonth();                   //returns out month

    int Routyear();                    //returns out year

    void Gtype(int);                   //stores type of room

    void Gdays(int);                   //number of days

};

#endif
