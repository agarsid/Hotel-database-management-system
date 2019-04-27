#ifndef HOTELDETAILS_H
#define HOTELDETAILS_H

#include<fstream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class hoteldeets
{
public:
	int noofroom,no_standard,no_deluxe,no_supreme,no_royal;
	static int cs,cd,csup,cr;                              //the values are updated across all classes
	int breakfast,lunch,dinner,laundrypg;
	int pr_standard,pr_deluxe,pr_supreme,pr_royal;
		int checkcount(int);                               //checks if the maximum number of room of a particular type have been filled
		int ns();                                          //returns number of standard rooms
		int nd();                                          //returns number of deluxe rooms
		int nsup();                                        //returns number of supreme rooms
		int nr();                                          //returns number of royal rooms
		int breakfastpr();                                 //returns breakfast price
		int lunchpr();                                     //returns lunch price
		int dinnerpr();                                    //returns dinner price
		int laundrypgpr();                                 //returns laundry price
		int pricestandard();                               //returns price of standard room
		int pricedeluxe();                                 //returns price of deluxe room
		int pricesupreme();                                //returns price of supreme room
		int priceroyal();                                  //returns price of royal room
		void inputhoteldeets();                            //inputs the details of the hotel from admin                               
};

#endif
