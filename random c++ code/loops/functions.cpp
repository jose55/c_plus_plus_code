//Fredrik Kjellberg
//Mathias Arkayin

#include "functions.h"
#include <iostream>
#include <iomanip>

using namespace std;


//#1 
//Requires: rows > 0, cols > 0
//Effects: prints a rectangle of *'s
//         if rows = 3, cols = 2 gives
//**
//**
//**
void printBoard(int rows, int cols)
{
    int R = rows; 
    while (R > 0) // count the rows 
    {     
        int C = cols;
        while(C > 0)
        {          
            cout << '*';   //prints the *        
            C--; 
        }
        cout << endl;
        R--; 
    }
}

//#2
//Requires: n > 0
//Modifies: nothing
//Effects: prints a right triangle
//  with a parameter of 3 gives
//*
//**
//***
void printRight(int n)
{
    int R = n;
    int C = n;
    while (R > 0) // count the rows 
    {   
        int c = C;
        while(c <= n) // count the lines
        {          
            cout << '*';   //prints the *        
            c++; 
        }
        cout << endl;
        R--;
        C--;
    }
}

//#3 
//Requires: n > 0
//Modifies: nothing
//Effects: prints a right triangle with the *'s right justified
//   with a parameter of 3 gives
//  *
// **
//***
void printRight_rightJustified(int n)
{
    int R = n;
    int C = n;
    while (R > 0) // count the rows 
    {   
        int c = C;
        while(c <= n) // count the lines
        {          
            cout << '*';   //prints the *        
            c++; 
        }
        cout << endl;
        R--;
        C--;
    }
}

//#4 
//Requires: n > 0
//Modifies: nothing
//Effects: prints a right triangle upside down
//   with a parameter of 3 gives
//***
// **
//  *
void printRight_upsideDown_rightJustified(int n)
{
    int R = n;
    int C = n;  
    while (R > 0) // count the rows
    {   
        int c = C;
        while(c < n) // count the lines
        {          
            cout << '*';   //prints the *        
            c++; 
        }
        cout << endl;
        R--;
        C--;
    }
}

//#5 
//Requires n > 0
//Modifies: nothing
//Effects: prints a right triangle upside down
//         with a parameter of 3 gives
//***
//**
//*
void printRight_upsideDown(int n)
{
    int R = n;
    int C = 0;
    while (R > 0) // count the rows 
    {   
        int c;
        c = C;
        while(c < n) // count the lines
        {          
            cout << '*';  //prints the *      
            c++; 
        }
        cout << endl;
        R--;
        C++;
    }
}

//#6 
//Requires:  n > 0
//Modifies:  nothing
//Effects:   prints a series of values
//        if n is even, halve it
//        if n is odd, triple it and add one
//        continue until n is 1
// starting with 3 gives
// 3, 10, 5, 16, 8, 4, 2, 1
//(yes you also need to print the commas)
void threeSeries (int n)
{
    cout << n;
    if (n>1)
    {   
        cout << ", "; //prints comma
    } 
    while (n > 1)
    {
        if (n%2==0)
        {
            n=n/2; //div n by two
            cout << n;
        }
        else
        {
            n =(n*3)+1;  // n * 3 and +1 
            cout << n;    
        }
        if (n>1)
        {   
            cout << ", "; //prints comma 
        }    
    }
} 

//#7 
//Requires: nothing
//Modifies: x and y
//Effects: will swap the values of x and y
//         if x = 7 and y = 13 upon entry
//         when this function ends, x = 13 and y = 7
void swap(int & x, int & y)
{
    int StoreX = x; 
    int StoreY = y;
    x = StoreY;
    y = StoreX;
}

