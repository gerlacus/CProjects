// FINISH THIS:
// issue: can't seem to understand how to manipulate string in C to allow me to turn it into an int


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ) {
    if (argc != 2) {
        printf( "usage: %s string_of_ints\n", argv[0] );
        exit(0);
    }
    // essentially loop through each char in argument string (e.g. "789")
    // '7' - '0' = actual ASCII int value, which in this case is 7
    // then, add that to previous int (but previous int * 10 because new decimal place)
    //
    //
    char * inputStr = argv[1];
    unsigned int runningTotal = 0;

    printf( "Input string: %s\n", inputStr );
    printf( "converting to integer...\n");

    for ( int i = 0;  i < strlen( inputStr );  i++) {
        //printf("Current character: %c\n", inputStr[i]);
        // check to see if character is within range of acceptable ASCII values (numbers)
        if ( inputStr[i] < 48 || inputStr[i] > 57 ) {
            printf( "Input must be a string of positive integers.\n" );
            exit( 0 );
        }
        runningTotal *= 10;
        runningTotal += ( inputStr[i] - '0' );
        //printf( "Current running total: %i\n", runningTotal );
    }
    printf( "Final integer value: %i\n", runningTotal );
    return 0;
}

