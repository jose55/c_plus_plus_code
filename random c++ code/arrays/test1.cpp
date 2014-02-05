//Fredrik Kjellberg, fredrikj  
// Mathias Arkayin, markayin

#include "arrays.h"
#include <iostream>
#include <fstream>
using namespace std;

int main () 

{
    //test of function # 1 DONE
    int  array_for_printArray_1D1 [1]= {1}; // def. of test 1D array with 5
    printArray(array_for_printArray_1D1, 1);
    int  array_for_printArray_1D2 [2]= {1,2}; // def. of test 1D array with 5
    printArray(array_for_printArray_1D2, 2);
    int  array_for_printArray_1D3 [5]= {1,2,3,4,5}; // def. of test 1D array with 5
    printArray(array_for_printArray_1D3, 5);
    int neg[4] = {-2,-1,-5,-2};
    printArray(neg, 4);
    
    //end of test # 1
 
    // test of function  # 2 DONE
    int array_for_printArray_2D1[1][SIZE] = { // n 1 so 1x1
                                            {0}
                                            };
    printArray(array_for_printArray_2D1,1);
    
    int array_for_printArray_2D2[2][SIZE] = { // n 2 so 2x2
                                            {1,1},
                                            {1,1}
                                            };
    printArray(array_for_printArray_2D2,2); // n 3 so 3x3
    
    int array_for_printArray_2D3[3][SIZE] = {
                                            {1,2,3},
                                            {3,-4,3},
                                            {3,4,-3}
                                            };
    printArray(array_for_printArray_2D3,3);
    //end of test # 2
    
    // test of function  # 3
    int array_for_isSorted_a[1] = {1};
    cout << isSorted(array_for_isSorted_a,1); // should return true
    
    int array_for_isSorted_b[2] = {1,2};
    cout << isSorted(array_for_isSorted_b,2); // should return true
    
    int array_for_isSorted_c[2] = {2,1};
    cout << isSorted(array_for_isSorted_c,2); // should return false
    
    int array_for_isSorted_d[5] = {0,0,0,0,0};
    cout << isSorted(array_for_isSorted_d,5); // should return true
    
    int array_for_isSorted_e[9] = {1,1,3,5,5,9,9,9};
    cout << isSorted(array_for_isSorted_e,9); // should return true
    
    int array_for_isSorted_f[10] = {1,1,3,5,5,9,9,9,1};
    cout << isSorted(array_for_isSorted_f,10); // should return false
    
    int array_for_isSorted_g[5] = {5,4,3,2,1};
    cout << isSorted(array_for_isSorted_g,5); // should return false
    
    cout << isSorted(neg, 4); // should return false
    //end of test # 3
    
    // test of function # 4 DONE
    int array_for_isFibonacci_1[1] = {0}; // 1
    int array_for_isFibonacci_2[2] = {0,1}; // 1
    int array_for_isFibonacci_3[3] = {0,1,1}; // 1
    int array_for_isFibonacci_4[10] = {0,1,1,2,3,5,8,13,21,34}; // 1
    int array_for_isFibonacci_5[1] = {1}; // 0
    int array_for_isFibonacci_6[5] = {1,1,2,3,5}; // 0
    int array_for_isFibonacci_7[6] = {5,3,2,1,1,0}; // 0
    int array_for_isFibonacci_8[6] = {0,1,1,2,3,8}; // 0
    cout << isFibonacci(array_for_isFibonacci_1,1); 
    cout << isFibonacci(array_for_isFibonacci_2,2); 
    cout << isFibonacci(array_for_isFibonacci_3,3); 
    cout << isFibonacci(array_for_isFibonacci_4,10); 
    cout << isFibonacci(array_for_isFibonacci_5,1); 
    cout << isFibonacci(array_for_isFibonacci_6,5);
    cout << isFibonacci(array_for_isFibonacci_7,6);
    cout << isFibonacci(array_for_isFibonacci_8,6);
    cout << isFibonacci(neg, 4);
    // should print 1 1 1 1 0 0 0 0
    //end of test # 4
    
    // test of function  # 5
    int array_for_rotateLeft[11] = {1,2,3,4,5,1,4,5,6,7,6}; 
    rotateLeft(array_for_rotateLeft,11); // rotatesleft 
    printArray(array_for_rotateLeft,11); // prints the rotated one
    
    int array_for_rotateLeft_a[3] = {1,2,3}; 
    rotateLeft(array_for_rotateLeft_a,3); // rotatesleft 
    printArray(array_for_rotateLeft_a,3); // prints the rotated one
    
    int array_for_rotateLeft_b[4] = {1,2,3,4}; 
    rotateLeft(array_for_rotateLeft_b,4); // rotatesleft 
    printArray(array_for_rotateLeft_b,4); // prints the rotated one
    
    int array_for_rotateLeft_c[11] = {1,2,3,4,-5,1,4,5,6,7,6}; 
    rotateLeft(array_for_rotateLeft_c,11); // rotatesleft 
    printArray(array_for_rotateLeft_c,11); // prints the rotated one
    
    int array_for_rotateLeft_d[3] = {1}; 
    rotateLeft(array_for_rotateLeft_d,3); // rotatesleft 
    printArray(array_for_rotateLeft_d,3); // prints the rotated one
    
    rotateLeft(neg, 4);
    printArray(neg, 4);
    // end of test # 5 
    
    // test of function  # 6
    int array_for_rotateRight[5] = {1,2,3,4,5};
    rotateRight(array_for_rotateRight,5); // rotatesleft 
    printArray(array_for_rotateRight,5); // prints the rotated one
    
    int array_for_rotateRight_1[11] = {1,2,3,4,5,1,4,5,6,7,6}; 
    rotateLeft(array_for_rotateRight_1,11); // rotatesleft 
    printArray(array_for_rotateRight_1,11); // prints the rotated one
    
    int array_for_rotateRight_a[3] = {1,2,3}; 
    rotateLeft(array_for_rotateRight_a,3); // rotatesleft 
    printArray(array_for_rotateRight_a,3); // prints the rotated one
    
    int array_for_rotateRight_b[4] = {1,2,3,4}; 
    rotateLeft(array_for_rotateRight_b,4); // rotatesleft 
    printArray(array_for_rotateRight_b,4); // prints the rotated one
    
    int array_for_rotateRight_c[11] = {1,2,3,-4,5,1,4,5,6,7,6}; 
    rotateLeft(array_for_rotateRight_c,11); // rotatesleft 
    printArray(array_for_rotateRight_c,11); // prints the rotated one
    
    int array_for_rotateRight_d[3] = {1}; 
    rotateLeft(array_for_rotateRight_d,3); // rotatesleft 
    printArray(array_for_rotateRight_d,3); // prints the rotated one
    
    rotateRight(neg, 4);
    printArray(neg, 4);
    // end of test # 6 
    
    // test of function # 7 DONE
    int array_for_getLargest_test1[5] = {1,4,5,3,2};
    cout << getLargest(array_for_getLargest_test1,5); //should return 5
    
    int array_for_getLargest_test2[5] = {1,3,3,3,2};
    cout << getLargest(array_for_getLargest_test2,5);// should return 3
    
    int array_for_getLargest_test3[3] = {9,9,9};
    cout << getLargest(array_for_getLargest_test3,3);// should return 9
    
    int array_for_getLargest_test4[5] = {9,1,1,1,1};
    cout << getLargest(array_for_getLargest_test4,5);// should return 1
    
    int array_for_getLargest_test5[5] = {1,1,1,1,9};
    cout << getLargest(array_for_getLargest_test5,5);// should return 9
    
    int array_for_getLargest_test6[1] = {9};
    cout << getLargest(array_for_getLargest_test6,1);// should return 9
    
    int array_for_getLargest_test7[1] = {1};
    cout << getLargest(array_for_getLargest_test7,1);// should return 1
    
    cout << getLargest(neg, 4); // should return -1
    //end of  test # 7
    
    // test of function # 8 DONE
    int array_for_getLargest_2D_test1[2][SIZE] = { 
                                                {1,4},
                                                {5,3} 
                                                }; 
    cout << getLargest(array_for_getLargest_2D_test1 , 2); // returns 5
    int array_for_getLargest_2D_test2[2][SIZE] = { 
                                                {-1,-4},
                                                {-4,-3} 
                                                };  
    cout << getLargest(array_for_getLargest_2D_test2, 2); // returns 4
    int array_for_getLargest_2D_test3[2][SIZE] = { 
                                                {4,4},
                                                {4,4} 
                                                }; 
    cout << getLargest(array_for_getLargest_2D_test3, 2); // returns 4
    
    int array_for_getLargest_2D_test4[1][SIZE] = {{1}}; 
    cout << getLargest(array_for_getLargest_2D_test4, 1); // returns 5
    
    int array_for_getLargest_2D_test5[1][SIZE] = {{-1}}; 
    cout << getLargest(array_for_getLargest_2D_test5, 1); // returns 5
    // end of test # 8
   
    
    //test of function # 9
    int array_for_mergeTwoSortedArrays_a1_T1[4] = {1,3,5,7};
    int array_for_mergeTwoSortedArrays_a2_T1[4] = {2,4,6,8};
    int array_for_mergeTwoSortedArrays_a3_T1[8] = {0};
    mergeTwoSortedArrays(array_for_mergeTwoSortedArrays_a1_T1, array_for_mergeTwoSortedArrays_a2_T1, array_for_mergeTwoSortedArrays_a3_T1, 4); 
    printArray(array_for_mergeTwoSortedArrays_a3_T1,8); // a3 {1,2,3,4,5,6,7,8}
    
    int array_for_mergeTwoSortedArrays_a1_T2[4] = {1,1,5,7};
    int array_for_mergeTwoSortedArrays_a2_T2[4] = {2,4,5,8};
    int array_for_mergeTwoSortedArrays_a3_T2[8] = {0};
    mergeTwoSortedArrays(array_for_mergeTwoSortedArrays_a1_T2, array_for_mergeTwoSortedArrays_a2_T2, array_for_mergeTwoSortedArrays_a3_T2, 4); 
    printArray(array_for_mergeTwoSortedArrays_a3_T2,8); // a3 {1,1,2,4,5,5,7,8}
    
    int array_for_mergeTwoSortedArrays_a1_T3[2] = {1,1};
    int array_for_mergeTwoSortedArrays_a2_T3[2] = {2,2};
    int array_for_mergeTwoSortedArrays_a3_T3[4] = {0};
    mergeTwoSortedArrays(array_for_mergeTwoSortedArrays_a1_T3, array_for_mergeTwoSortedArrays_a2_T3, array_for_mergeTwoSortedArrays_a3_T3, 2); 
    printArray(array_for_mergeTwoSortedArrays_a3_T3,4); // a3 {1,1,2,2}
    
    int array_for_mergeTwoSortedArrays_a1_T4[4] = {1,1,2,2};
    int array_for_mergeTwoSortedArrays_a2_T4[4] = {1,1,2,3};
    int array_for_mergeTwoSortedArrays_a3_T4[8] = {0};
    mergeTwoSortedArrays(array_for_mergeTwoSortedArrays_a1_T4, array_for_mergeTwoSortedArrays_a2_T4, array_for_mergeTwoSortedArrays_a3_T4, 4); 
    printArray(array_for_mergeTwoSortedArrays_a3_T4,8); // a3 {1,1,1,1,2,2,2,3}
    
    int array_for_mergeTwoSortedArrays_a1_T5[1] = {-1};
    int array_for_mergeTwoSortedArrays_a2_T5[1] = {-2};
    int array_for_mergeTwoSortedArrays_a3_T5[2] = {0};
    mergeTwoSortedArrays(array_for_mergeTwoSortedArrays_a1_T5, array_for_mergeTwoSortedArrays_a2_T5, array_for_mergeTwoSortedArrays_a3_T5, 1); 
    printArray(array_for_mergeTwoSortedArrays_a3_T5,2); // a3 {1,2}
    
    int array_for_mergeTwoSortedArrays_a1_T6[1] = {1};
    int array_for_mergeTwoSortedArrays_a2_T6[1] = {2};
    int array_for_mergeTwoSortedArrays_a3_T6[2] = {0};
    mergeTwoSortedArrays(array_for_mergeTwoSortedArrays_a1_T6, array_for_mergeTwoSortedArrays_a2_T6, array_for_mergeTwoSortedArrays_a3_T6, 1); 
    printArray(array_for_mergeTwoSortedArrays_a3_T6,2); // a3 {1,2}
    // end test #9
    
    
    //test of function # 10 DONE
    int EqualElements_b[1] = {1};
    cout << hasTwoEqualElements(EqualElements_b, 1); //0
    int EqualElements_k[1] = {1};
    cout << hasTwoEqualElements(EqualElements_k, 1); //0
    int EqualElements_c[2] = {1,5};
    cout << hasTwoEqualElements(EqualElements_c, 2); //0
    int EqualElements_j[2] = {1,1};
    cout << hasTwoEqualElements(EqualElements_j, 2); //1
    int EqualElements_a[5] = {1,5,1,5,2};
    cout << hasTwoEqualElements(EqualElements_a, 5); //1
    int EqualElements_d[2] = {1,1};
    cout << hasTwoEqualElements(EqualElements_d, 2); //1 
    int EqualElements_e[3] = {1,5,1};
    cout << hasTwoEqualElements(EqualElements_e, 3); //1 
    int EqualElements_f[5] = {1,5,1,5,2};
    cout << hasTwoEqualElements(EqualElements_f, 5); //1
    int EqualElements_g[5] = {1,5,1,5,1};
    cout << hasTwoEqualElements(EqualElements_g, 5); //1 
    int EqualElements_h[5] = {1,1,1,5,1};
    cout << hasTwoEqualElements(EqualElements_h, 5); //1 
    int EqualElements_i[5] = {1,2,3,4,8};
    cout << hasTwoEqualElements(EqualElements_i, 5); //0
    cout << hasTwoEqualElements(neg, 4); // 1
    // end of test # 10
    
    //test of function # 11 DONE
    int k_EqualElements_b[1] = {1};
    cout << has_k_EqualElements(k_EqualElements_b, 1, 2); //0
    int k_EqualElements_k[1] = {1};
    cout << has_k_EqualElements(k_EqualElements_k, 1, 3); //0
    int k_EqualElements_c[2] = {1,5};
    cout << has_k_EqualElements(k_EqualElements_c, 2, 2); //0
    int k_EqualElements_j[2] = {1,1};
    cout << has_k_EqualElements(k_EqualElements_j, 2, 3); //0
    int k_EqualElements_a[5] = {1,5,1,5,2};
    cout << has_k_EqualElements(k_EqualElements_a, 5, 2); //1
    int k_EqualElements_d[2] = {1,1};
    cout << has_k_EqualElements(k_EqualElements_d, 2, 2); //1 
    int k_EqualElements_e[3] = {1,5,1};
    cout << has_k_EqualElements(k_EqualElements_e, 3, 2); //1 
    int k_EqualElements_f[5] = {1,5,1,5,2};
    cout << has_k_EqualElements(k_EqualElements_f, 5, 2); //1
    int k_EqualElements_g[5] = {1,5,1,5,1};
    cout << has_k_EqualElements(k_EqualElements_g, 5, 3); //1 
    int k_EqualElements_h[5] = {1,1,1,5,1};
    cout << has_k_EqualElements(k_EqualElements_h, 5, 4); //1 
    int k_EqualElements_i[5] = {1,5,1,5,1};
    cout << has_k_EqualElements(k_EqualElements_i, 5, 2); //1
    cout << has_k_EqualElements(neg, 4, 2); // 1
    // ==> 0 0 0 0 1 1 1 1 1 1 1 1
    // end of test # 11
    
    //test of function # 14 DONE
    int bombsornotarray[] = {0};
    
    char BOMB_ARRAY_n2a[] = {'.','.'}; // 2 and bombs holds: . .
    int index = 2;
    countAdjacentBombs(BOMB_ARRAY_n2a,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 0 1
    
    char BOMB_ARRAY_n2b[] = {'*','*'}; // 2 and bombs holds: . *
    index = 2;
    countAdjacentBombs(BOMB_ARRAY_n2b,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 0 1
    
    char BOMB_ARRAY_n2c[] = {'.','*'}; // 2 and bombs holds: . *
    index = 2;
    countAdjacentBombs(BOMB_ARRAY_n2c,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 0 1
    
    char BOMB_ARRAY_n2d[] = {'*','.'}; // 2 and bombs holds: . *
    index = 2; 
    countAdjacentBombs(BOMB_ARRAY_n2d,bombsornotarray, index);
    printArray(bombsornotarray,index);// prints 1 0 
    
    char BOMB_ARRAY_n1a[] = {'.'}; // 1 and bombs holds: .
    index = 1;
    countAdjacentBombs(BOMB_ARRAY_n1a,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 0
    
    char BOMB_ARRAY_n1b[] = {'*'}; // 1 and bombs holds: *
    index = 1;
    countAdjacentBombs(BOMB_ARRAY_n1b,bombsornotarray, index);
    printArray(bombsornotarray,index);// prints 0
    
    char BOMB_ARRAY_n10a[] = {'*','*','.','.','*','*','*','*','.','*'}; // 10 and bombs holds: . * . . * * * * . *
    index = 10;
    countAdjacentBombs(BOMB_ARRAY_n10a,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 1 0 1 1 0 2 1 1 2 0
    
    char BOMB_ARRAY_n10b[] = {'.','*','.','.','*','.','*','*','.','.'}; // 10 and bombs holds: . * . . * . * * . *
    index = 10; 
    countAdjacentBombs(BOMB_ARRAY_n10b,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 1 0 1 1 0 2 1 1 2 0
    
    char BOMB_ARRAY_n11b[] = {'*','*','.','.','*','.','*','*','.','.'}; // 10 and bombs holds: . * . . * . * * . *
    index = 10; 
    countAdjacentBombs(BOMB_ARRAY_n11b,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 1 0 1 1 0 2 1 1 2 0
    
    char BOMB_ARRAY_n12b[] = {'*','*','*','*','*','*','*','*','*','*'}; // 10 and bombs holds: . * . . * . * * . *
    index = 10; 
    countAdjacentBombs(BOMB_ARRAY_n12b,bombsornotarray, index);
    printArray(bombsornotarray,index); // prints 1 0 1 1 0 2 1 1 2 0
    // end test #9
    
    //test of function # 15 DONE
    int bombsornotarray_a[][SIZE] = {0};
    char BOMB_ARRAY_2D[][SIZE] = {
        {'.','*','.'},
        {'*','.','.'},
        {'*','*','*'}
    };
    countAdjacentBombs(BOMB_ARRAY_2D,bombsornotarray_a, 3);
    printArray(bombsornotarray_a,3);
    cout << endl;
    
    int bombsornotarray_b[][SIZE] = {0}; // testing 2x2
    char BOMB_ARRAY_2Db[][SIZE] = {
        {'.','*'},
        {'*','.',},
    };
    countAdjacentBombs(BOMB_ARRAY_2Db,bombsornotarray_b, 3);
    printArray(bombsornotarray_b,3);
    
    int bombsornotarray_c[][SIZE] = {0}; // testing 4x4 one place with no bombs ajacent
    char BOMB_ARRAY_2Dc[][SIZE] = {
        {'.','*','.','.'},
        {'*','.','.','.'},
        {'*','*','*','*'},
        {'*','*','*','*'}
    };
    countAdjacentBombs(BOMB_ARRAY_2Dc,bombsornotarray_c, 4);
    printArray(bombsornotarray_c,4);
    
    int bombsornotarray_d[][SIZE] = {0}; // testing 1x1 with no bomb
    char BOMB_ARRAY_2Dd[][SIZE] = {{'.'}};
    countAdjacentBombs(BOMB_ARRAY_2Dd,bombsornotarray_d, 1);
    printArray(bombsornotarray_d,1);
    
    int bombsornotarray_e[][SIZE] = {0};// testing 1x1 with 1 bomb
    char BOMB_ARRAY_2De[][SIZE] = {{'*'}};
    countAdjacentBombs(BOMB_ARRAY_2De,bombsornotarray_e, 1);
    printArray(bombsornotarray_e,1);
    
    int bombsornotarray_f[][SIZE] = {0}; // testing 4x4 one place with no bombs ajacent
    char BOMB_ARRAY_2Df[][SIZE] = {
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'.','.','.','.'}
    };
    countAdjacentBombs(BOMB_ARRAY_2Df,bombsornotarray_f, 4);
    printArray(bombsornotarray_f,4);
    
    int bombsornotarray_g[][SIZE] = {0}; // testing 2x2
    char BOMB_ARRAY_2Dg[][SIZE] = {
        {'*','*'},
        {'*','*',},
    };
    countAdjacentBombs(BOMB_ARRAY_2Dg,bombsornotarray_g, 3);
    printArray(bombsornotarray_g,3);
    
    int bombsornotarray_k[][SIZE] = {0}; // testing 4x4 one place with no bombs ajacent
    char BOMB_ARRAY_2Dk[][SIZE] = {
        {'*','*','*','*'},
        {'*','*','*','*'},
        {'*','*','*','*'},
        {'*','*','*','*'},
    };
    countAdjacentBombs(BOMB_ARRAY_2Dk,bombsornotarray_k, 4);
    printArray(bombsornotarray_k,4);
    
    int bombsornotarray_l[][SIZE] = {0}; // testing 4x4 one place with no bombs ajacent
    char BOMB_ARRAY_2Dl[][SIZE] = {
        {'*','.','.','*'},
        {'.','.','.','.'},
        {'.','.','.','.'},
        {'*','.','.','*'}
    };
    countAdjacentBombs(BOMB_ARRAY_2Dl,bombsornotarray_l, 4);
    printArray(bombsornotarray_l,4);
    
    int bombsornotarray_m[][SIZE] = {0}; // testing 4x4 one place with no bombs ajacent
    char BOMB_ARRAY_2Dm[][SIZE] = {
        {'.','*','.'},
        {'*','*','*'},
        {'.','*','.'}
    };
    countAdjacentBombs(BOMB_ARRAY_2Dm,bombsornotarray_m, 4);
    printArray(bombsornotarray_m,4);
    
    return 0;
}


