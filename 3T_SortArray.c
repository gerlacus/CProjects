#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MARKS:
// a - arraySize in main
// e - elementRange in main
// r - randPopArray
// p - printArray
// n - quickSortNew


void printArray( int * array, int length ) {
    printf( "Array contents: (");
    for ( int i = 0;  i < length;  i++ ) {
        printf( "%i", array[i] );
        if ( i != length-1 ) {
            printf( ", " );
        }

    }
    printf( ")\n" );
}


void randPopArray ( int * array, int size, int maximum ) {
    //printf( "maximum upon randPopArray: %i\n", maximum );
    for ( int i = 0;  i < size;  i++ ) {
        //printf( "Current element: %i\n", i );
        array[i] = ( rand() % maximum ) + 1;
        //printf( "  Randomly assigned value: %i\n", array[i] );
    }
}


void swapPointers( int * x, int * y) {
    // swaps x and y in an array, using temp variable
    int tmp;
    tmp = * x;
    * x = * y;
    * y = tmp;
    //printf( "Swapped %i with %i\n", *x, *y );
}

void quickSort( int inArray[], int lPos, int rPos ) {
    int pivVal, i, j, pivPt;
    if ( lPos < rPos ) {
        // random pivot within range between lPos and rPos
        pivPt = ( rand() % ( rPos - lPos ) ) + lPos;
        swapPointers( &inArray[lPos], &inArray[pivPt] );
        pivVal = inArray[lPos];
        i = lPos + 1;
        j = rPos;
        while ( i <= j ) {
            while ( ( i <= rPos ) && ( inArray[i] <= pivVal ) ) {
                i++;
            }
            while ( ( j >= lPos ) && ( inArray[j] > pivVal ) ) {
                j--;
            }
            if ( i < j ) {
                swapPointers( &inArray[i], &inArray[j] );
            }
        }
        // swap two elements
        swapPointers( &inArray[lPos], &inArray[j] );

        // recursively sort lesser lists
        quickSort( inArray, lPos, j - 1 );
        quickSort( inArray, j + 1, rPos );
    }
}

void bubbleSort( int inArray[], int size ) {
    // process: outer loop passes, inner loop bubbles
    for ( int pass = 0;  pass < size; pass++ ) {
        for ( int i = 1;  i < size - pass;  i++ ) {
            // compare adjacent elements; if not in order, swap
            if ( inArray[i] < inArray[i - 1] ) {
                swapPointers( &inArray[i], &inArray[i - 1] );
            }
        }
    }
}

int max(int x, int y) {
    // simple helper to swap two integers
    if (x >= y) { return x; }
    else { return y; }
}

void siftDown( int inArray[], int current, int heapSize ) {
    // initialized variables: l/rChild = index of left/right child, l/rVal = value at said left/right child's index in array
    int lChild = 0;
    int rChild = 0;
    int lVal = 0;
    int rVal = 0;     // the value at lChild or rChild's indeces
    // check if child is valid according to heapSize
    if ( 2 * current <= heapSize - 1 ) {
        lChild = ( 2 * current ) + 1;
    }
    if ( 2 * current <= heapSize - 2 ) {
        rChild = ( 2 * current ) + 2;
    }
    if ( !lChild  &&  !rChild ) {   // if the current element has no children
        return;
    }
    // if child was valid, grab value and put into lVal or rVal
    if ( lChild ) {
        // grab lChild's value
        lVal = inArray[lChild];
    }
    if ( rChild ) {
        // grab rChild's value
        rVal = inArray[rChild];
    }

    // compare self with children (if at least one child is bigger)
    if ( max( lVal, rVal ) > inArray[current] ) {
        // if lChild has bigger value, swap with left and call again on left
        if ( max( lVal, rVal ) == lVal ) {
            swapPointers( &inArray[current], &inArray[lChild] );
            siftDown( inArray, lChild, heapSize );
        }
        // if rChild has bigger value, swap with right and call again on right
        else if ( max( lVal, rVal ) == rVal ) {
            swapPointers( &inArray[current], &inArray[rChild] );
            siftDown( inArray, rChild, heapSize );
        }
    }
}

void heapify( int inArray[], int heapSize ) {
// turns entire heap into a valid heap via siftDown operations starting from last element and moving to first
    int highestToSift = ( heapSize ) / 2;   // only first half of heap must be sifted; last half has no children
    for ( int i = highestToSift;  i >= 0;  i-- ) {
        siftDown( inArray, i, heapSize );
    }

}

