//Fredrik Kjellberg, fredrikj  
//Mathias Arkayin, markayin

#include "arrays.h"
#include <iostream>
#include <fstream>

using namespace std;

//function #1 
void printArray(const int a[], int n)
{
    cout << a[0]; //prints first without 
    for (int i = 1; i < n; i++) // a for loop that will go around until i>=n
        cout << ' ' << a[i]; // prints array
    cout << endl;
}

//function #2
void printArray(const int a[][SIZE], int n)
{
    for (int row = 0; row < n; row++)// loops through the rows
    {
        cout << a[row][0]; //prints the first digit in row col = 0 without space ' '
        for (int col = 1; col < n; col++)// loops trough the digit in the col
        {
            cout << ' ' << a[row][col]; //prints each number in the row
        }
        cout << endl; //prints last endl
    }
}

//function #3 
bool isSorted(const int a[], int n)
{
    bool sorted = true; //sets sorted to true 
    for (int digit = 0; digit < n-1; digit++) // loops through each digit if the next is larger
    {
        if (a[digit] <= a[digit+1]) // true if the digit before (a[digit]) is smaller or equall to than the next (a[digit+1]) (increasing in order)
        {
            sorted = true; // sorted will be true
        }
        else // will be true if the a[digit+1] is not larger than a[digit]
        {    
            sorted = false; // sorted will be false
            break; // ends the loop as there is no need to test if the rest are in order as the previous digit where not in order   
        }    
    }
    return sorted; // return true or false
}

//function #5 
bool isFibonacci(const int a[], int n)
{
    bool fibonacci = true; // sets finonacci to true 
    
    if ( a[0] != 0) //checking the first F(0) = 0
    {    
        fibonacci = false;
        return fibonacci; // ends functions as there is no need to check the rest as the first condiction did not pass
    }
    if (n>1)
    {    
        if ( a[1] != 1) //checking the second F(1) = 1
        {    
            fibonacci = false;
            return fibonacci; // ends functions as there is no need to check the rest as the second condiction did not pass
        }
        if (n>2)
        {    
            for (int k = 2;k < n; k++) 
            {
                if (a[k] != a[k-1] + a[k-2]) // if F(k) is not F(k-1) + F(k-2), for all k > 1 returns false
                {
                    fibonacci = false; 
                    return fibonacci; // returns false
                }
            }
        }    
    }    
    return fibonacci; //returns true if all condictions are met!
}

//function #5 
void rotateLeft(int a[], int n)
{
    int temp0 = a[0]; //saves the first digit (with index 0) in a temp int
    for (int i = 0; i < n-1; i++)
    {
        a[i] = a[i+1]; //  index i+1 to index i and counting
    }
    a[n-1] = temp0; // takes the first digit and puts in in the last index
}

//function #6
void rotateRight(int a[], int n)
{
    int templast = a[n-1]; //saves the last digit (with index n-1) in a templast int
    for (int i = n-1; i > 0; i--) //starts at last index (i = n-1) and goes to the right 
    {
        a[i] = a[i-1]; //  index n-1-1 to index  and counting
    }
    a[0] = templast; // takes the last digit and puts in in the first index
}

//function #7
int getLargest(const int a[], int n)
{
	int LargestSoFar = a[0]; // saves the first digit as the largest one
    
    for (int i = 0; i < n; i++) //loops digit
    {
        if (a[i] > LargestSoFar) // tests if each digit is smaller than the largest so far
        {
            LargestSoFar = a[i]; // if it is larger it will be saved as largest so far
        }    
    }
    return LargestSoFar; // return largest 
}

//function #8
int getLargest(const int a[][SIZE], int n)
{
    int LargestSoFar = a[0][0]; // saves the first digit as the largest one
    
    for (int row = 0; row < n; row++) // loops through each row 
    {
        for (int col = 0; col < n; col++) // loops cols
        {
            if (a[row][col] > LargestSoFar) // tests if each digit is smaller than the largest so far
            {
                LargestSoFar = a[row][col]; // if it is larger it will be saved as largest so far
            }
        }
    }
    return LargestSoFar;  // return largest 
}

//function #9
void mergeTwoSortedArrays(const int a1[], const int a2[], int a3[], int n)
{
    int a = 0, b = 0, c = 0; // initializes first array (a1), second array (a2), and new array (a3) indexes to 0
    
    while ((a < n) && (b < n)) 
    {
        if (a1[a] < a2[b])
        {
            a3[c] = a1[a];
            a++; // increments a1 index
        }
        else 
        {
            a3[c] = a2[b];
            b++; // increments a2 index
        }
    c++; // increments to next position in a3
    }
    
    while (a < n) // transfers all remaining elements from a1 to a3 that have not been assigned above
    {
        a3[c] = a1[a];
        a++;
        c++;
    }
    
    while (b < n) // transfers all remaining elements from a2 to a3 that have not been assigned above
    {
        a3[c] = a2[b];
        b++;
        c++;
    }
}

