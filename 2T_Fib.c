#include <stdio.h>
#include <stdlib.h>


// actual fib function: takes in int fibEnd, spits out fibEnd'th Fibonacci number
unsigned long long int fib( int fibEnd ) {
    // base cases: fibEnd == 0 or 1
    if ( fibEnd == 0 ) {
        return( 0 );
    }
    else if ( fibEnd == 1 ) {
        return ( 1 );
    }
    else {
        // general algorithm: keep track of 3 variables:
        // cur: current running total (i.e. n)
        // imm: immediately trailing value (i.e. n-1)
        // dis: distant trailing value (i.e. n - 2)
        // cur = imm + dis, dis = imm, imm = cur
        // lather, rinse, repeat until n = fibEnd
        unsigned long long int cur = 1;
        unsigned long long int imm = 1;
        unsigned long long int dis = 0;
        for ( int i = 2;  i <= fibEnd;  i++ ) {
            cur = imm + dis;
            dis = imm;
            imm = cur;
        }
        return ( cur );
    }
}



int main( int argc, char * argv[] ) {
    if ( argc != 2 ) {
        printf( "Usage: %s unsigned_int\n", argv[0] );
        exit( 0 );
    }
    int fibEnd = atoi(argv[1]);
    // printf( "%i\n", fibEnd );
    // make sure fibEnd is in valid range ( > 0)
    if ( fibEnd < 0 ){
        printf( "Argument must be a positive integer.\n" );
        exit( 0 );
    }
    printf( "Fibonacci sequence for n = %i: %llu\n", fibEnd, fib( fibEnd ) );
    

}
