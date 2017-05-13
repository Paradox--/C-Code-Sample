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
    int CountNumWordsInSentence(const char *InString);
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
int CountNumWordsInSentence(const char *InString)
{
    if(!InString) return 0;                              /* If Null string, return 0 */
    else                                                 /* Else process the string  */
    {
       int numOfWords = 0, white = FALSE; 
      
       while(*InString != TERMINATOR){                         
            if(!white && !isWhiteSpace(*InString))              /* If the last wasnt a white space and the      */
               numOfWords++;                                    /* current isnt a white space. Increment.       */
            white = !isWhiteSpace(*InString);                   /* Set the white check based on the current pos */
            *InString++;
       }
       
        return numOfWords;                               /* Return the num of words. */
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