//function #10
bool hasTwoEqualElements(const int a[], int n)
{
    bool EqualIntegers = false; // asumes that there are no Equal Integers
    
    for (int i = 0; i < n-1; i++)
    {
        for (int k = i+1; k < n; k++)
        {
            if (a[i] == a[k])
            {
                EqualIntegers = true;
                break;
            }
        }
    }
    return EqualIntegers; // returns if equal or not
}

//function #11
bool has_k_EqualElements(const int a[], int n, int k)
{
    int count = 1; // counts the number of eqa
    bool EqualIntegers = false; // asumes that there are no Equal Integers
    
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int num = i+1; num < n; num++)
        {
            if (a[i] == a[num])
            {
                count++; // counts the number of equl
                if (count >= k) // true if equal X k
                {
                    EqualIntegers = true;
                    return EqualIntegers;
                }
            }
        }
    }
    return EqualIntegers;
}


// function #12 try again
bool loadArrayFromFile(int a[], int & n)
{
     string FileName;
     cout << "Enter the name of file: ";
     getline(cin, FileName);

    ifstream myfile; 
    myfile.open(FileName.c_str()); 
    
    if (myfile.fail())
    {
        cout << "File didn't open";
        return false;
    }
    int digit = 0; // sets count to zero
    int i = 0; // sets count to zero
    
    while (myfile.good() && i < n)
    {
        myfile >> digit;
        if (myfile.eof()) // makes sure that right data and true when end of file 
        {
            n = i;
            myfile.close();
            return true;
        }
        if (myfile.fail()) // makes sure that right data true if wrong 
        {
            cout << "Wrong datatype in file";
            myfile.close();
            return false;
        }
        a[i] = digit;
        i++;
    }
myfile.close();
return true;
}

// function #13 try again
bool loadArrayFromFile(int a[][SIZE], int &n)
{
    string FileName;
    cout << "Enter the name of file: ";
    getline(cin, FileName);
    
    ifstream file; 
    file.open(FileName.c_str()); // reads in file 
    
    if (file.fail())
    {
        cout << "File didn't open";
        return false;
    }
    file >> n; // saves the first digit into n  
    
    int digit = 0;
    for (int h = 0; h < n; h++)// loops through the rows
    {
        for (int w = 0; w < n; w++)// loops trough the digit in the col
        {
            file >> digit;
            if (file.fail()) // makes sure that right data
            {
                cout << "Wrong datatype in file";
                file.close();
                return false;
            }
            a[h][w] = digit;
        }
    }
file.close();
return true;
}

//function #14 DONE 
void countAdjacentBombs(const char bombs[], int a[], int n)
{
    int numOFbombs = 0; 
    for (int i = 0; i <= n-1; i++)
    {
        numOFbombs = 0;
        if ((i != 0) && bombs[i-1] == '*') // true if there is a bomb to the right
        {
            numOFbombs++;
        }
        if ((i != n-1) && bombs[i+1] == '*') // true if there is a bomb to the left && checks how many boms are adjacent(only to the right) of the last digit
        {
            numOFbombs++;
        }
        a[i] = numOFbombs; // sets array a to hold x num of bombs depending on numOFbombs
    }
}

//function #15 DONE
void countAdjacentBombs(const char bombs[][SIZE], int a[][SIZE], int n)
{
    {
        int numOFbombs = 0; // bombs[Height][Width]
        for (int Height = 0; Height <= n-1; Height++)
        {
            for (int Width = 0; Width <= n-1; Width++)
            {
                numOFbombs = 0; 
                if ((Width != 0) && bombs[Height][Width-1] == '*') // true if there is a bomb to the right
                {
                    numOFbombs++;
                }
                if ((Width != n-1) && bombs[Height][Width+1] == '*')// true if there is a bomb to the left  
                {
                    numOFbombs++;
                }
                if ((Height != 0) && bombs[Height-1][Width] == '*')// true if there is a bomb above  
                {
                    numOFbombs++;
                }
                if ((Height != 0) && (Width != 0) && bombs[Height-1][Width-1] == '*')// true if there is a bomb in upper left corner  
                {
                    numOFbombs++;
                }
                if ((Height != 0) && (Width != n-1) && bombs[Height-1][Width+1] == '*')// true if there is a bomb in upper right corner  
                {
                    numOFbombs++;
                }
                if ((Height != n-1) && bombs[Height+1][Width] == '*')// true if there is a bomb to the below  
                {
                    numOFbombs++;
                }
                if ((Height != n-1) && (Width != 0) && bombs[Height+1][Width-1] == '*')// true if there is a bomb in the lower left corner  
                {
                    numOFbombs++;
                }
                if ((Height != n-1) && (Width != n-1) && bombs[Height+1][Width+1] == '*')// true if there is a bomb in the lower right corner
                {
                    numOFbombs++;
                }
                a[Height][Width] = numOFbombs; // sets array a to hold x num of bombs depending on numOFbombs
            }
        }        
    }
}

