
//Fredrik Kjellberg

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string getName(string prompt);

double getPrice(string prompt);

bool isBidPriceGood(double bidPrice, double reservePrice);

void calcWinner(string bidder1, string bidder2, string lotName, double bid1, double bid2, double reservePrice);

void printWinner(string bidder, string lotName, double bid);

void printHeader();

void printErrorMessage(int num);

int main()
{
    double Bidder1bidprice;
    printHeader();

    string lotName = getName("Enter lot name: "); //declears LotName as a string

    double ReservePrice = getPrice("Reserve price: $ "); //asks for reserve price and store value as a double in ReservePrice
    
    if (ReservePrice <= 0)
    {
        printErrorMessage(5); //prints ""ERROR: Reserve is not positive, auction canceled""
        return 0;
    }
    else
    {
        string bidder1ID = getName("Bidder1 ID: "); //prints "Bidder1 ID: " and stores the name in Bidder ID
        
        if (bidder1ID == "")
        {
            printErrorMessage(3); //prints "ERROR: Blank bidder ID, no bid allowed" if the Bidder ID is not enterd going strait to bid ID 2
    
            string bidder2ID = getName("Bidder2 ID: "); //prints "Bidder2 ID: " and stores the name in Bidder ID
            
            if (bidder2ID == "")
            {
                printErrorMessage(3); //prints "ERROR: Blank bidder ID, no bid allowed" if the Bidder ID is not enterd
                Bidder1bidprice = 0;
                double Bidder2bidprice = 0;
                calcWinner(bidder1ID, bidder2ID, lotName, Bidder1bidprice, Bidder2bidprice, ReservePrice);
            }
            else
            {
                double Bidder2bidprice = getPrice("Bidder2 price: $ ");
                if (isBidPriceGood(Bidder2bidprice, ReservePrice) == true)
                {
                calcWinner(bidder1ID, bidder2ID, lotName, Bidder1bidprice, Bidder2bidprice, ReservePrice);
                }
                else
                {
                calcWinner(bidder1ID, bidder2ID, lotName, Bidder1bidprice, Bidder2bidprice, ReservePrice);
                }
            }
        }
        else
        {    
            double Bidder1bidprice = getPrice("Bidder1 price: $ "); //ask bidder1's bid price - stores it as a double 
            if (isBidPriceGood(Bidder1bidprice, ReservePrice) == true)
            {
                cout << bidder1ID << " is high bidder, current price = $" << ReservePrice << endl; // prints bidder1ID and promt + ReservePrice price if conditions met
            }
            string bidder2ID = getName("Bidder2 ID: "); //prints "Bidder2 ID: " and stores the name in Bidder ID
            
            if (bidder2ID == "")
            {
            printErrorMessage(3); //prints "ERROR: Blank bidder ID, no bid allowed" if the Bidder ID is not enterd
            double Bidder2bidprice = 0;
            calcWinner(bidder1ID, bidder2ID, lotName, Bidder1bidprice, Bidder2bidprice, ReservePrice);
            }
            else
                {
                double Bidder2bidprice = getPrice("Bidder2 price: $ "); //ask bidder2's bid price - stores it as a double 
                    if (isBidPriceGood(Bidder2bidprice, ReservePrice) == true)
                    {
                        calcWinner(bidder1ID, bidder2ID, lotName, Bidder1bidprice, Bidder2bidprice, ReservePrice);
                    }
                    else
                    {
                        calcWinner(bidder1ID, bidder2ID, lotName, Bidder1bidprice, Bidder2bidprice, ReservePrice);
                    }    
                }
        }
    }
return 0;
}

double getPrice(string prompt)
//Requires: prompt is non-empty
//Modifies: nothing
//Effects: prints the 'prompt'; reads the price; dumps all data that remains on the line; returns the price
{
    cout << prompt;
    double Price;
    string Junk;
    cin >> Price;
    getline(cin, Junk);
    return Price;
}

