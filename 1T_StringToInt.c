#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, char *argv[] ) {

    // Seed randomizer
    srand( time( NULL ) );

    // Should be 1 argument (string of ints)
    if (argc != 2) {
        printf( "usage: %s string_of_ints\n", argv[0] );
        exit(0);
    }

    // Methodology: essentially loop through each char in argument string (e.g. "789")
    // '7' - '0' = actual ASCII int value, which in this case is 7
    // Then, add that to previous int (but previous int * 10 because new decimal place)
    char * inputStr = argv[1];
    unsigned int runningTotal = 0;

    printf( "Input string: %s\n", inputStr );
    printf( "converting to integer...\n");

    for ( int i = 0;  i < strlen( inputStr );  i++) {
        // Check to see if character is within range of acceptable ASCII values (numbers)
        if ( inputStr[i] < 48 || inputStr[i] > 57 ) {
            printf( "Input must be a string of positive integers.\n" );
            exit( 0 );
        }
        runningTotal *= 10;
        runningTotal += ( inputStr[i] - '0' );
    }

    // For use in random integer operations
    int randMult = ( rand() % (runningTotal) ) + 1;
    int randAdd = ( rand() % runningTotal ) + 1;
    int randSubt = ( rand() % runningTotal ) + 1;
    int randDiv = ( rand() % runningTotal ) + 1;

    printf( "Final integer value: %i\n", runningTotal );
    printf( "Now, just to prove that it's an integer...\n" );
    printf( "%i * %i = %i\n", runningTotal, randMult, runningTotal * randMult );
    printf( "%i + %i = %i\n", runningTotal, randAdd, runningTotal + randAdd);
    printf( "%i - %i = %i\n", runningTotal, randSubt, runningTotal - randSubt );
    printf( "%i / %i = %i\n", runningTotal, randDiv, runningTotal / randDiv );
    return 0;
}

