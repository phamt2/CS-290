/* CS261- Assignment 1 - Q.1*/
/* Name:Tom Pham
 * Date:7/7/2018
 * Solution description: Allocates memory for a struct and prints out average, minimum, and maximum then deallocates memory.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *newStudent = malloc(10*(sizeof*newStudent));
     /*Return the pointer*/
     return newStudent;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/

    int count;
    int test;
    int temp;

    for (count = 0; count < 10; count++)
    {
        students[count].score = rand() % 100;
    }

    test = 1;

    for (count = 0; count < 10; count++)
    {
        students[count].id = test;
        test++;
    }

    /* Reference: Fisher Yates shuffle https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle*/
    for (count = 0; count < 10; count++)
    {
        temp = rand() % 10;

        test = students[count].id;

        students[count].id = students[temp].id;

        students[temp].id = test;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int count;
    int number = 1;

    for (count = 0; count < 10; count++)
    {
        printf("ID%d %d Score%d %d\n", number, students[count].id, number, students[count].score);
        number++;
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
    int sum = 0;
    int count;
    int average;
    int minimum;
    int maximum;

    minimum = students[0].score;
    maximum = students[0].score;

    for (count = 0; count < 10; count++)
    {
        sum = students[count].score + sum;

        if (students[count].score >= maximum)
        {
            maximum = students[count].score;
        }

        if (students[count].score <= minimum)
        {
            minimum = students[count].score;
        }
    }

    average = sum/10;

    printf("The minimum score of the ten students is %d\n", minimum);
    printf("The maximum score of the ten students is %d\n", maximum);
    printf("The average score of the ten students is %d\n", average);
     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

    free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*Call allocate*/

    stud = allocate();
    
    /*Call generate*/

    generate(stud);
    
    /*Call output*/

    output(stud);
    
    /*Call summary*/

    summary(stud);
    
    /*Call deallocate*/

    deallocate(stud);

    return 0;
}

