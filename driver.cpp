// Bianca Hernandez
// Coleman Johnston
// Chanel Aquino
// Regie Daquioag
// 
//********************************************************

#include<cstdlib>//toupper
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
	cout << spelunk(5) << endl;
	return 0;
}

double discount(double baseCharge, int people)
{
    baseCharge = people * baseCharge;
    if (people >= 5)
    {//if five or more people return 10% of the base charge
        return (baseCharge * .10);
    }     
    else
    {//if less than five people return 0
        return 0;
    }
}

double scuba(int people)
{
    const double PERSON_PRICE = 350;//price per person
    const double INSTRUCRION_PRICE = 100;//price of scuba instruction
    int students;//variable to hold the number of people who need scuba instruction
    double baseDiscount = 0;//discount off of the base price (positive number!)
       
    cout << "Thank you for choosing Scuba Bahama!\n";
    do//check and make sure the amount of people who need instruction is <= the number of people going on the trip
    {
        cout << "How many people need diving lessons?\n";
        cout << "(Those with prior experience may dive right in, while beginners should choose\n"; 
        cout << "to take optional, but very affordable lessons.)\n";
        cin >> students;
    
        if(students > people)
        {
            cout << "You have entered a number greater than the number of people in your party.\n";
            cout << "Please enter a smaller number.\n\n";
        }
        else if(students < 0)
        {
            cout << "Please enter a positive number or 0.\n";
        }
    
    }while(students > people || students < 0);
    
        baseDiscount = discount(PERSON_PRICE, people);//find the discount.     
    
    return (PERSON_PRICE * people) + (INSTRUCRION_PRICE * students) - baseDiscount;
}

double spelunk(int people)
{
    const double PERSON_PRICE = 700;//base price per person
    const double RENTAL = 40;//equipment rental per day per person
    double baseDiscount = discount(PERSON_PRICE, people);//discount off of base price
    int renters;//how many people are renting equipment
    int days;//days that a single person is renting equipment for
    int totalDays = 0;//total days that equipment is getting rented for 
    
    cout << "Thank you for choosing Barron Cliff Spelunk!\n";
    do//error checking for input
    {
        cout << "Optional equipment rental is $40 per day for every person.\n";
        cout << "How many need to rent equipment?\n";
        cin >> renters;
        if (renters > people)
        {
            cout << "You have tried to rent equipment for more people than are in your party\n";
            cout << "Please enter a smaller number\n";
        }
        else if(renters < 0)
        {
            cout << "Please enter a positive number.\n";
        } 
    }while((renters > people) || (renters < 0));//continue until the user has entered valid input
    
    for(int i = 1;i <= renters;i++)//ask how many days each renter needs the equipment for
    {
        do
        {
            cout << "How many days does person " << i << " want to rent equipment?\n";
            cout << "(The trip is eight days long.)\n";
            cin >> days;
            
            if (days > 8)
            {
                cout << "The trip is only eight days please enter a smaller number\n";
            }
            else if(days < 0)
            {
                cout << "Please enter a positive number.";
            }
            else 
            {
                totalDays += days;//if valid input add to total days
            }
  
        }while((days > 8) || (days < 0));//continue until user enters valid input        
    }  
    return ((RENTAL * totalDays) + (people * PERSON_PRICE) - baseDiscount); 
}
