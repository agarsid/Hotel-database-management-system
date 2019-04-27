#include"hotel.h"
#include"hoteldetails.h"
#include"run.h"

using namespace std;

int breakfastprice,lunchprice,dinnerprice,laundryprice,standard_room,deluxe_room,supreme_room,royal_room;

#define CHM M>12 || M<1

#define CHY Y>2025 || Y<2019

#define CHD1 D<1 || M==1 && D>31 || M==2 && (Y%4)==0 && D>29 || M==2 && (Y%4)!=0 && D>28 || M==3 && D>31

#define CHD2 M==4 && D>30 || M==5 && D>31 || M==6 && D>30 || M==7 && D>31 || M==8 && D>31 || M==9 && D>30

#define CHD3 M==10 && D>31 || M==11 && D>30 || M==12 && D>31

int D,M,Y,ERR=0;        //day,month,year,error
//const unsigned char BLACK = 219;

unsigned long long hotel::food_bill()

{
    return (days*(breakfastprice*btimes+lunchprice*ltimes+dinnerprice*dtimes));
}


unsigned long long hotel::wash_bill()
{
    return (gtimes*laundryprice);
}

unsigned long long hotel::rent_bill()
{
    if(type==1)
        return (standard_room*days);
    
    else if(type==2)
        return (deluxe_room*days);
    
    else if(type==3)
        return (supreme_room*days);
    
    else
        return (royal_room*days);
}

void hotel::net_bill()
{
    if(type==1)
        cout<<"\t Hotel Rent = "<<days<<" * "<<standard_room<<" = "<<rent_bill()<<endl;
    else if(type==2)
        cout<<"\t Hotel Rent = "<<days<<" * "<<deluxe_room<<" = "<<rent_bill()<<endl;
    else if(type==3)
        cout<<"\t Hotel Rent = "<<days<<" * "<<supreme_room<<" = "<<rent_bill()<<endl;
    else 
        cout<<"\t Hotel Rent = "<<days<<" * "<<royal_room<<" = "<<rent_bill()<<endl;
            
    cout<<"\t Laundry Charges = "<<gtimes<<" * "<<laundryprice <<" = "<<wash_bill()<<endl;

    cout<<"\t Breakfast Charges = "<<days*btimes<<" * "<< breakfastprice<<" = "<<days*btimes*breakfastprice<<endl;

    cout<<"\t Lunch Charges = "<<days*ltimes<<" * "<<lunchprice<<" = "<<days*ltimes*lunchprice<<endl;

    cout<<"\t Dinner Charges = "<<days*dtimes<<" * "<<dinnerprice<<" = "<<days*dtimes*dinnerprice<<endl;

    cout<<"\t Service Charge @ 10% = "<<service_charge_bill()<<endl;

    cout<<"\n TOTAL     AMOUNT      PAYABLE "<<service_charge_bill()+rent_bill()+wash_bill()+food_bill();   //prints total bill of the customer
}


void check_in()

