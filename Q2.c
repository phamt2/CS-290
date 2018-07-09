/* CS261- Assignment 1 - Q.2*/
/* Name:Tom Pham
 * Date:7/7/2018
 * Solution description: Swaps the values of the pointer variables a and b. Prints out the values x,y, and zbefore calling the funciton foo and after with the swap initiated. Prints out the return value of the function foo as well to see the decremented value since the printed values were unchanged due to the function not changing the pointer value of the variable but only a copy of z.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int pointer;

    pointer = *a;
    *a = *b;
    *b = pointer;
    /*Decrement the value of integer variable c*/
    c = c - 1;   
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    
    int x = 2;
    int y = 0;
    int z = 9;
    /*Print the values of x, y and z*/
    
    printf("Value of x is %d\n", x);
    printf("Value of y is %d\n", y);
    printf("Value of z is %d\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
 
    foo(&x, &y, z);
    /*Print the values of x, y and z*/
    
    printf("Value of x is %d\n", x);
    printf("Value of y is %d\n", y);
    printf("Value of z is %d\n", z);
    /*Print the value returned by foo*/

    printf("The value returned by foo is %d\n", foo(&x, &y, z));
 
    /*a) Is the return value different than the value of integer z? Why or why not?
     *Yes because the value returned is constant to the function only as it only changes a copy of z and not the original z.*/

    /*b) Are the values of integers x and y different before and after calling the function foo(..)? Why or why not?
     *Yes because the values that the pointers are pointed to are switched each pointing to a different variable then before.*/
    
    return 0;
}
    
    