//#8 
//Requires: num >= 0; 0 <= digit <= 9
//Modifies: nothing
//Effects: will return true if 'digit' occurs anywhere within 'num'
//         returns false otherwise
//         if num=42 and digit = 5  this will return false
//         if num=42 and digit = 4  this will return true
//         if num=142 and digit = 2  this will return true
bool equalsDigit(int num, int digit)
{
    int N = num;
    
    while (N > digit && N > 1) 
    {
        if (N%10 == digit) // if the remainder is equal to digit returns true 
        {
            return true;
        }
        else
        {
            N= N/10; //takes away that last digit of num
        } 
    }
    // if N is a single digit 
    if (N == digit) // if the remainder is equal to digit returns true 
    {
        return true;
    }
    else //else return false 
    {    
        return false;
    }    
}

//#9
//Requires: start > 0; end > 0; 0 <= digit <= 9
//Modifies: nothing
//Effects: runs the range of numbers from start to end inclusive
// if (end < start), it will swap start and end
// prints the number if any digit of the number is the
// same as 'digit'
// printIfHoldsDigit(5, 10, 7) //prints: 7
// printIfHoldsDigit(5, 30, 8) //prints: 8, 18, 28
// printIfHoldsDigit(1, 30, 2)  prints: 2, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 
// and yes you need to print the commas
void printIfHoldsDigit(int start, int end, int digit)
{
    if (start <= end) // true if the (end < start)
    {
        int START = start; //saves start in START
        int END = end; //saves end in END
        int C = 0; // sets c = 0 so that there will be no comma in front of the first digit.
        while (START <= END) // will run as a loop unitll START > END
        { 
            int N = START; // START ==> is assigned to N 
            while (N > 0)
            {
                if (N%10 == digit) // true if the remainder is = to the digit
                {
                    if (C == 0)// will only be true for the first digit to print (this is so that there will be no comma printed if there is only one digit)
                    {   
                        cout << START;
                        N= N/10; 
                        C = 1; // sets C = 1 so if will be false and so that all numbers will have a comma before it now...
                    }    
                    else // will be true for all digits after the first one (will print a comma before each digit)
                    {
                        cout << ", "; // prints a comma before the digit
                        cout << START;  // increses the start value by one 
                        N= N/10; // divides N by 10 (last digit is taken away)
                    }
                }
                else
                {   
                    N= N/10; // divides N by 10 (last digit is taken away)
                } 
            }
            START++; // increses the start value by one    
        }   
    }
    else // true if the (end > start) ==> will therefore swap the numbers so that the large number will become end and small number will become start
    {
        int swapend = start; //savs start in endswap
        int START = end; // swaps start with end
        int END = swapend; // swaps end and for start
        int C = 0; // sets c = 0 so that there will be no comma in front of the first digit.
        while (START <= END) // will run as a loop unitll START > END
            while (START <= END) // will run as a loop unitll START > END
            { 
                int N = START; // START ==> is assigned to N 
                while (N > 0)
                {
                    if (N%10 == digit) // true if the remainder is = to the digit
                    {
                        if (C == 0)// will only be true for the first digit to print (this is so that there will be no comma printed if there is only one digit)
                        {   
                            cout << START;
                            N= N/10; 
                            C = 1; // sets C = 1 so if will be false and so that all numbers will have a comma before it now...
                        }    
                        else // will be true for all digits after the first one (will print a comma before each digit)
                        {
                            cout << ", "; // prints a comma before the digit
                            cout << START;  // increses the start value by one  
                            N= N/10; // divides N by 10 (last digit is taken away)
                        }
                    }
                    else
                    {   
                        N= N/10; // divides N by 10 (last digit is taken away)
                    } 
                }
                START++; // increses the start value by one    
            }   
    }
}


//#10 
//Requires: n >= 0
//Modifies: nothing
//Effects: returns the int formed by reversing the digits of n
//  a parameter of 123 will return 321
//  a parameter of 1234 will return 4321
//  a parameter of 1230 will return 321  (or 0321)
//   NOTE:  0321 will return 321 -- 
//   NOTE: in C++ listeral that begin with a 0 are interpreted to be octal
//         numbers and not decimal numbers
int reverseNumber(int n)
{
    int Reverse;
    Reverse = 0;
    
    while ( n != 0) // while n is not equal to zero
    {
        Reverse = Reverse * 10 + n % 10; // saves reverse digit in reverse 
        n = n / 10; 
    }
    return Reverse; // return the reversed value of n
}