void heapSort( int inArray[], int heapSize ) {
    // general method: initial heapify, swap [1] with [heapSize], then heapSize-- and reheapify with new, smaller size
    heapify( inArray, heapSize );
    for ( int i = heapSize;  i > 0;  i-- ) {
        swapPointers( &inArray[0], &inArray[heapSize] );
        //printf( "%i swapped with %i\n", inArray[0], inArray[heapSize] );
        heapSize--;
        heapify( inArray, heapSize );
    }
}

void mergeArrays( int inArray[], int lP, int mP, int rP ) {
    // create temp array to store sorted elements
    int tempArray[rP - lP + 1];
    int pos = 0;
    int lPos = lP;
    int rPos = mP + 1;
    while ( lPos <= mP && rPos <= rP ) {
        if ( inArray[lPos] < inArray[rPos] ) {
            tempArray[pos++] = inArray[lPos++];
        }
        else {
            tempArray[pos++] = inArray[rPos++];
        }
    }
    while ( lPos <= mP ) {
        tempArray[pos++] = inArray[lPos++];
    }
    while ( rPos <= rP ) {
        tempArray[pos++] = inArray[rPos++];
    }
    // write (sorted) contents of tempArray back into inArray
    for ( int i = 0;  i < pos;  i++ ) {
        inArray[lP + i] = tempArray[i];
    }
    return;
}

void mergeSort( int inArray[], int lPos, int rPos ) {
    int mPos = ( lPos + rPos ) / 2;
    if ( lPos < rPos ) {
        // sort left partition
        mergeSort( inArray, lPos, mPos );
        // sort right partition
        mergeSort( inArray, mPos + 1, rPos);
        // merge two partitions
        mergeArrays( inArray, lPos, mPos, rPos );    
    }
}

int main ( int argc, char * argv[] ) {
    //printf( "Hello world\n" );
    //printf( "Your argument was: %s\n", argv[1] );
    // seed randomizer
    srand( time( NULL ) );
    // initialize variables:
    //      argSize = size of array as given by first CL argument
    //      elementRange = range of each element in array as given by second CL argument
    //      if no arguments, each defaults to random value between 1 and 100
    int argSize = ( rand() % 99 ) + 1;
    int elementRange = ( rand() % 99 ) + 1;

    if ( argc >= 2  &&  atoi ( argv[1] ) > 0 ) {
        argSize = atoi( argv[1] );
        printf( "Array size successfully passed from command line; creating array of size %i.\n", argSize );
        }
    else if ( argc >= 2 ) {
            printf( "Invalid array size passed in. Creating randomly-sized array between 1 and 100 instead (%i).\n", argSize );
            srand( time( NULL ) );
        }
    if ( argc == 1 ) {
        printf( "No array size passed in; creating randomly-sized array between 1 and 100 (%i).\n", argSize );
    }

    if ( argv[2] ) {
        if ( atoi( argv[2] ) > 0 ) {
            elementRange = atoi( argv[2] );
            printf( "Element maximum successfully passed from command line; setting to random between 1 and %i.\n", atoi( argv[2] ) );
        }
        else {
            printf( "Invalid or no element maximum passed in; choosing random number between 1 and 100 instead (%i).\n", elementRange );
        }
    }
    else {
        printf( "Element maximum not specified; choosing random number between 1 and 100 instead (%i).\n", elementRange );
    }
    //int * sizeArray
    //int origArray [10];
    int * origArray = ( int * )malloc( argSize *sizeof( int ) );
    randPopArray( origArray, argSize, elementRange );
    int * bubArray = origArray;
    int * mergeArray = origArray;
    int * quickArray = origArray;
    int * heapArray = origArray;
    
    printf( "\n" );
    printArray( origArray, argSize );
    printf( "\nNow, let's sort this array with a number of different sorting algorithms!\n\n" );

    printf( "After using bubbleSort...\n    " );
    bubbleSort( bubArray, argSize );
    printArray( bubArray, argSize );
    
    printf( "After using mergeSort...\n    " );
    mergeSort( mergeArray, 0, argSize - 1 );
    printArray( mergeArray, argSize );

    printf( "After using quickSort...\n    " );
    quickSort( quickArray, 0, argSize - 1 );
    printArray( quickArray, argSize );

    printf( "After using heapSort...\n    " );
    heapSort( heapArray, argSize - 1);
    printArray( heapArray, argSize );
    //printf( "
    /*
    printf( "Ok, now let's sort this with heapSort...\n" );
    //printf( "Ok, now let's sort this with bubble sort...\n" );
    //bubbleSort( origArray, argSize );
    //quickSort( origArray, 0, argSize - 1);
    //mergeSort( origArray, 0, argSize - 1);
    heapSort( origArray, argSize - 1 );
    printf( "Final results...\n" );
    printArray (origArray, argSize );
    */
}