{
    ifstream deets("hoteldeets.dat",ios::binary); //opening file hoteldeets.dat to read pricing of rooms
    //clearscreen();
    int r,flag;

    hotel s,c; //objects of class hotel

    hoteldeets h; //objects of class hoteldeets

    deets.read((char*)&h,sizeof(h));

    long int temp;

    cout<<"Enter the date(ddmmyyyy): ";

    cin>>temp;

    do

    {

        if(ERR==1)

        {

            cout<<"Invalid data format. Try again."<<endl;

            cout<<"Enter the date(ddmmyyyy): ";

            cin>>temp;

        }

        D=(temp/1000000);

        M=(temp/10000)%100;

        Y=(temp%10000);

        ERR=1;

    }while((CHM)||(CHD1)||(CHD2)||(CHD3)||(CHY));

    s.checkindate(Y,M,D); //storing check-in date

    ERR=0;

    cout<<"\n 1.Standard at HKD"<<standard_room<<" per night \n 2.Deluxe at HKD"<<deluxe_room<<" per night \n 3.Supreme at HKD"<<supreme_room<<" per night \n 4.Royal at HKD"<<royal_room<<" per night \n";

    int temptype;
    cout << " Enter room type: ";
    cin>>temptype;

    while(temptype<1 || temptype > 4)

    {

        cout << "Wrong Selection.\nEnter room type:\n";

        cin>>temptype;

    }

    s.Gtype(temptype); //storing room type in object s

    cout<<"\nENTER CUSTOMER DETAILS";

    cout<<"\n----------------------";

    cout<<"\nRooms Booked: ";

    fstream rom("Record.dat",ios::binary|ios::in);

    int chk=0; //counter to check if any rooms are booked

    while(rom.read((char*)&c,sizeof(c)))

    {

        chk=1;

        cout<<endl<<" "<<c.Rroom_no()<<"   "<<c.Rname();

    }

    if(chk==0)

        cout<<"None.";

    cout<<"\n\nRoom no: ";

    cin>>r;

    flag=check(r); // check if room is already occupied

    ofstream fout("Record.dat",ios::app|ios::binary);

    if(flag)

    {
            cout<<"\nRoom is already booked.";
    }
    else

    {
        if(temptype==1)
        {
            if(h.checkcount(temptype)<=h.ns()) // to check whether that category of room is available
            {
                s.input(r);
                fout.write((char*)&s,sizeof(s));

                cout<<"\nRoom is booked.";
                //system("pause");
            }
            else
                cout<<"All rooms of this category are booked";
        }
        else if(temptype==2)
        {
            if(h.checkcount(temptype)<=h.nd()) // to check whether that category of room is available
            {
                s.input(r);
                fout.write((char*)&s,sizeof(s));

                cout<<"\nRoom is booked.";
                //system("pause");

            }
            else
                cout<<"All rooms of this category are booked";


        }
        else if(temptype==3)
        {
            if(h.checkcount(temptype)<=h.nsup()) // to check whether that category of room is available
            {
                s.input(r);
                fout.write((char*)&s,sizeof(s));

                cout<<"\nRoom is booked.";
                //system("pause");

            }
            else
                cout<<"All rooms of this category are booked";

        }
        else if(temptype==4)
        {
            if(h.checkcount(temptype)<=h.nr()) // to check whether that category of room is available
            {
                s.input(r);
                fout.write((char*)&s,sizeof(s));

                cout<<"\nRoom is booked.";
                //system("pause");

            }
            else
                cout<<"All rooms of this category are booked";

        }

        else

        {
            cout<<"This category of rooms is full.";
        }

    }
    c.sort(); //sorting the file in ascending order of room numbers
    fout.close();

}



void check_out()

