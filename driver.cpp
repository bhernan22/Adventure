// Bianca Hernandez
// Coleman Johnston
// Chanel Aquino
// Regie Daquioag
// 
//********************************************************

#include <iostream> // cin/cout
#include <cassert> // assert unit testing

using namespace std;

char menu();
double climbing(int people);
double scuba(int people);
double skyDive(int people);
double spelunk(int people);
double discount(double baseCharge, int people);
double discount(char choice, int people);
void receipt(double total, int people, double discount);

int main()
{
    return 0;
}

//*******************************
double climbing(int people)
{

    double 
        discountTotal = 0,
        baseTotal, 
        totalAmount,  
        climbOptional, 
        equipOptional;
        
    int 
        peopleOptional, 
        daysOptional;

    const double 
        BASE_CHARGE = 350, 
        DISCOUNT_RATE = 0.10, 
        CLIMB_INSTR = 100, 
        EQUIP_RENT = 40,
        NUM_DAYS = 3;
    
   
    cout 
        << "\nThank you for choosing Devil's Courthouse Adventure Weekend!" << endl
        << endl << "Listed below are our rates." << endl
        << "\t⇨ Base Charge: \t\t\t$" << BASE_CHARGE << " per person" << endl
        << "\t⇨ Climbing Instructions: \t$" << CLIMB_INSTR << " per person (optional)" << endl
        << "\t⇨ Equipment Rental: \t\t$" << EQUIP_RENT << "/day per person (optional)" << endl << endl;
    

    // calculate the base total, before discount
    baseTotal = BASE_CHARGE * people;
    
    // call discount() to calculate the discount
    discountTotal = discount(baseTotal, people);
    
    
    cout 
        << "You have [" << people << "] people in your party." << endl
        << "Your Base Charge (before discount) is:\t$" << baseTotal << endl
        << "Your Discount Total is:\t\t\t(-$" << discountTotal << ")" << endl;
        
        baseTotal -= discountTotal; // subtract discount total from the base total
        totalAmount = baseTotal;    // update the total amount
    
        
    cout << "Your Base Charge (after discount) is:\t$" << baseTotal << endl << endl;
    
    cout << "Enter the number of people who will need a climbing instructor: ";
    cin >> peopleOptional;
    
    while (peopleOptional < 0 || peopleOptional > people)
        // the people who need instruction (peopleOptional) should not exceed the number of people in the party
    {  
        cout 
            << "\tError: You entered more people than are in your party. Please try again."<< endl
            << "Enter the number of people who will need a climbing instructor: ";
        cin >> peopleOptional;
    }   // while()
        
    
    
    cout
        << "\n[" << peopleOptional << "] people will need a climbing instructor." << endl 
        << "$" << CLIMB_INSTR << " charge x [" << peopleOptional << "] people =" << endl;
    
    climbOptional = CLIMB_INSTR * peopleOptional;   // the optional climbing instruction charge is $100/person
    
    cout << "\t⇨ $" << climbOptional << " will be added to your current total of $" << totalAmount << "." << endl;
    totalAmount += climbOptional;  // add the optional charge of climbing instructions to the totalCharge
    
    cout << "\t⇨ Your updated total is $" << totalAmount << "." << endl << endl;
    
    cout << "Enter the number of people who will need to rent equipment: ";
    cin >> peopleOptional;
    
    while (peopleOptional < 0 || peopleOptional > people)
        // the people who need instruction (peopleOptional) should not exceed the number of people in the party
    {
        cout 
            << "\tError: You entered more people than are in your party. Please try again." << endl
            << "Enter the number of people who will need to rent equipment: ";
        cin >> peopleOptional;
    }   // while()
        
    cout << "How many days will you be renting equipment? ";
    cin >> daysOptional;
        
    while (daysOptional < 0 || daysOptional >  NUM_DAYS)
        // the number of days needed for equipment (daysOptional) should not exceed the total number of days
    {   cout 
            << "\tError: You entered more days than this package allows. Please try again." << endl
            << "How many days will you be renting equipment? ";
        cin >> daysOptional;
    }   // while()
        
    
    cout << "\n$" << EQUIP_RENT << " charge x [" << peopleOptional << "] people x [" << daysOptional << "] days =" << endl;
    equipOptional = EQUIP_RENT * peopleOptional * daysOptional; // the optional equipment rental charge is $40/day per person

    cout << "\t⇨ $" << equipOptional << " will be added to your current total of $" << totalAmount << "." << endl;
    totalAmount +=  equipOptional;  // add the optional charge of equipment rental, equipOptional, to the totalCharge
    
    cout << "\t⇨ Your updated total is $" << totalAmount << "." << endl;
    
        
    return totalAmount;    
}   // climbing()

//*******************************
void receipt(double total, int people, double discount)
{
    cout 
        << "\nYour charges are as follows:" << endl
        << "\t⇨ Per person: \t$" << total/people << endl
        << "\t⇨ Total people: " << people << endl
        << "Base Charge: \t\t$" << total + discount << endl
        << "\t⇨ Discount: \t-($" << discount << ")" << endl
        << "TOTAL CHARGES: \t\t$" << total << endl
        << "\nThank you for purchasing your vacation package!" << endl;   
}   // receipt()

//*******************************
double discount(char choice, int people)
{

    const double DISCOUNT_RATE = 0.10;  // 10% discount only applies to parties of 5 or more people
        
    double
        baseCharge, 
        totalDiscount = 0;
    
    if (people >= 5)
    {
        switch(choice)
        {
           case '1': // Devil's Courthouse Adventure Weekend
                baseCharge = 325;
                
                totalDiscount = baseCharge * DISCOUNT_RATE;
                return totalDiscount;
                break;
                
            case '2': // Scuba Bahama
                baseCharge = 1000;
                
                totalDiscount = baseCharge * DISCOUNT_RATE;
                return totalDiscount;
                break; 
                
            case '3': //Sky Dive Colorado
                baseCharge = 700;
                
                totalDiscount = baseCharge * DISCOUNT_RATE;
                return totalDiscount;
                break;  
                
            case '4': // Barron Cliff Spelunk
                baseCharge = 700;
                
                totalDiscount = baseCharge * DISCOUNT_RATE;
                return totalDiscount;
                break;
            
            default:
                cout << "Invalid. Try again." << endl;
                break;   
                
        }   // switch()
    
    }   // if()
    
    return totalDiscount;
}   // discount()
