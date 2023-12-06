/* Chapter 7******************************************************************* */
/* Pointer variables. */
// Example Program:

/* Write a program segment to use a float pointer to print the value in a float variable to the display.✅ */
float x=3.1,*px;
px=&x;
printf(“%f”, *px); // prints 3.1 to the display

/* Using pointers as arguments to subroutine. */
 // Example Program:
// Function to swap the values of two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 5, num2 = 10;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Call the swap function with the addresses of num1 and num2
    swap(&num1, &num2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

/* Pointers and arrays */
 // Example Program:
 #include <stdio.h>

int main() {
    // Declare an array of integers
    int numbers[] = {1, 2, 3, 4, 5};

    // Declare a pointer to an integer
    int *ptr;

    // Point the pointer to the beginning of the array
    ptr = numbers;

    // Access array elements using pointer notation
    printf("Array elements using pointer notation:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    // Modify array elements using pointer notation
    for (int i = 0; i < 5; ++i) {
        *(ptr + i) *= 2; // Double the value of each element
    }

    // Print the modified array using array notation
    printf("\nArray elements after modification:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Element %d: %d\n", i, numbers[i]);
    }

    return 0;
}

/* Dereferencing */
 // Example Program:
#include <stdio.h>

int main() {
    // Declare a variable and a pointer
    int number = 42;
    int *ptr;

    // Point the pointer to the address of the variable
    ptr = &number;

    // Print the value of the variable and the dereferenced pointer
    printf("Value of the variable: %d\n", number);
    printf("Value using pointer dereferencing: %d\n", *ptr);

    // Modify the value through dereferencing
    *ptr = 99;

    // Print the modified value of the variable
    printf("Modified value of the variable: %d\n", number);

    return 0;
}

/*Levels of indirection (pointers to pointers, etc) */
#include <stdio.h>
int main(){
    int ix = 2, y;
    /* (1 level ) of pointers are needed to have runtime allocation of 1D 
    arrays of arbitrary size. */
    int *p, *p1; // pointers to int variables

    /* **pointers (2 levels) are used for 2D arrays declared
    at runtime */
    int ** p2pi; // pointer to pointer to int

    /* *** pointers are for 3D arrays at runtime */
    int *** p2p2pi; // pointer to pointer to pointer to int.

    ix = 5; // changing ix from 2 to 5 (idk why lol)
    p = &ix; // pointer p points to ix
    p1 = &y; // pointer p1 points to y
    
    /* Printing pointers: prints the memory address held by the
    pointer in hexadecimal format. Output may look something 
    like: 0x7ffd5f3489ac. The actual memory address varies each
    time you run the program due the dynamic nature of memory allocation.*/
    printf("%p", p); // printing the memory address of the pointer
    printf("%p", &ix);
    p2pi = &p;
    p1 = &p; // INCORRECT!! assigning pointer to int value
    p2p2pi = &p2pi; // valid!
    p2p2pi = &p; //INVALID
    printf("%d%d%d\n", ix, *p, **p2pi); // all print 5. (ix's value)
}

/* Understand the examples in the book regarding memory 
addresses and pntr-pntr-… */
/* ***Look over my ch.7 notes for this! */

/* Know how to use both pointer_syntax
 and array_syntax for accessing cells of a 2-d array. */
 #include <stdio.h>

int main() {
    // Declare and initialize a 2D array
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Using array syntax to access elements
    printf("Using array syntax:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Using pointer syntax to access elements
    /* How it works:  
    matrix is a pointer to the first row of the 2D array.
     The expression matrix + i gives the address of the 
     ith row.

    *(matrix + i) dereferences the pointer obtained in 
    step 1, resulting in a pointer to the first element of
     the ith row.

    *(matrix + i) + j gives the address of the jth 
    element in the ith row. Here, we're essentially 
    navigating within the ith row.

    *(*(matrix + i) + j) dereferences the pointer 
    obtained in step 3, giving the value stored at the 
    jth element in the ith row*/
    printf("\nUsing pointer syntax:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    return 0;
}
