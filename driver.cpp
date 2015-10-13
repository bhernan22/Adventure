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
	double total;
	
	cout << 	"\nWelcome to the High Adventure Travel Agency!" << endl;
	cout <<  "\nHow many people will be participating in this trip? ";
	cin >> people;
	
	cout<< "Please select one of our packages." << endl << endl;
	
	choice = menu();
	
	switch(choice)
	{
		case '1': total = climbing(people);
						break;
		case '2': total = scuba(people);
						break;
		case '3': total =skyDive(people);
						break;
		case '4': total = spelunk(people);
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
    
    while (housingChoice == 'w' || housingChoice == 'l') 
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
    
    while (housingChoice != 'w' && housingChoice != 'l') 
    {
        cout << "Invalid answer, please enter in 'w' or 'l'" << endl;
        cin >> housingChoice;
        
        if (housingChoice == 'w')
        {
            housingCost = wilderness * days;
        }
        else if (housingChoice == 'l')
        {
            housingCost = luxury * days;
   
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
double scuba(int people)
{
	return 5.6;
}
double spelunk(int people)
{
	return 5.4;
}
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
        DISCOUNT = 0.10, 
        CLIMB_INSTR = 100, 
        EQUIP_RENT = 40;
    
    cout 
        << "\nThank you for choosing Devil's Courthouse Adventure Weekend!" << endl
        << endl << "Listed below are our rates." << endl
        << "\t⇨ Base Charge: \t\t\t$" << BASE_CHARGE << " per person" << endl
        << "\t⇨ Climbing Instructions: \t$" << CLIMB_INSTR << " per person (optional)" << endl
        << "\t⇨ Equipment Rental: \t\t$" << EQUIP_RENT << "/day per person (optional)" << endl << endl;
    
    // calculate the base total, before discount
    baseTotal = BASE_CHARGE * people;
    
    // call discount() to calculate the discount
    discountTotal = 0;//discount(baseTotal, people);
    
    cout 
        << "You have [" << people << "] people in your party." << endl
        << "Your Base Charge (before discount) is:\t$" << baseTotal << endl
        << "Your Discount Total is:\t\t\t(-$" << discountTotal << ")" << endl;
        
        baseTotal -= discountTotal; // subtract discount total from the base total
        totalAmount = baseTotal;    // update the total amount
    
        
    cout << "Your Base Charge (after discount) is:\t$" << baseTotal << endl << endl;
        
    cout << "Enter the number of people who will need climbing instructions: ";
    cin >> peopleOptional;
    
    cout << "$" << CLIMB_INSTR << " x [" << peopleOptional << "] people =" << endl;
    
    climbOptional = CLIMB_INSTR * peopleOptional;   // the optional climbing instruction charge is $100/person
    
    cout << "\t⇨ $" << climbOptional << " will be added to your current total of $" << totalAmount << "." << endl;
    totalAmount += climbOptional;  // add the optional charge of climbing instructions to the totalCharge
    
    cout << "\tYour updated total is $" << totalAmount << "." << endl << endl;
    
    cout << "Enter the number of people who will need to rent equipment: ";
    cin >> peopleOptional;
    
    cout << "How many days will you be renting equipment? ";
    cin >> daysOptional;
    
    cout << "$" << EQUIP_RENT << " x [" << peopleOptional << "] people x [" << daysOptional << "] days =" << endl;
    equipOptional = EQUIP_RENT * peopleOptional * daysOptional; // the optional equipment rental charge is $40/day per person

    cout << "\t⇨ $" << equipOptional << " will be added to your current total of $" << totalAmount << "." << endl;
    totalAmount +=  equipOptional;  // add the optional charge of equipment rental, equipOptional, to the totalCharge 
        
    return totalAmount;    
} 
void receipt(double total, int people, double discount)
{
    cout 
        << "\nYour charges are as follows:" << endl
        << "\t⇨ Per person: \t$" << total/people << endl
        << "\t⇨ Total people: \t" << people << endl
        << "Base Charge: \t$" << total + discount << endl
        << "\t⇨ Discount: \t-($" << discount << ")" << endl
        << "TOTAL CHARGES: \t$" << total << endl
        << "\nThank you for purchasing your vacation package!" << endl;   
} 