{

    //clearscreen();

    int r,flag=0;

    int tdays=0;// number of days spent in hotel

    cout<<"\n Enter room number to be checked out: ";

    cin>>r;

    ifstream fin("Record.dat",ios::binary|ios::app);

    ofstream fout("temp.dat",ios::binary);

    ofstream his("History.dat",ios::binary|ios::app); //stores deleted records

    hotel s; //object of hotel

    if(fin) ;  //check
        while(fin.read((char*)&s,sizeof(hotel))) //reading data from file dynamically

        {

            if(s.Rroom_no()==r)

            {

                char ch;

                s.show(); //showing customer details
                do
                {

                        cout<<"\n Do you want to check out  (y/n)"<< endl; // y for Yes, n for No

                        cin>>ch;

                        if(ch=='y')

                        {

                            long long temp;

                            cout<<"    Mr."<<s.Rname()<<"    checked in on "<<s.Rindate()<<"/"<<s.Rinmonth()<<"/"<<s.Rinyear();

                            cout<<"\n Enter date (ddmmyyyy) of check-out: ";

                            cin>>temp;

                            do

                            {

                                if(ERR==1)

                                {

                                    cout<<"Invalid date format. Try again."<<endl;

                                    cout<<"\nEnter date (ddmmyyyy) of check-out: ";

                                    cin>>temp;

                                }

                                D=(temp/1000000);

                                M=(temp/10000)%100;

                                Y=temp%10000;

                                ERR=1;

                            }while(CHM||CHD1||(CHD2)||(CHD3)||CHY);



                            s.checkoutdate(Y,M,D);

                            ERR=0;

                            if((s.Routmonth()==s.Rinmonth())&&(s.Routyear()==s.Rinyear()))

                            {

                                tdays=s.Routdate()-s.Rindate();

                                s.Gdays(tdays); //storing total days in object s

                            }

                            else

                            {

                                int n=s.Routmonth()-s.Rinmonth(),k=s.Routyear()-s.Rinyear();

                                tdays=s.Routdate()-s.Rindate()+(n*30)+(k*365); //Assumption that number of months will be multiplied by 30 and number of years by 365

                                s.Gdays(tdays);

                            }

                            s.net_bill(); //calculating total bill

                            cout<<"\n\n\tRecord deleted.";

                            flag=1;

                            his.write((char*)&s,sizeof(hotel));

                        }

                        else if (ch=='n')

                        {

                            cout<<"Not checked out.";
                            flag=1;
                            fout.write((char*)&s,sizeof(hotel));

                        }

                        else
                        {

                            cout <<"Invalid Choice." <<endl;

                        }

                }while(ch!='y' && ch!='n');

            }

            else

                fout.write((char*)&s,sizeof(hotel));

        }

    fin.close();

    fout.close();

    if(flag==0)

        cout<<"\nSorry rooom number not found or vacant.";

    else

    {

        remove("Record.dat");

        rename("temp.dat","Record.dat"); // Record deleted from Record.dat

    }

}



void display()

{

    //clearscreen();

    fstream fin("Record.dat",ios::in|ios::out|ios::binary);

    int r,flag=0;

    cout<<"\nEnter room number: ";

    cin>>r; //stores room number

    hotel s,c;

    hoteldeets h;

    fstream F("hoteldeets.dat",ios::binary|ios::in);

    F.read((char*)&h,sizeof(h));

    long int pos;

    while(fin.read((char*)&s,sizeof(hotel))) //reading data dynamically

    {

        pos= long(fin.tellg())-long(sizeof(s)); //finds the starting position of the class

        if(s.Rroom_no()==r) // display details if room is alloted

        {

            //clearscreen();

            cout<<"\n Customer Details";

            cout<<"\n ----------------";

            s.show();

            cout<<"\n 1.Breakfast @ "<<h.breakfastpr() <<" per head";

            cout<<"\n 2.Lunch     @ "<<h.lunchpr() <<" per head";

            cout<<"\n 3.Dinner    @ "<<h.dinnerpr()<<" per head";

            cout<<"\n 4.Laundry   @ "<<h.laundrypgpr() <<" per garment" ;
                        int ch;
            do

            {
                cout<<"\n Enter 5 to go to Main Menu or Enter a choice to add a meal plan or laundry service: ";
                cin>>ch;
                switch(ch)

                {

                    case 1: s.breakfast();

                            cout<<"\n Breakfast added ";

                            fin.seekg(pos);

                            fin.write((char*)&s,sizeof(s));

                            break;

                    case 2: s.lunch();

                            cout<<"\n Lunch added ";

                            fin.seekg(pos);

                            fin.write((char*)&s,sizeof(s));

                            break;

                    case 3: s.dinner();

                            cout<<"\n Dinner added ";

                            fin.seekg(pos);

                            fin.write((char*)&s,sizeof(s));

                            break;

                    case 4:cout<<"\n Enter number of garments: ";

                            int temp;

                            cin>>temp;

                            s.wash(temp);

                            fin.seekg(pos);

                            fin.write((char*)&s,sizeof(s));

                            cout<<"\n Sent for wash ";

                            break;
                    case 5: break;

                        default:cout<<"\n Invalid choice";

                }

            }while(ch<1||ch>5); //invalid choice condition

            flag=-1;

        }

    }

    if (flag==0)

        cout<<"\n Sorry room number not found or vacant...";

    fin.close();

}



void rooms()

