#include <stdio.h>

/* 
   Defines::  
             TARGET: is defined as a white space character. This Will allow for the method
                     to determine if it has reached the end of a letter block. 
 
             TERMINATOR: is defined as the terminator character. This is used for find the 
                         end of a string. If Changed, will crash this program, as the while
                         loop might try to access memory that is out of bound of the character
                         arrays range. 
 
              FALSE: is defined as the integer value of 0; or the logical false. If changed
                     could result in an error. As this value is returned for the isWhiteSpace
                     function. The Caller of that function will be expecting a one or zero.
 
 
              TRUE: is defined as the integer value of 1; or the logical true. If changed 
                    could result in an error or crash of the program. As this Value, is returned
                    for the isWhiteSpace function. The Caller of that function will be expecting 
                    a one or zero.
 */
#define TARGET ' '
#define TERMINATOR '\0'
#define FALSE 0
#define TRUE 1

int main(int argc, char **argv)
{
    /* Methods */
    int CountNumWordsInSentence(const char* InString);
    int findLenght(const char* string);
    int isWhiteSpace(char n);
    
    /* Given Cases */
    int num1 = CountNumWordsInSentence("A BIG DOG ");  /* 3 */
    int num2 = CountNumWordsInSentence("A");           /* 1 */
    int num3  = CountNumWordsInSentence(" BC");        /* 1 */
     
    /* Edge Case Attempts */
    int num4 = CountNumWordsInSentence(" Hello World");                          /* 2 */
    int num5 = CountNumWordsInSentence("A B C D EFG    HIJKL  MN O P");          /* 9 */
    int num6 = CountNumWordsInSentence(" Game    Over    Man      Game O ver");  /* 6 */
    
    /* Print the Result Out */
    fprintf(stderr, "%d\n%d\n%d\n%d\n%d\n%d\n", num1, num2, num3, num4, num5, num6);
    
    exit(0);
}

/* Determine The number of letter blocks in a string
   @Param:: const char* InString : Character array to check
   @Return:: int : 0 If the string is NULL, else will return the number
                   of blocks in an array of characters.
 */
int CountNumWordsInSentence(const char* InString)
{
    if(!InString) return 0;                              /* If Null string, return 0 */
    else                                                 /* Else process the string  */
    {
        int numOfWords = 0, white = 0, i;
        int lenght = findLenght(InString);               /* Find the Length          */
        
        for(i = 0; i < lenght; i++)                      /* For each place in the string          */
            if(!isWhiteSpace(InString[i]) && i == 0)     /* If the first place, and not a white   */
                numOfWords++;                            /* space, increment the num of words up  */
            else if(!isWhiteSpace(InString[i]) && white == TRUE)
            {                                            /* Else if, not a white space and, last character               */
                numOfWords++;                            /* was a white space, then we must be on a new word             */
                white = FALSE;                           /* increment the wordcount, and flip the whitespace check back  */
            }
            else if(isWhiteSpace(InString[i]))           /* Else, if it is at least is at least a white space  */
                white = TRUE;                            /* then flip the whitespace check                     */
        
        return numOfWords;                               /* Return the num of words. */
    }
}

/* Determine the length of the string
   @Param:: const char* string : Character array to check
   @Return:: int : 0 If the string is NULL, else will return the length of the
                   String.
 */
int findLenght(const char* string)
{
    if(!string) return 0;   /* If NULL string return 0                */
    else                    /* Else iterate through the string        */
    {                       /* Till we find the terminating character */
        int len = 0;
        
        while(*string++ != TERMINATOR)
            ++len;          /* Increment the length  */
        
        return len;         /* Return the length     */
    }
}

/* Determine if the character is a white space(Target) or not.
   @Param:: char n: Character to check
   @Return:: int : 0 if not a whitespace, 1 if a whitespace
 */
int isWhiteSpace(char n)
{
    if(n == TARGET)    /* If it is a white space; Return True */
        return TRUE;
    else return FALSE; /* Else assume character( for time sake), return False */
}
