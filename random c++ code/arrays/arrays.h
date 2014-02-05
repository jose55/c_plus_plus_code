#ifndef ARRAYS_H
#define ARRAYS_H

const int SIZE = 20;

// Requires: The size of array a is n && n > 0
// Modifies: Nothing
// Effects:  Prints the elements of the array separated with a space
//           Prints an endl at the end
//
//           e.g., If array a contains {1,2,3} then the following code:
// 
//                 printArray(a,3); 
//                 cout << "Hello";
//
//                 will print:
//                 
//                 1 2 3
//                 Hello
//
//                 Note that there must be no space after 3 in the above example
//
void printArray(const int a[], int n);


// Requires: The size of array a is n x n && 0 < n && n <= SIZE
// 
//           i.e., Even though array a is allocated with SIZE columns, 
//                 only the first n columns are being used
// 
// Modifies: Nothing
// 
// Effects:  Prints the elements of the array separated with a space
//             one row per line
//           Prints an endl at the end
//
//           e.g., If array a contains {{1,2}, {3,4}} then the following code:
// 
//                 printArray(a,2); 
//                 cout << "Hello";
//
//                 will print:
//                 
//                 1 2
//                 3 4
//                 Hello
//
//                 Note that there must be no spaces after 2 and 4 above
//
void printArray(const int a[][SIZE], int n);


// Requires: The size of array a is n && n > 0
// Modifies: Nothing
// Effects:  Returns true iff array a is sorted in increasing order
//           e.g., Array {1,2,3,4,5} is sorted
//                 Array {1,1,3,5,5} is sorted
//                 Array {1,4,3,5,2} is not sorted
//                 Array {5,4,3,2,1} is not sorted
bool isSorted(const int a[], int n);


// Requires: The size of array a is n && n > 0
// Modifies: Nothing
// Effects:  Returns true iff array a contains the first n numbers of the
//           Fibonacci sequence in order
//
//           The Fibonacci sequence is defined as follows:
//             F(0) = 0
//             F(1) = 1
//             F(k) = F(k-1) + F(k-2), for all k > 1
//
//           e.g., The function returns true  on {0,1,1,2,3,5}
//                 The function returns false on {1,1,2,3,5}
//                 The function returns false on {5,3,2,1,1,0}
//                 The function returns false on {0,1,1,2,3,8}
//                 The function returns true  on {0,1,1,2,3,5,8,13,21,34}
bool isFibonacci(const int a[], int n);


// Requires: The size of array a is n && n > 0
// Modifies: The array a
// Effects:  Rotates the array by one element to the left 
//           e.g., Array {1,2,3,4,5} when rotated left becomes {2,3,4,5,1}
void rotateLeft(int a[], int n);


// Requires: The size of array a is n && n > 0
// Modifies: The array a
// Effects:  Rotates the array by one element to the right 
//           e.g., Array {1,2,3,4,5} when rotated right becomes {5,1,2,3,4}
void rotateRight(int a[], int n);


// Requires: The size of array a is n && n > 0
// Modifies: Nothing
// Effects:  Returns the largest element in the array
//           e.g., Given {1,4,5,3,2} the function returns 5
//                 Given {1,4,4,3,2} the function returns 4
int getLargest(const int a[], int n);


// Requires: The size of array a is n x n && 0 < n && n <= SIZE
// Modifies: Nothing
// Effects:  Returns the largest element in the array
//           e.g., Given { {1,4}, {5,3} } the function returns 5
//                 Given { {1,4}, {4,3} } the function returns 4
int getLargest(const int a[][SIZE], int n);


// Requires: The size of array a1 is  n && n > 0
//           The size of array a2 is  n
//           The size of array a3 is 2n
//           Array a1 is sorted in increasing order
//           Array a2 is sorted in increasing order
//
// Modifies: The array a3
//
// Effects:  Merges a1 and a2 into a3 in sorted increasing order
//           e.g., If a1 is {1,3,5,7} and a2 is {2,4,6,8} then 
//                   the function must set a3 to {1,2,3,4,5,6,7,8}
//                 If a1 is {1,1,5,7} and a2 is {2,4,5,8} then 
//                   the function must set a3 to {1,1,2,4,5,5,7,8}
void mergeTwoSortedArrays(const int a1[], const int a2[], int a3[], int n);


