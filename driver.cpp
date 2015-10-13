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
	cout << skyDive(5) << endl;
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
    char inn, lodge, both;
    double housingCost, innCost, lodgeCost;
    double allDiscount;
    double baseCost;
    int days = 0;
    int innDays = 0;
    int lodgeDays = 0;
    int daysFor2 = 0;
    double baseCharge = 700.00;
    int wilderness = 65;
    int luxury = 120;
        
    baseCost = baseCharge * people;
    
    cout << "\nTHANK YOU FOR CHOICING THE 4 DAY SKYDIVING PLAN\n"
         << "HOPE YOU HAVE A GREAT TIME!!" << endl;
        
    cout << "\nWould you like to stay at the Wilderness Lodge which\n"
         << "is $65/day per person or would you like to stay at\n"
         << "the Luxury Inn which is $120/day per person? Please\n"
         << "enter in 'w' for Wilderness and 'l' for Luxury and for"
         << "both enter in 'b'." << endl;
    cin >> housingChoice;
        
   /*if (people > 5)
    {
       allDiscount = discount(baseCharge, people);
    }*/
    //else
    //{
    allDiscount = 0;
    
    //}
       
    while (housingChoice != 'w' && housingChoice != 'l' && housingChoice != 'b') 
    {
        cout << "Invalid answer, please enter in 'w' or 'l' or 'b'" << endl;
        cin >> housingChoice;
        
        if (housingChoice == 'w' || housingChoice == 'l' || housingChoice == 'b')
        {
            break;
        }
    }
    
    if (housingChoice == 'w')
    {
        lodge = 'w';
        cout << "\nHow many days will you be staying there?" << endl;
        cin >> days;  
    }
    else if (housingChoice == 'l')
    {
        inn = 'l';
        cout << "\nHow many days will you be staying there?" << endl;
        cin >> days;  
    }
    else if (housingChoice == 'b')
    {
        both = 'b';
        cout << "How many days would you like to stay at the Wilderness Lodge?" << endl;
        cin >> lodgeDays;
        
        cout << "How many days would you like to stay at the Luxury Inn?" << endl;
        cin >> innDays;
        
        daysFor2 = lodgeDays + innDays;        
    }
          
    while (daysFor2 > 4)
    {
        cout << "\nToo long of a stay" << endl;
        cout << "\nHow many days would you like to stay at the Wilderness Lodge?" << endl;
        cin >> lodgeDays;
        
        cout << "How many days would you like to stay at the Luxury Inn?" << endl;
        cin >> innDays;
        
        daysFor2 = lodgeDays + innDays;
    }           
    
        
    while (days > 4)
    {
        cout << "That too long of a stay.\nPlease enter in a right amount of days." << endl;
        cin >> days;
    }
    
    if (lodge == 'w')
    {
        housingCost = wilderness * (people * days);                
    }   
    else if (inn == 'l')
    {
        housingCost = luxury * (people * days);              
    }
    else if (both == 'b')
    {
        innCost = luxury * (people * innDays);
        cout << "Your inn cost is :$ " << innCost << endl;
        lodgeCost = wilderness * (people * lodgeDays);
        cout << "Your lodge cost is :$ " << lodgeCost << endl;
        
        housingCost = innCost + lodgeCost;      
    }
    
    cout << "\nYour base cost is: $" << baseCost << endl;
    cout << "Your housing cost is: $" << housingCost << endl;
    cout << "Your discount amount is: $" << allDiscount << endl;
    return (baseCost + housingCost - allDiscount); 
       
}

