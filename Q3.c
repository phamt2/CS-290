/* CS261- Assignment 1 - Q.3*/
/* Name: 
 * Date: 
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
    if (ch != '\0' && ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
    }

    return ch;

}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/
    if (ch != '\0' && ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
    }

    return ch;

}

int stringLength(char s[]) {
   /*Return the length of the string*/
    int length = 0;

    while (s[length] != '\0')
    {
        length++;
    }


    return length;
}


void camelCase(char* word){
	/*Convert to camelCase*/

    int length;
    int count;

    int nCount = 0;
    char nWord[500];
    

    length = stringLength(word);

    for (count = 0; count < length; count++)
    {
        if ((word[count] >= 65 && word[count] <= 90) || (word[count] >= 97 && word[count] <= 122))
        {
                nWord[nCount] = word[count];
                nCount++;
        }
        else if ((word[count+1] >= 65 && word[count+1] <= 90) || (word[count+1] >= 97 && word[count+1] <= 122))
        {
            word[count+1] = toUpperCase(word[count+1]);
        }
    }

    for (count = 0; count <= nCount; count++)
    {
        word[count] = nWord[count];
    }
    
}

int main(){

	/*Read the string from the keyboard*/
    char string[500];
    int length;
    int count;
    int test = 0;
    int nCount = 0;
    char newString[500];

	printf("Please enter a string.\n");

	scanf("%s", string);

    length = stringLength(string);

    for (count = 0; count < length; count++)
    {
        if ((string[count] >= 65 && string[count] <= 90) || (string[count] >= 97 && string[count] <= 122))
        {
                newString[nCount] = string[count];
                nCount++;
        }

        else if ((string[count+1] >= 65 && string[count+1] <= 90) || (string[count+1] >= 97 && string[count+1] <= 122))
        {
            test = test + 1;

            if (nCount == 0)
            {
            }

            else
            {
                newString[nCount] = '_';
                nCount++;
            }
        }

    }

    for (count = 0; count <= nCount; count++)
    {
        string[count] = newString[count];
    }

    string[0] = toLowerCase(string[0]);

    for (count = 0; count <= nCount; count++)
    {
        if (string[count] == '_')
        {
            string[count+1] = toLowerCase(string[count+1]);
        }

        else if (string[count+1] >= 65 && string[count+1] <= 90)
        {
            string[count+1] = toLowerCase(string[count+1]);
        }
    }

    if (test < 2 || string[0] == '\0')
    {
        printf("%s", "invalid input string");
    }

    else
    {
        /*Call camelCase*/

        camelCase(string);

        /*Print the new string*/
        
        printf("This is the Camel Case version of the string %s\n", string);
        
        /*"_", "__ _", " ", "435_%7_$$", "random", "_random_". Print “invalid input string” for such cases.*/
    }

	return 0;
}