// Requires: The size of array a is n && n > 0
// Modifies: Nothing
// Effects:  Returns true iff at least two of the array elements are equal
//           e.g., Returns true  on {1,4,1,5,2} because a[0]==a[2]
//                 Returns true  on {1,4,4,1,1} because a[0]==a[3]
//                 Returns false on {1,4,3,5,2}
bool hasTwoEqualElements(const int a[], int n);


// Requires: The size of array a is n && n > 0 && k > 1
// Modifies: Nothing
// Effects:  Returns true iff at least k of the array elements are equal
//           e.g., If k=2 then returns true  on {1,4,1,5,2} because a[0]==a[2]
//                 If k=3 then returns false on {1,4,1,5,2}
//                 If k=2 then returns true  on {1,4,5,1,1} because a[0]==a[3]
//                 If k=3 then returns true  on {1,4,5,1,1} because a[0]==a[3]==a[4]
//                 If k=4 then returns false on {1,4,5,1,1} 
bool has_k_EqualElements(const int a[], int n, int k);


// Requires: The maximum size of array a is n && n > 0
// Modifies: The array a and n
// Effects:  Asks for name of a file to read data from
//           Opens the file
//           Reads data and enters valid data into the array
// 
//           You may assume that the number of data items in the file <= n
// 
//           If all goes well, sets n to hold the number of values read
//             and returns true
// 
//           If anything goes wrong, returns false.  It is okay to set n and 
//             the elements of array a to arbitrary values in that case.
// 
// Prompt:  "Enter the name of file: "
//          "File didn't open" 
//          "Wrong datatype in file"
bool loadArrayFromFile(int a[], int &n);


// Requires: The maximum size of array a is SIZE x SIZE && SIZE > 0
// Modifies: The array a and n
// Effects:  Asks for name of a file to read data from
//           Opens the file
//           The first number in the file (say, k) will be the number of rows 
//             and number of columns
//           The rest of the file contains the data 
// 
//           You may assume that the rest of the file contains k*k data items
//           You may also assume that k <= SIZE
// 
//           The function reads the data and enters valid data into the array
// 
//           If all goes well, sets n to k (that is, the number of rows & cols)
//               and returns true
// 
//           If anything goes wrong, returns false.  It is okay to set n and 
//             the elements of array a to arbitrary values in that case.
// 
// Prompt:  "Enter the name of file: "
//          "File didn't open" 
//          "Wrong datatype in file"
bool loadArrayFromFile(int a[][SIZE], int &n);


// Requires: The size of array bombs and array a is n && n > 0
// 
//           Format of the array bombs is as follows:
//             It contains a '*' if there is a  bomb in that location
//             It contains a '.' if there is no bomb in that location
// 
// Modifies: The array a
// 
// Effects:  Sets array a to hold the number of bombs adjacent to each location
//           
//           e.g., If n == 10 and bombs holds: . * . . * . * * . *
//                 then sets array a to hold:  1 0 1 1 0 2 1 1 2 0
// 
void countAdjacentBombs(const char bombs[], int a[], int n);


// Requires: The size of array bombs and array a is n x n && n > 0
// 
//           Format of the array bombs is as follows:
//             It contains a '*' if there is a  bomb in that location
//             It contains a '.' if there is no bomb in that location
// 
// Modifies: The array a
// 
// Effects:  Sets array a to hold the number of bombs adjacent to each location
//           Left, right, above, below, & diagonal are all considered adjacent
//
//           e.g., If n == 3 and bombs holds: . * .
//                                            * . . 
//                                            * * * 
// 
//                 then sets array a to hold: 2 1 1
//                                            3 5 3
//                                            2 3 1
// 
void countAdjacentBombs(const char bombs[][SIZE], int a[][SIZE], int n);

#endif
