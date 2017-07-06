#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char * argv[]) {
    // seed randomizer based on systime
    srand( time( NULL ) );
    printf( "Your input: %s\n", argv[1] );

    // Check if valid input (positive integer)
    // if no args passed in, make it random (between 1 and 20)
    int triangleSize = ( rand() % 20 ) + 1;
    if ( argc == 1 ) {
        printf( "No argument passed in; randomly generating size (%i)\n", triangleSize );
    }
    else if ( atoi( argv[1] ) > 0 ) {
        triangleSize = atoi( argv[1] );
        printf( "Argument passed in; side length is %i.\n", triangleSize );
    }

    // Print the triangle based on triangleSize
    printf( "Here is your triangle:\n" );
    for ( int i = 1;  i <= triangleSize;  i++ ) {
        for ( int j = 1;  j <= i;  j++ ) {
            printf( "*" );
        }
        printf( "\n" );
    }
}