//#11 
//Requires: n >= 0;
//Modifies:  n
//Effects: alters n to be the integer formed by reversing its digits
//         if n = 123, then it will be altered to be 321
//         if n = 1230, then it will be altered to be 0321, i.e., 321
void reverseNum(int & n)
{
    int Reverse;
    Reverse = 0;
    
    while ( n != 0) // while n is not equal to zero
    {
        Reverse = Reverse * 10 + n % 10; // saves reverse digit in reverse 
        n = n / 10; 
    }
    n = Reverse; //saves the reversed value of n
}

//#12 
//Requires: val >= 0
//Modifies: nothing
//Effects: returns how many hundreds there are in val
//         if the val is not an exact number of 100's, it
//         adds one
//         if val = 1300, it returns 13
//         if val = 1324, it returns 14
//         if val = 1, it returns 1
//         if val = 100, it returns 1
//         if val = 101, it returns 2 
int calcNum(int val)
{
    int S = val;
    int count = 0;   
    if (S%100==0) // ture if the number is just 100's
    {
        while(S > 0)
        {   
            count++;
            S=S-100; 
        }
        return count;   
    }   
    else
    {
        S = S + (100-S%100); //ads 99 if remianer is 1 etc so that S will be all 100's
        while(S > 0)
        {    
            count++;
            S=S-100;
        }
        return count;     
    }
}

//#13 
//Requires: store1, store2, store3, store4, store5 >= 0
//          these represent the sales of 5 stores
//Modifies: nothing
//Effects:  prints a bar chart for the sales
//          one * for each $100 of sales
//printBarChart(500,510,120,750,812);  // prints
//SALES BAR CHART
//(Each * = $100)
//Store 1: *****
//Store 2: ******
//Store 3: **
//Store 4: ********
//Store 5: *********
void printBarChart(int store1, int store2, int store3, int store4, int store5)
{
    cout << "SALES BAR CHART" << endl;
    cout << "(Each * = $100)" << endl;
    int S = store1; // for store 1 
    cout << "Store 1: ";    
    if (S%100==0) // ture if the number is just 100's
    {
        while(S > 0) 
        {          
            cout << '*';        
            S=S-100; 
        }
    }   
    else
    {
        S = S + (100-S%100); //ads 99 if remianer is 1 etc so that S will be all 100's
        while(S > 0)
        {    
            cout << '*';        
            S=S-100;
        }       
    }
    cout << endl;    
    S = store2; // for store 2
    cout << "Store 2: ";    
    if (S%100==0) // ture if the number is just 100's
    {
        while(S > 0)
        {          
            cout << '*';        
            S=S-100; 
        }
    }   
    else
    {
        S = S + (100-S%100); //ads 99 if remianer is 1 etc so that S will be all 100's
        while(S > 0)
        {    
            cout << '*';        
            S=S-100;
        }       
    }
    cout << endl;
    S = store3; // for store 3 
    cout << "Store 3: ";    
    if (S%100==0) // ture if the number is just 100's
    {
        while(S > 0)
        {          
            cout << '*';        
            S=S-100; 
        }
    }   
    else
    {
        S = S + (100-S%100); //ads 99 if remianer is 1 etc so that S will be all 100's
        while(S > 0)
        {    
            cout << '*';        
            S=S-100;
        }       
    }
    cout << endl;
    S = store4; // for store 4 
    cout << "Store 4: ";    
    if (S%100==0) // ture if the number is just 100's
    {
        while(S > 0)
        {          
            cout << '*';        
            S=S-100; 
        }
    }   
    else
    {
        S = S + (100-S%100); //ads 99 if remianer is 1 etc so that S will be all 100's
        while(S > 0)
        {    
            cout << '*';        
            S=S-100;
        }       
    }
    cout << endl;
    S = store5; // for store 5 
    cout << "Store 5: ";    
    if (S%100==0) // ture if the number is just 100's
    {
        while(S > 0)
        {          
            cout << '*';        
            S=S-100; 
        }
    }   
    else
    {
        S = S + (100-S%100); //ads 99 if remianer is 1 etc so that S will be all 100's
        while(S > 0)
        {    
            cout << '*';        
            S=S-100;
        }       
    }        
}


