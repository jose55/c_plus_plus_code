//Fredrik Kjellberg
//Mathias Arkayin

#include "functions.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
     //TEST #1
     printBoard(1,1); // 1*1
     printBoard(3,2); // 3*2
     printBoard(2,3); //flip
     printBoard(5, 10); // Larger
     //end of test #1
    
     //TEST #2
     printRight(1); // n = 1 one 
     printRight(3); // n = 3 odd
     printRight(6); //  n = 6 even
     printRight(23); // Larger
     //end of test #1
    
    //TEST #3
    printRight_rightJustified(1); // n = bound
    printRight_rightJustified(1); // n = 1 one 
    printRight_rightJustified(3); // n = 3 odd
    printRight_rightJustified(6); //  n = 6 even
    printRight_rightJustified(23); // Larger
    //end  of test #4 
    
     //TEST #4
     printRight_upsideDown_rightJustified(1); // n = bound
     printRight_upsideDown_rightJustified(3); // n = 3 odd
     printRight_upsideDown_rightJustified(6); //  n = 6 even
    printRight_upsideDown_rightJustified(23); // Larger
     //end  of test #4
     
    
    
     //TEST #5
     printRight_upsideDown(1); // n = 1 one and n = bound
     printRight_upsideDown(3); // n = 3 odd
     printRight_upsideDown(6); // n = 6 even
     printRight_upsideDown(23); // n = 23 large numb
     //end of test #5
     
    
    
     //TEST #6
     threeSeries(1); //test of 1 = bound
     threeSeries(3); //test of odd
     threeSeries(2); //test of even
     threeSeries(12); //test of larger even
     threeSeries(23); //test of larger odd
     // end of test #6
     
    
     //TEST #7
     int x = 4; // both are positive 
     int y = 3;
     cout << "x is before swap:" << x << endl;
     cout << "y is before swap:" << y << endl;
     swap(x, y);
     cout << "x is now:" << x << endl;
     cout << "y is now;"<< y << endl;
     x = -3; //one is negative 
     y = 4;
    cout << "x is before swap:" << x << endl;
    cout << "y is before swap:" << y << endl;
    swap(x, y);
    cout << "x is now:" << x << endl;
    cout << "y is now;"<< y << endl;
    x = -3; //both are negative
    y = -4;
    cout << "x is before swap:" << x << endl;
    cout << "y is before swap:" << y << endl;
    swap(x, y);
    cout << "x is now:" << x << endl;
    cout << "y is now;"<< y << endl;
     //end of test #7
    
     //TEST #8
     int trueORfalse =  equalsDigit(0, 0); // testing min and min => TRUE
     cout << endl << "#1 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(100, 0); // testing true and min => TRUE
     cout << endl << "#3 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(11, 0); // testing false and min => FALSE
     cout << endl << "#4 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(91, 9); // testing true and max => TRUE
     cout << endl << "#5 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(10, 0); // testing false and min => TRUE
     cout << endl << "#6 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(0, 9); // testing min and max => FALSE
     cout << endl << "#7 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(9, 9); // testing max == max => TRUE
     cout << endl << "#8 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(453898322, 9); // testing large and max => TRUE
     cout << endl << "#9 will return: "<< trueORfalse << "!";
     
     trueORfalse =  equalsDigit(453838322, 9); // testing large and max => FALSE
     cout << endl << "#10 will return: "<< trueORfalse << "!";
     // end of #8
     
    
    
     //TEST #9
     printIfHoldsDigit(1, 1, 1); // if digit = start = end
     cout << endl;
     printIfHoldsDigit(1, 1, 0); // if digit = start > end and digit is min
     cout << endl;
     printIfHoldsDigit(5, 5, 0); // if digit is outside bound and start and end is equal and digit = 0
     cout << endl;
     printIfHoldsDigit(1, 5, 7); // if digit is outside bound and end and start is not 
     cout << endl;
     printIfHoldsDigit(23, 34, 3); // if digit < end & start and end > start
     cout << endl;
     printIfHoldsDigit(34, 23, 3); // if digit < end & start and end < start
     cout << endl;
     printIfHoldsDigit(1, 30, 2); // if digit > end > start
     cout << endl;
     printIfHoldsDigit(9, 34, 9); // end > digit and start = digit
     cout << endl;
     printIfHoldsDigit(34, 9, 9); // end = digit and start < digit
     // end test #9
     
    //TEST #10
    cout << reverseNumber(0) << endl; // bound
    cout << reverseNumber(1)  << endl; // =1 
    cout << reverseNumber(123)  << endl; // 3 digit number
    cout << reverseNumber(321)  << endl; // same 3 digit number but reversed 
    cout << reverseNumber(10) << endl; // 10 ==> 1
    cout << reverseNumber(01) << endl; // 01 ==> 1
    cout << reverseNumber(100) << endl; // 100 == 1
    // end of test #10
    
    //TEST #11
    int n = 1; // 1 ==> 1
    reverseNum(n);
    cout << n << endl;
    n = 21; // two digit number
    reverseNum(n);
    cout << n << endl;
    n = 12; //same but reversed two digit number
    reverseNum(n);
    cout << n << endl;
    n = 123456; // large 2 digit number
    reverseNum(n);
    cout << n << endl;
    n = 100; // 100 == 1
    reverseNum(n);
    cout << n << endl;
    n = 102; // 102 == 201
    reverseNum(n);
    cout << n << endl;
    n = 010; // 010 ==> 1
    reverseNum(n);
    cout << n << endl;
    n = 0; // bound
    reverseNum(n);
    cout << n << endl;
    // end of test #11
    
     // TEST #12
     cout << calcNum(1300) << endl; // test = 13 100's
     cout << calcNum(1324) << endl; // larger than 13 100's
     cout << calcNum(1) << endl; // testing 1
     cout << calcNum(0) << endl; // testing 0
     cout << calcNum(100) << endl; // testing 100 = 1
     cout << calcNum(101) << endl; // 100 should print 2 100's
     // end of test
     
     // TEST #13
     printBarChart(500, 510, 120, 750, 812); // test of  medium and small 100's and even 100's
     printBarChart(23, 5111, 0, 1, 1000); // test of large, small, and medium and 0 and 1
     // end test #13
     
    
     // TEST #14
     cout << isPrime(1); // test of one should return false
     cout << isPrime(3); // test of prime
     cout << isPrime(4); // test of non prime
     cout << isPrime(5); // test of prime
     cout << isPrime(6);
     cout << isPrime(7);
     cout << isPrime(23);
     // end test #14
     
    
    
     // TEST #15
    cout << "1: "; printPrimes(1, 1); cout << endl;
     cout << "2: "; printPrimes(2, 1); cout << endl;
     cout << "3: "; printPrimes(1, 2); cout << endl;
     cout << "4: "; printPrimes(3, 2); cout << endl; // start on a prime end on prime
     cout << "5: "; printPrimes(7, 20); cout << endl; // end on prime start on non prime
     // end test #15
     
    // TEST #16
    prettyPrintPrimes(1, 1); //test min
    prettyPrintPrimes(1, 2); // mest min and normal
    prettyPrintPrimes(1, 10); // mest min larger 
    prettyPrintPrimes(10, 1); // // mest min and normal switch
    prettyPrintPrimes(1, 101); // mest min and large
    prettyPrintPrimes(101, 101);
    prettyPrintPrimes(101, 1);
    prettyPrintPrimes(3, 11);
    prettyPrintPrimes(80, 82);
    // end of test #16
    
    
    // TEST #17
    cout << sumPrimes(0); cout << endl; // test of 0 
    cout << sumPrimes(1); cout << endl; // test of one
    cout << sumPrimes(4); cout << endl; // of  even
    cout << sumPrimes(3); cout << endl; // of odd
    cout << sumPrimes(10); cout << endl;
    cout << sumPrimes(99); cout << endl; // of large
    //end of test #17
    
    
    // TEST #18
    printTwinPrimes(5, 3); 
    printTwinPrimes(1, 1); // test of one and one
    printTwinPrimes(2, 1);
    printTwinPrimes(1, 3);
    printTwinPrimes(5, 5); // no printed 
    printTwinPrimes(6, 13);
    printTwinPrimes(2, 4); // only one pair printed
    printTwinPrimes(11, 17);
    // end of test #18
    
    // TEST #19
    printCousinPrimes(3, 7);
    printCousinPrimes(3, 11);
    printCousinPrimes(11, 3);
    printCousinPrimes(3, 7);
    printCousinPrimes(3, 13);
    printCousinPrimes(11, 17);
    printCousinPrimes(1, 1); // test of one and one
    printCousinPrimes(2, 4); // no printed 
    // end of test 19#

    // TEST #20 
    printEquilateral(1); // st of one
    printEquilateral(2); // test of 2
    printEquilateral(3);
    printEquilateral(4); 
    // end of test #20
    
    return 0;
}