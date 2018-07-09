/* CS261- Assignment 1 - Q. 0*/
/* Name:Tom Pham
 * Date:7/6/2018
 * Solution description: Prints out value and address of variables and pointers. As well as increments and decrements value of the integer that is pointed.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
     printf("The value of iptr is %d\n", *iptr);
     printf("The address of iptr is %p\n", iptr);
          
     /*Increment the value of the integer pointed to by iptr by 5*/
     *iptr = *iptr + 5;
          
     /*Print the address of iptr itself*/
     printf("The address of iptr itself is %p\n", &iptr);
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/

    printf("The value of jptr is %d\n", *jptr);
    printf("The address of jptr is %p\n", jptr);
               
     /*Decrement jptr by 1*/

    *jptr = *jptr - 1;
      
     /*Print the address of jptr itself*/

    printf("The address of jptr itself is %p\n", &jptr);
}


int main(){
    
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/
    int x = 5;

    /*Print the value and address of x*/
    
    printf("This is the value of x %d\n", x);
    printf("This is the address of x %p\n", &x);

    /*Call fooA() with the address of x*/
    
    fooA(&x);

    /*Print the value of x*/

    printf("This is the new value of x %d\n", x);
    
    /*Is the value of x different than the value that was printed at first? Why or why not?
     *Yes because after the function was ran the x value was changed within the function and when called outside of the function the variable had been changed to reflect the changes made in the function.*/
    
    /*Call fooB() with the address of x*/

    fooB(&x);
    
    /*Print the value and address of x*/

    printf("This is the new new value of x %d\n", x);
    printf("This is the address of x %p\n", &x);

    /*Are the value and address of x different than the value and address that were printed before the call to fooB(..)? Why or why not?
     *The value of the variable is different as fooB() decremented the value directly while the address never changed because the address of a variable remains static regardless of the changes.*/

    return 0;
}