//#14 
//Requires: val > 0
//Modifies: nothing
//Effects: returns true is val is a prime
//         returns false otherwise
//Note:  in modern mathematical usage 1 is NOT considered to be prime
bool isPrime(int val)
{
    int count = 2; 
    if (val == 1)
    {
        return 0;
    } 
    else if (val == 2) // if val is 2 then it is a prime 
    {
        return 1;
    }    
    else
    {    
        while (count < val)
        {
            if (val%count==0 || val == count) // if val is devided by count gets no remainer then it is not a prime so it will return false 
            {
                return 0;
            }
            else
            {
                count++;   
            }    
        }
        return 1; // val is not devided by any count then it is a prime so it will return true 
    }    
}

//#15 
//Requires: start > 0; end > 0
//Modifies: nothing
//Effects: prints out the primes between start and end inclusive
//if start > end, it will swap them
//if start = 5, end = 10 this prints
//5
//7
void printPrimes(int start, int end)
{
    if (start <= end)
    {
        int START = start; //saves start in START
        int END = end; //saves end in END
        while (START <= END)
        {
            int primeORnot = START;
            int count = 2;
            bool ISprime;
            ISprime = 1;
            if (primeORnot != 1)
            {    
                while ( count < primeORnot)
                {
                    if (primeORnot%count==0) // true if not a prime
                    {
                        ISprime = 0;
                        count++;
                    }    
                    else    
                        count++;   
                }
                if (ISprime == 1) // if prime is ture 
                {
                    cout << primeORnot <<  endl; // prints prime 
                }        
                START++;
            }
            else
            {
                START++;    
            }    
        }
    }
    else
    {    
        int swapend = start; //savs start in endswap
        int START = end; // swaps start with end
        int END = swapend; // swaps end and for start
        while (START <= END)
        {
            int primeORnot = START;
            int count = 2;
            bool ISprime;
            ISprime = 1;
            if (primeORnot != 1)
            {    
                while ( count < primeORnot)
                {
                    if (primeORnot%count==0) // true if not a prime
                    {
                        ISprime = 0;
                        count++;
                    }    
                    else    
                        count++;   
                }
                if (ISprime == 1)
                {
                    cout << primeORnot <<  endl; // prints if prime is true 
                }        
                START++;
            }
            else
            {
                START++;    
            }    
        }
    }
}

//#16 
//same as 'printPrimes' except this will be a 'pretty' print
//5 primes per line
//if start = 1, end = 101, this prints
//
//Prime numbers from 1 to 101 are:
//--------------------------------
//    2    3    5    7   11
//   13   17   19   23   29
//   31   37   41   43   47
//   53   59   61   67   71
//   73   79   83   89   97
//  101
// 
//you will want a setw(5) on this one to get the columns
void prettyPrintPrimes(int start, int end)
{
    cout <<  endl;
    cout << "Prime numbers from " << start << " to " << end << " are:" <<  endl;
    cout << "--------------------------------" << endl;
    int START; 
    int END;   
    if (start > end)
    {
        START = end; 
        END = start;   
    }
    else
    {    
        START = start; 
        END = end;
    }
    
    int Newline = 0;
    while (START <= END) // will be a loop unit start is larger than end -2 
    {
        if (isPrime(START)) // checks if the start is prime
        {
            cout << setw(5) << START;
            Newline++; //prints 
            if (Newline == 5) // prints new line if 5 primes have been printed
            {
                cout << endl;
                Newline = 0;
            }
        }
        START++;
    }
    
}