{

    //clearscreen();

    fstream fin("Record.dat",ios::in|ios::binary);

    cout<<"\n\t\t\t List of rooms alloted";

    cout<<"\n\t\t\t ---------------------"<<endl;

    cout<<setw(9)<<"Room number "<<setw(30)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Phone number"<<setw(20)<<"Room Type"<<endl;
    if(fin)
    {
        hotel s;

        s.sort();

        while(fin.read((char*)&s,sizeof(hotel)))

        {

            cout<<setw(9)<<s.Rroom_no()<<setw(30)<<s.Rname()<<setw(20)<<s.Radd()<<setw(20)<<s.Rphno()<<setw(20);

            s.Rtype();

            cout<<endl;

        }
    }
    fin.close();

}

int check(int r)

{

    int flag=0;

    hotel s;

    ifstream fin("Record.dat",ios::binary);

    if(fin) // there are certain records in file

        while(!fin.eof())

        {

            fin.read((char*)&s,sizeof(hotel));

            if(s.Rroom_no()==r)

            {

                flag=1; //room alloted

                break;

            }

        }

    fin.close();

    return(flag);

}

int checkID(char s[10])
{
    ofstream fout ("file.txt");
    fout << s << endl;
    system("grep '^[AFMZXWOYBNRUC][0-9][0-9][0-9][0-9][0-9][0-9]([0-9A].' file.txt>file1.txt"); //using LINUX command to check HKID
    ifstream fin("file1.txt");
    string x;
    int c=0; // counting lines
    while(fin>>x)
      ++c; // if c updates, file not empty. HKID veriied
    fin.close();
    fout.close();
    return c;
}

void modify(int r)

{

    long int pos,flag=0;

    hotel s;

    fstream file("Record.dat",ios::in|ios::out|ios::binary);

    if(file)

        while(!file.eof())

        {

            pos=file.tellg();

            file.read((char*)&s,sizeof(hotel));

            if(s.Rroom_no()==r)

            {

                cout<<"\n Enter New details";

                cout<<"\n -----------------";

                cout<<endl;

                s.input(r);

                file.seekg(pos);

                file.write((char*)&s,sizeof(hotel));

                cout<<"\n Record is modified..!!";

                flag=1;break;

            }

        }

    if (flag==0)

        cout<<"\n Sorry Room number not found or vacant.....!!";

    file.close();

}



void delete_rec(int r)

{

    int flag=0;

    char ch; //takes choice of user

    ifstream fin("Record.dat",ios::binary);

    ofstream fout("temp.dat",ios::binary);

    hotel s;

    if (fin)

        while(fin.read((char*)&s,sizeof(hotel)))

        {

            if (s.Rroom_no()==r)

            {

                s.show();

                cout<<"\n\n Do you want to delete this record(y/n)?";

                cin>>ch;

                if(ch=='y')

                {}

                if(ch=='n')

                    fout.write((char*)&s,sizeof(hotel));

                flag=1;

            }

            else

                fout.write((char*)&s,sizeof(hotel));

        }

    fin.close();

    fout.close();

    if(flag==0)

        cout<<"\n Sorry room number already alloted";

    else

    {

        remove("Record.dat");

        rename("temp.dat","Record.dat");

    }

}

void create()
{
    hoteldeets h;
    fstream fout ("hoteldeets.dat",ios::binary|ios::out);
    h.inputhoteldeets();
    fout.write((char*)&h,sizeof(h));
}


void initialize()
{
    fstream fin("hoteldeets.dat",ios::binary|ios::in);
    hoteldeets h;
    fin.read((char*)&h,sizeof(h));
    breakfastprice=h.breakfastpr();
    lunchprice=h.lunchpr();
    dinnerprice=h.dinnerpr();
    laundryprice=h.laundrypgpr();
    standard_room=h.pricestandard();
    deluxe_room=h.pricedeluxe();
    supreme_room=h.pricesupreme();
    royal_room=h.priceroyal();
}

int main()

{

    //clearscreen();

    hotel h;

    h.main_menu();

}

