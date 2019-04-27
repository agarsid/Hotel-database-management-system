# Hotel-database-management System
## Problem Statement
    In the hotel industry, there is a constant need for evaluating the total charges that a customer
    needs to pay for his stay and the use of hotel facilities during this period. Hence, we target to 
    build a database management system which allows the staff to check room availability, authenticity
    of the individual and also keep a track of the charges depending upon the individual's type of room,
    meal plan and house keeping services.
## Problem Setting:

**(This project works on a LINUX environment and is coded in c++11)**

The database system is created for hotels in Hong Kong wherein all the prices are in HKD.

### **Assumptions**:
1. The database is built for a hotel with maximum 4 types of rooms: Standard, Deluxe, Supreme and Royal.
2. The admin should be aware of the room numbers as the database only maintains records if a room number is entered.
3. A date before 2019 and after 2025 cannot be input. The admin should however not enter a date prior to the current date.
4. 1 room can be allotted to only 1 guest/family.The meal plan is on a per head basis i.e. there is a fixed charge for each  meal. 

## Functionalities and Features:

    The program creates two main files. "hoteldeets.dat" stores the details of room type and price.
    "Records.dat stores information of each person staying in a room.
    
1. Edit Hotel Details:
   - Choosing this function allows the admin to add or increase number of rooms in the hotel and also change their
     prices. It is **important** to note that if "hoteldeets.dat" is empty, this function is implicitly called in
     the start of code for the admin to enter details of the user.
     
2. Check-In:
   - After entering "2", the admin is asked to enter the date of check-in **ddmmyyyy** format. The program shall not
     work if there is any discrepancy in the desired format. The program however informs the admin if an incorrect 
     date is mentioned and asks admin again for input. Room type is asked from the admin followed by the room number
     which the admin should himself. Following the date, customer details are asked including name,
     address, phone number and HKID.Once details are successfully stored and if room is empty, the room is alloted or
     else tha main menu is again shown.
     - Validation of phone number: It should be equal to 8 digits.
       **Validation of HKID:**  Standard format is Xnnnnnn(A). X represents any one letter of alphabets[AFMZXWOYBNRUC]
       n is a digit in [0-9] and A is in [0-9] or equal to A.
    
3. Check-Out:
   - After entering "3", the admin is asked to enter room number to be checked out followed by the the date in ddmmyyyy
     format. Like the check-in function, the date specifications remain the same. If the room is occupied and the admin
     confirms checkout by pressing "y", the total bill of the customer is calculated. His record is deleted from the
     database and the room is unoccupied. If he presses "n", main menu is shown again.
     - Calculation of charges:  
       Rent - The number of days resided in hotel multiplied by room tariff
       Food - If there is a meal plan for lunch,dinner or breakfast,it's price is multiplied by number of days.
       Laundry - The number of garments sent for washing multiplied by the price of one garment.
       Service Charge - 10% service charge on each bill.
       
4. Customer Record:
   - Allows admin to access details of a guest staying in a occupied room. Important to note that the information is
     of one guest only even if a family is staying. It then allows the admin to add meal plans and laundry service of
     the guest.
     - The meal plans,being breakfast,lunch and dinner, can be added for n number of guests by selecting the required
       meal plan n times. If the laundry service is chosen, the number of garments can be input. The price for each
       meal and laundry service are also displayed by this choice.
       
5. Rooms Alloted:
   - By pressing "5", the admin gets the details of the rooms occupied in the hotel in ascending order of room numbers.
     The name, phone number and address of each guest(one indiviudal) is also displayed along with the room type.
     
6. Edit Records:
   - The admin gets the option to either modify or delete records of a room which has been alloted. He can edit the
     name, address, phone number and HKID which are again subject to **authentication as before**.
     The option of deleting a record gives the admin the freedom to delete records of guests who did not stay in the
     hotel for a day.
     
7. Exit:
   - The main menu exits and the program terminates.
     *If the admin enters a number not in [1-7],the main menu again pops up.
     
## Input/Output SPECIFICATIONS:

* The input requirement in main menu or other areas where a particular choice is required and the admin is asked for
  input should be an integer value only and there should be no spaces when such a choice is being made. If an invalid
  integer choice is made, the user is asked for input again. Furthermore, in cases where a name is asked, there is no
  restriction.
  
* The ouput is displayed on the screen. Also the files created get updated whenever any detail in them is changed. For
  example, when a new guest checks in, his details are updated on "Record.dat".
  
## SPECIAL FEATURE:
Currently, **privacy** is a big concern of individuals wherein they are concerned how their ID can be misused when a 
particular organisation/company/entity asks for their identity. However, it cannot be ignored that authentification of
an individual is also neccessary for such companies, especially in the hotel industry who are responsible for the safety
of all their guests. **Hence, our database management system does ask for the HKID of an individual so as to authenticate 
his identity, but having checked it, it does not store any record of the person's ID. The only ID which is stored in the 
system is of the most recent guest.** Moreover, to access the record of previous guests, a file "History.dat". Again, this 
file has no record of HKID details of the guest so as to maintain his privacy whereas it has his name, address and a correct Hong Kong number for security concerns of the hotel.