//#17 
//Requires: n >= 0
//Modifies: nothing
//Effects: returns the sum of the first 'n' primes
// a parameter of 5 will return
//   2 + 3 + 5 + 7 + 11 or 28
int sumPrimes(int n)
{
    int  NumberOFPrimes = 0;
    int Sumofprimes = 0;
    int START = 2; // start with the first prime (2)
    while (NumberOFPrimes != n)
    {
        if (START == 2)
        {
            Sumofprimes = Sumofprimes + START; // ads prime to sum of primes
            NumberOFPrimes++; //ad count to number of primes 
            START++;
        }
        else
        {
            bool PrimeORNot = 1;
            int count = 2;
            while (count < START)
            {
                if (START%count==0) //  if starts is not a prime then primeORnot will be false 
                {
                    PrimeORNot = 0;
                    count++;
                }
                else
                {
                    count++;   
                }    
            }
            if (PrimeORNot == 1)
            {
                Sumofprimes = Sumofprimes + START;  // ads prime to sum of primes
                NumberOFPrimes++; //ad count to number of primes 
            }
            START++;
        }    
    }
    return Sumofprimes; // returns sum of primes
} 


//#18 
//Requires: start > 0; end > 0
//Modifies: nothing
//Effects: prints out the twin primes between start and end inclusive
//if start > end, it will swap them
//if start = 1, end = 20 this prints
//(3, 5) (5, 7) (11, 13) (17, 19)
//FYI: twin primes are 2 prime numbers whose difference is 2
void printTwinPrimes(int start, int end)
{
    if (start <= end) // true if end is large than start
    {    
        int START = start; 
        int END = end;
        while (START <= (END - 2)) // will be a loop unit start is larger than end -2 
        {
            if ( isPrime(START) && isPrime(START + 2)) // checking that both are prime numbers bc we want print to print TwinPrimes not just prime and prime + 2
            {
                cout << "(" << START << ", " << START + 2 << ")" << " ";  //prints 
            }
            START++;
        }
    }
    else
    {    
        int START = end; // swaps end with start
        int END = start; // swaps start with end
        while (START <= (END - 2)) // will be a loop unit start is larger than end -2 
        {
            if ( isPrime(START) && isPrime(START + 2)) // checking that both are prime numbers bc we want print to print TwinPrimes not just prime and prime + 2
            {
                cout << "(" << START << ", " << START + 2 << ")" << " ";  //prints 
            }
            START++;
        }
    }    
}


//#19 (wrong)
//Requires: start > 0; end > 0
//Modifies: nothing
//Effects: prints out the cousin primes between start and end inclusive
//if start > end, it will swap them
//if start = 1, end = 25 this prints
//(3, 7) (7, 11) (13, 17) (19, 23)
//FYI: cousin primes are 2 prime numbers whose difference is 4
void printCousinPrimes(int start, int end)
{
    if (start <= end) // true if end is large than start
    {    
        int START = start; 
        int END = end;
        while (START <= (END - 4)) // will be a loop unit start is larger than end -4 
        {
            if ( isPrime(START) && isPrime(START + 4)) // checking that both are prime numbers bc we want print to print CousinPrimes not just prime and prime + 4
            {
                cout << "(" << START << ", " << START + 4 << ")" << " ";  //prints 
            }
            START++;
        }
    }
    else
    {    
        int START = end; // swaps end with start
        int END = start; // swaps start with end
        while (START <= (END - 4)) // will be a loop unit start is larger than end -4 
        {
            if ( isPrime(START) && isPrime(START + 4)) // checking that both are prime numbers bc we want print to print CousinPrimes not just prime and prime + 4
            {
                cout << "(" << START << ", " << START + 4 << ")" << " ";  //prints 
            }
            START++;
        }
    }    
}





//#20 
//Requires:  n > 0
//Modifies:  nothing
//Effects:  prints an equilaterial triangle
//   starting with one *
//   continuing until the last row has 'n' *'s
//   this last row will start with a * and have one space between *'s
//   with a parameter of 3 gives
//   must be left justified and must NOT have any characters past the last *
//     in any given line
// put one and only one blank line after the last line of the triangle
// do not begin with a blank line
// printEquilateral(3);
// printEquilateral(4);
// will print
//  *
// * *
//* * *
//
//   *
//  * *
// * * *
//* * * *
//
void printEquilateral(int n)
{
}