string getName(string prompt)
//Requires: prompt is non-empty
//Modifies: nothing
//Effects: prints the 'prompt' and reads the name of the bidder and returns this name
{
    cout << prompt;
    string Name;
    getline(cin, Name);
    return Name;
}

bool isBidPriceGood(double bidPrice, double reservePrice)
//Requires:  bidPrice and reservePrice to be loaded
//           reservePrice > 0
//Modifies:  nothing
//Effects: returns true if the bidPrice is >=reservePrice
//           false otherwise
//		   Also, prints errorMessage 2 if bidPrice < 0
//		         prints errorMessage 1 if bidPrice < reservePrice
{
    if (bidPrice > 0)
    {
        if (bidPrice >= reservePrice)
        {
            return true; //returns a true statment
        }
        else
        { 
            printErrorMessage(1); //prints ERROR: Reserve not met, bid rejected and returns a false value
            return false;
        }
    }    
    else
    {
        printErrorMessage(2); //prints ERROR: Negative price, bid rejected and returns a false value
        return false; 
    }  
}

void calcWinner(string bidder1, string bidder2, string LotName, double bid1, double bid2, double reservePrice)
//Requires: all parameters to be loaded
//          reservePrice > 0
//Modifies: nothing
//Effects:  will calculate the winner of the auction and print out the winner          
//Note:     you have a function that does the printing
//          also, prints error message in case no-one won
{
    if ((bid1 >= reservePrice) && (bid2 >= reservePrice))
    {
        if (bid2 < bid1)
        {
            printWinner(bidder1, LotName, (bid2 + 0.50));
        }
        else if ((bid2 >= bid1) && (bid2 < (bid1 + 0.50)))
        {
            printWinner(bidder1, LotName, bid1);
        }
        else if (bid2 >= (bid1 + 0.50))
        {
            printWinner(bidder2, LotName, (bid1 + 0.50));
        }
    } 
    else if (bid2 < reservePrice)
    {
        if (bid1 < reservePrice)
        {
            printErrorMessage(4);
        }
        else if (bid1 >= reservePrice)
        {
            printWinner(bidder1, LotName, reservePrice);
        }
    }
    else if (bid2 >= reservePrice)
    {
        if (bid1 < reservePrice)
        {
            printWinner(bidder2, LotName, reservePrice);
        }
    }
    return;
}

void printWinner(string bidder, string lotName, double bid)
//Requires: bidder is non-empty, lotName is non-empty, bid is valid
//Modifies: nothing
//Effects: prints out "Congratulations", the winning bidder,
//         "You won", the name of the lot along with the price
//Example:
//Congratulations, Hobbes002
//You won "1987 Sugar Bombs" at a price of $2.25
{
    cout << "Congratulations, "<< bidder << endl;
    cout << "You won " << '"' << lotName << '"' << " at a price of $" << bid << endl;
    return;
}

void printHeader()
//Requires: nothing
//Modifies: nothing
//Effects:  prints out the initial header
{
	cout << "----------------------------------------" << endl 
    <<"            bCreek" << endl 
    <<"       Fine Cereal Sales" << endl 
    <<"----------------------------------------" << endl << endl;
	cout << fixed << showpoint;
	cout << setprecision(2);
    return;
}

void printErrorMessage(int num)
//Requires: num is 1-4 inclusive
//Modifies: nothing
//Effects: prints the appropriate error message
//         groups printing of error messages together into a function
{
	if (num == 1) {
		cout << endl
        << "  ERROR: Reserve not met, bid rejected" << endl << endl;
	} else if (num == 2) {
		cout << endl
        << "  ERROR: Negative price, bid rejected" << endl << endl;
	} else if (num == 3) {
		cout << endl
        << "  ERROR: Blank bidder ID, no bid allowed" << endl << endl;
	} else if (num == 4) {
		cout << endl
        << "ERROR: Neither bidder met Reserve, auction canceled" << endl << endl;
	} else if (num == 5) {
		cout << endl
        << "ERROR: Reserve is not positive, auction canceled" << endl << endl;
	} else {
		cout << "   This should never print" << endl << endl;
	}
    return;
}