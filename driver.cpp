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

char menu()
{
    char choice;
    
    cout << "       The High Adventure Travel Package:\n" << endl;
    cout << "Enter in '1' for Devil’s Courthouse Adventure Weekend" << endl;
    cout << "Enter in '2' for Scuba Bahama" << endl;
    cout << "Enter in '3' for Sky Dive Colorado" << endl;
    cout << "Enter in '4' for Barron Cliff Spelunk" << endl;
    
    cin >> choice;
    
    return choice;
    
}

double skyDive(int people)
{
    char housingChoice;
    double housingCost;
    double allDiscount;
    double baseCost;
    int days;
    double baseCharge = 700.00;
    int wilderness = 65;
    int luxury = 120;
        
    baseCost = baseCharge * people;
        
    cout << "\nWould you like to stay at the Wilderness Lodge which\n"
         << "is $65/day per person or would you like to stay at\n"
         << "the Luxury Inn which is $120/day per person? Please\n"
         << "enter in 'w' for Wilderness and 'l' for Luxury." << endl;
    cin >> housingChoice;
    
    
    
   /*if (people > 5)
    {
       allDiscount = discount(baseCharge, people);
    }*/
    //else
    //{
    allDiscount = 0;
    
    //}
    
    while (housingChoice == 'w' || housingChoice == 'l') 
    {
        cout << "\nHow many days will you be staying there?" << endl;
        cin >> days;
        
        if (housingChoice == 'w')
        {
            housingCost = wilderness * (people * days);
            cout << "\nYour base cost is: $" << baseCost << endl;
            cout << "Your housing cost is: $" << housingCost << endl;
            cout << "Your discount amount is: $" << allDiscount << endl;
            return (baseCost + housingCost - allDiscount);  
            
        }
        else if (housingChoice == 'l')
        {
            housingCost = luxury * (people *days);
            cout << "\nYour base cost is: $" << baseCost << endl;
            cout << "Your housing cost is: $" << housingCost << endl;
            cout << "Your discount amount is: $" << allDiscount << endl;
            return (baseCost + housingCost - allDiscount);  
            
        }
    }
    
    while (housingChoice != 'w' && housingChoice != 'l') 
    {
        cout << "Invalid answer, please enter in 'w' or 'l'" << endl;
        cin >> housingChoice;
        
        cout << "\nHow many days will you be staying there?" << endl;
        cin >> days;        
        
        if (housingChoice == 'w')
        {
            housingCost = wilderness * (people * days);
            cout << "\nYour base cost is: $" << baseCost << endl;
            cout << "Your housing cost is: $" << housingCost << endl;
            cout << "Your discount amount is: $" << allDiscount << endl;
            return (baseCost + housingCost - allDiscount);  
            
        }
        else if (housingChoice == 'l')
        {
            housingCost = luxury * (people * days);
            cout << "\nYour base cost is: $" << baseCost << endl;
            cout << "Your housing cost is: $" << housingCost << endl;
            cout << "Your discount amount is: $" << allDiscount << endl;
            return (baseCost + housingCost - allDiscount);  
            
        }
    }
       
}

