#include"hotel.h"
#include"hoteldetails.h"
#include"run.h"

using namespace std;

void hotel::checkindate(int Y, int M, int D)

{
    inyear=Y;

    inmonth=M;

    indate=D;
}

void hotel::checkoutdate(int Y, int M, int D)

{
    outyear=Y;

    outmonth=M;

    outdate=D;
}







float hotel:: service_charge_bill()
{
    return((rent_bill()+wash_bill()+food_bill())*0.10);                 //service charge= 10 % of total bill
}





int hotel::Rroom_no()
{
    return(room_no);
}

char * hotel::Rname()
{
    return(name);
}


char * hotel ::Radd()
{
    return (address);
}

char * hotel::Rphno()
{
    return phone;
}

void hotel::breakfast()
{
    btimes++;
}

void hotel::lunch()
{
    ltimes++;
}

void hotel::dinner()
{
    dtimes++;
}

void hotel::wash(int temp)
{
    gtimes+=temp;
}

int hotel::Rindate()
{
    return indate;
}

int hotel::Rinmonth()
{
    return inmonth;
}

int hotel::Rinyear()
{
    return inyear;
}

int hotel::Routdate()
{
    return outdate;
}

int hotel::Routmonth()
{
    return outmonth;
}

int hotel::Routyear()
{
    return outyear;
}

void hotel::Gtype(int A)
{
    type=A;                                 //stores the type of room in type
}

void hotel::Rtype()
{
    rtype=type;

    switch(rtype)

    { case 1:cout<<"Standard";break;

        case 2:cout<<"Deluxe";break;

        case 3:cout<<"Supreme";break;

        case 4:cout<<"Royal";break;

        default:cout<<"WRONG CATEGORY OF ROOM";
    }
}

void hotel::Gdays(int A)
{
    days=A;                                     //stores the number of days the customer stayed in the hotel
}



void hotel::show()
{
    cout<<endl;

    cout<<"\t Name: "<<name<<endl;

    cout<<"\t Address: "<<address<<endl;

    cout<<"\t Phone number: "<<phone<<endl;
}

void hotel::input(int r)
{
    char HKID[10];
    room_no=r;

    cin.ignore();

    cout<<"Name: ";

    cin.getline(name,30);                               //inputs Name

    cout<<"Address: ";

    cin.getline(address,100);                            //inputs Address

    do

    {

        cout<<"Phone number: ";

        cin>>phone;
        if(strlen(phone)!=8)

            cout<<"Invalid Phone number. Please re-enter. ";
    }while(strlen(phone)!=8);
    phone[8]='\0';
        cout << "HKID: ";
    cin>>HKID;
    while(!checkID(HKID))                                               //checks validity of HKID
    {
      cout<<"Invalid HKID." << endl << "Please re-enter HKID: ";
      cin >> HKID;
    }
}

void hotel::main_menu()
{
    //clearscreen();
    fstream fil;
    fil.open("hoteldeets.dat",ios::in);                    //opens hoteldeets.dat
    if(!fil)                                               //if file doesn't exist, opens a new file and writes new data onto it
    {
        create();                                          
        main_menu();
    }
    
    else
    {
        initialize();                                      //initializes the values of the global variable everytime a new code is run
        int choice=0;

        while(choice!='6')

        {

            if(choice!=4)

              //clearscreen();

            cout<<"\n\t\t\t***************";

            cout<<"\n\t\t\t** MAIN MENU **";

            cout<<"\n\t\t\t***************";

            cout<<"\n\n\n\t\t\t 1.Edit Hotel Details";

            cout<<"\n\t\t\t 2.Check In";

            cout<<"\n\t\t\t 3.Check Out";

            cout<<"\n\t\t\t 4.Customer Record";

            cout<<"\n\t\t\t 5.Rooms Allotted";

            cout<<"\n\t\t\t 6.Edit Record";

            cout<<"\n\t\t\t 7.Exit";

            cout<<"\n\n\t\t\t Enter your choice: ";

            cin>>choice;

            switch(choice)

            {

                case 1:create();                                                 //edits hotel details

                    break;

                case 2:check_in();                                               //creates new customer details

                    break;

                case 3:check_out();                                              //checks out a customer

                    break;

                case 4:display();                                                //search customer record

                    break;

                case 5:rooms();                                                  //displays rooms allocated

                    break;

                case 6:edit();                                                   //modify or delete customer records

                    break;

                case 7:exit(0);

                default:

                    cout<<"\n\n\t\t\t Wrong Choice......!!!";

                    break;

            }

        }
    }

}void hotel::edit()

{

    //clearscreen();

    int choice,r;

    cout<<"\n EDIT MENU  ";

    cout<<"\n ---------";

    cout<<"\n\n 1.Modify Customer record";

    cout<<"\n\n 2.Delete Customer record";

    cout<<"\n Enter your choice: ";

    cin>>choice;

    //clearscreen();

    if(choice==1 || choice==2)

    {
        cout<<"\n\n Enter room number: ";

        cin>>r;

    }

    switch(choice)

    {

        case 1:modify(r);    break;

        case 2:delete_rec(r);  break;

        default:cout<<"\n Wrong choice";

    }

}

void hotel::sort()
{
    fstream F;
    F.open("Record.dat",ios::binary|ios::binary|ios::in|ios::out);
    F.seekg(0,ios::end);
    int NOR= F.tellg()/sizeof(hotel);
    hotel h,h1;
    for (int i=0;i<NOR-1;i++)
    {
        for(int j=0;j<NOR-i-1;j++)
        {
            F.seekg(j*sizeof(hotel));
            F.read((char*)&h,sizeof(hotel));
            F.read((char*)&h1,sizeof(hotel));
            if(h.Rroom_no()>h1.Rroom_no())
            {
                F.seekp(j*sizeof(hotel));
                F.write((char*)&h1,sizeof(hotel));
                F.write((char*)&h,sizeof(hotel));
            }
        }
    }F.close();

}
