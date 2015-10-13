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
	int people;
	char choice;
	double total, discountTotal;
	
	cout << 	"\nWelcome to the High Adventure Travel Agency!" << endl;
	cout << "We offer four vacation packages for thrill-seeking customers!" << endl;
	
	cout <<  "\nHow many people will be participating in this trip? ";
	cin >> people;
	
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
	
	discountTotal = 0;
	receipt(total, people, discountTotal);
	
	return 0;
}
char menu()
{
    char choice;
    
    cout << "       The High Adventure Travel Package:\n" << endl;
    cout << "Enter in '1' for Devil’s Courthouse Adventure Weekend" << endl;
    cout << "Enter in '2' for Scuba Bahama" << endl;
    cout << "Enter in '3' for Sky Dive Colorado" << endl;
    cout << "Enter in '4' for Barron Cliff Spelunk" << endl << endl;
    cout<< "Please select one of our packages.";
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
        
    cout << "\nWhere would you like to stay? \n"
         << "Wilderness Lodge: $65/day per person \n"
         << "Luxury Inn: $120/day per person\n"
         << "Please enter in 'w' for Wilderness and 'l' for Luxury and for "
         << "both enter in 'b'." << endl;
    cin >> housingChoice;
               
    while (housingChoice != 'w' && housingChoice != 'l' && housingChoice != 'b') 
    {
        cout << "Invalid answer, please enter in 'w' or 'l' or 'b'" << endl;
        cin >> housingChoice;
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
    baseCost = baseCharge * people;
    
    if (people > 5)
    {
       allDiscount = discount(baseCharge, people);
    }
    else
    {
        allDiscount = 0;
    }
  
    cout << "\nYour base cost is: $" << baseCost << endl;
    cout << "Your housing cost is: $" << housingCost << endl;
    cout << "Your discount amount is: $" << allDiscount << endl;
    return (baseCost + housingCost - allDiscount);      
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
    discountTotal = discount(baseTotal, people);
    
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
void receipt(double total, int people, double discount)
{
    cout 
        << "\nYour charges are as follows:" << endl
        << "\t⇨ Per person: \t$" << total/people << endl
        << "\t⇨ Total people: \t" << people << endl
        << "Base Charge: \t$" << total + discount << endl
        << "\t⇨ Discount: \t-($" << discount << ")" << endl
        << "TOTAL CHARGES: \t$" << total << endl
        << "\nThank you for purchasing your vacation package!\n" << endl;   
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
