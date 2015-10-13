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
	int people;
	char choice;
	
	cout << 	"Welcome to the High Adventure Travel Agency!" << endl;
	cout <<  "How many people will be participating in this trip?";
	cin >> people;
	
	cout<< "Please select one of our packages." << endl;
	
	choice = menu();
	
	switch(choice)
	{
		case '1': climbing(people);
						break;
		case '2': scuba(people);
						break;
		case '3': skyDive(people);
						break;
		case '4': spelunk(people);
						break;
		default: cout << "You enter an invalid input. Please Try Again." << endl;
	}
	
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
    double baseCharge = 700.00;
    int wilderness = 65;
    int luxury = 120;
    int baseCost;
    int days;
    
    cout << "\nWould you like to stay at the Wilderness Lodge which\n"
         << "is $65/day per person or would you like to stay\n"
         << "at the Luxury Inn which is $120/day per person?\n"
         << "Please enter in 'w' for Wilderness and 'l' for Luxury." << endl;
    cin >> housingChoice;
    
    cout << "\nHow many days will you be staying there?" << endl;
    cin >> days;
    
    while (housingCost == 'w' || housingCost == 'l')
    {
        if (housingChoice == 'w')
        {
            housingCost = wilderness * days;
        }
        else if (housingChoice == 'l')
        {
            housingCost = luxury * days;
        }
    }
    
    while (housingCost != 'w' && housingCost != 'l')
    {
        cout << "Invalid answer, please enter in 'l' or 'w'" << endl;
        cin >> housingChoice;
        
        if (housingChoice == 'w')
        {
            housingCost = wilderness * days;
        }
        else if (housingChoice == 'l')
        {
            housingCost = luxury * days;
        }
    }
    
    baseCost = baseCharge * people;
    
    /*if (people > 5)
    {
       allDiscount = discount(baseCharge, people);
    }*/
    //else
    //{
        allDiscount = 0;
    //}
    return (baseCost + housingCost - allDiscount);    
}
double climbing(int people)
{
 return 5.8;
}
double scuba(int people)
{
	return 5.6;
}
double spelunk(int people)
{
	return 5.4;
}

