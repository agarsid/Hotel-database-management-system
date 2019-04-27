#include"hoteldetails.h"
#include"run.h"
using namespace std;

int hoteldeets::cs=0,hoteldeets::csup=0,hoteldeets::cr=0,hoteldeets::cd=0;      //initializing the static variables

void hoteldeets::inputhoteldeets()
{
	cout<<"**CREATING HOTEL DATABASE** \n\n\n";
	cout<<" Enter the number of standard rooms: ";
	cin>>no_standard;
	cout<<"\n Enter the number of deluxe rooms: ";
	cin>>no_deluxe;
	cout<<"\n Enter the number of supreme rooms: ";
	cin>>no_supreme;
	cout<<"\n Enter the number of royal rooms: ";
	cin>>no_royal;
	cout<<"\n Enter the price of a standard room: ";
	cin>>pr_standard;
	cout<<"\n Enter the price of a deluxe room: ";
	cin>>pr_deluxe;
	cout<<"\n Enter the price of a supreme room: ";
	cin>>pr_supreme;
	cout<<"\n Enter the price of a royal room: ";
	cin>>pr_royal;
	cout<<"\n Breakfast price:";
	cin>>breakfast;
	cout<<"\n Lunch price:";
	cin>>lunch;
	cout<<"\n Dinner price:";
	cin>>dinner;
	cout<<"\n Laundry per garment rate:";
	cin>>laundrypg;
}


int hoteldeets::checkcount(int temptype)
{
	int k;
	if(temptype==1)

    {++cs;k=cs;}

    else if(temptype==2)

    {++cd,k=cd;}

    else if(temptype==3)

    {++csup;k=csup;}

    else

    {++cr;k=cr;}
    return k;
}


int hoteldeets::ns()
{
	return no_standard;
}


int hoteldeets::nd()
{
	return no_deluxe;
}


int hoteldeets::nsup()
{
	return no_supreme;
}


int hoteldeets::nr()
{
	return no_royal;
}

int hoteldeets::breakfastpr()
{
	return breakfast;
}

int hoteldeets::lunchpr()
{
	return lunch;
}

int hoteldeets::dinnerpr()
{
	return dinner;
}

int hoteldeets::laundrypgpr()
{
	return laundrypg;
}

int hoteldeets::pricestandard()
{
	return pr_standard;
}

int hoteldeets::pricedeluxe()
{
	return pr_deluxe;
}

int hoteldeets::pricesupreme()
{
	return pr_supreme;
}

int hoteldeets::priceroyal()
{
	return pr_royal;
}
