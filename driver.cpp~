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
    double scubaTest;
	int count = 0;
	while(count == 0)
	{
	    scubaTest = scuba(2);
	    cout << scubaTest << endl;
	}
	return 0;
}

double scuba(int people)
{
    const double personPrice = 350;//price per person
    const double instructionPrice = 100;//price of scuba instruction
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
    
 //       baseDiscount = discount(personPrice, people);//find the discount.     
    
    return (personPrice * people) + (instructionPrice * students) - baseDiscount;
}
