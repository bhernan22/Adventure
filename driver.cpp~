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
    cout << scuba(4) << endl;
    
    assert(discount(100.0, 3) == 0);
    assert(discount(100.0, 5) == 10);
    assert(discount(200.0, 33) == 20);
	return 0;
}

double discount(double baseCharge, int people)
{
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
