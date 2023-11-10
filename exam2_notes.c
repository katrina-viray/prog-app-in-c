// https://www.w3schools.com/c/c_structs.php
#include <stdio.h>
#include <stdlib.h>
int main(){

/* Topics to look over******************************************************************* */
/*
1. Get really familiar with pointers.
*/

/* W3 School NOTES******************************************************************* */
/* C Structures (structs)*************/
/* Structs- way to grpup several related variables in one place.
    Each variable in the struct is known as a "member" of the structure.
    These can contain diff data types.*/
struct MyStructure{ // declares a structure
    int myNum; // member 1 (int var)
    char myLetter; // member 2 (char var)
    char myString[30];
}; // remember to end structs with a semicolon!

// now in main:
struct MyStructure s1;
s1.myNum = 13; // access members with the dot "." syntax
s1.myLetter = 'a';
printf("My number: %d", s1.myNum);

// since strings can't be assigned like this:
s1.myString = "some text";
// we can work around this by using strcpy():
strcpy(s1.myString, "some text");

// can also assign variables when declaring the struct:
struct MyStructure s2 = {13, 'a', "some text"};

// can also assign one structure to another
struct MyStructure s3;
s3 = s1;

/* C Enumeration (enum)*************/
/* Enums- special type which reps a group of constants, AKA unchangeable values.*/
enum Level{ // good practice is for the enum items to be uppercase
    LOW, // 0
    MEDIUM, // 1
    HIGH = 75, // can change the values that each item holds.
    EXTRA_HIGH // next items are updated accordingly, so now 76
};

// in main, to declare an enum variable:
enum Level myVar = MEDIUM; // assigned values must be one of the items in the enum
printf("%d", myVar); // outputs 1 since by default, items have values of 0, 1, 2, etc.


/* TEXTBOOK NOTES******************************************************************* */

/* Chapter 7: Pointers*************/
/* Section 7.1: Pointer Variables***/
// Review: In C, pointers hold the address to certain data types, like char* is a char pointer type.
int x = 0;

// while int* pt works too, use the one below since you can do int *pt1, *pt2, etc.
// you cannot do this with int* pt (it would not work as intended).
int *pt = &x; // int pointer holds the address of x, or points to x. 
*pt = 3; // assigns value of 3 into x; dereference

/* Section 7.2: Levels of Indirection***/
// Levels of indirection- number of * attached to a variable to reference a value to which it points
// Here, the cell named pt contains an andress of a cell which contains an address of a cell which contains an int. 
int **pt; // pt is a pointer to a pointer to an int. 

/* Section 7.3: Pointers and Arrays***/
// Review: An array's name is a constant whose value is the address of the array's first element. 
// Therefore, these statements both assign ptr the address of the first element of an array:
float on_time[100];
float* ptr;
ptr = on_time;
ptr = &on_time[0];

// Here, the value of s2 cannot be changed since s2 is a pointer constant (to the first element in s2). 
char s2[] = "blah blah";

//Arrays and Pointer Artihmetic: 
// Review: Can traverse arrays and access cells in a array through pointers, called pointer syntax.
char letters[5];
char *ptr = letters; // ptr points to address of letters[0]
int count;

// read in five characters into letters:
for(count = 0; count < 5; count++){
    *ptr = getchar(); // gets a character from the user
    ++ptr;

    //NOTE: these lines above can be combined to be: 
    *ptr++ = getchar(); // * and increment operators have the same precedence
}

// printing characters from letters in reverse order
for(count = 0; count < 5; count++){
    --ptr;
    putchar(*ptr); // outputs a char to output
}

// Pointer Operations:
// Can also do ptr + 2, ptr - 2, ptr2 - ptr1, ptr1 >= ptr2
// You CANNOT add two pointers, multiply 2 pointers, or divide one by another. 

/* ptr2 - ptr1 is the cap btwn the cells pointed to by ptr1 and ptr2.
if ptr2 and ptr1 point to the same cell, then it becomes zero. 
if ptr2 - ptr1 is positive, then ptr1 points to a cell beyond the cell pointed to by ptr2
if ptr2 - ptr1 is negative, then ptr1 points to a cell before the cell pointed to by ptr1.
*/

// These two statements both access the 13th element/cell in an array
// publisher[12]
// *(publisher + 12)

/* Section 7.4: Pointers as Arguments to Functions***/
// C does not support call by reference, where functions can receive a reference instead
// copies of the arguments sent to it. C uses call by value exclusively, AKA where functions
// work on copies of the argument sent to it instead of the OG argument itself. 

/* By using pointer arguments, we can simulate call by reference. */
int x = 999;
f(&x); // simulates calling by reference

void f(int *p){
    *p += 2; // DOES change the value of x!
    // return ++*p would return 999 + 1 = 1000. It derefs first and then ++ adds 1. 
}

// both headers for f would work due to arrays pointing to the first element :)
int s[10];
f(s);
void f(int a[]); 
void f(int *a);

/* Chapter 7: Pointers*************/


/* Chapter 7: Pointers*************/


/* Chapter 7: Pointers*************/


/* Chapter 7: Pointers*************/


/* Chapter 7: Pointers*************/





/* Program homework notes******************************************************************* */
/* Audio Files********************************************/
/*
WAV format- must be stored in file extensions of *.wav. 
- WAV format is a subset of Microsoft's RIFF specification for storing 
multimedia files.
- RIFF files- starts with a file header followed by a sequence of data chunks.
- WAV files are RIFF files with 3 chunks:
    1. indicates the file is a RIFF WAV file.
    2. Header of a "fmt" chunk; specifies the data format, like stereo. 
    3. "Data" chunk containing the actual sample data stored in the format
    specified in the "fmt" chunk.

    Ex. A WAV PCM file is stored in an uncompressed format; PCM means
    pulse-code-modulation; in this case it means uncompressed mode.
*/

/* Written homework notes******************************************************************* */
// Section 7.3*******************************************
/*
Pointers:
Ex. 
int numbs[2];
int* ptr = numbs;
numbs[0] = 10;
printf("%d\n", ++*ptr); --> outputs 11


Functions: 
*/

// Section 9.1*******************************************
/*
Diff btwn mode r and r+, w and w+, r+b (read-write-binary)

Functions: 
stdin-

gets- reads characters from the standard input until it encounters a newline
fputs- writes a character string to the file referenced by its second argument
*/
 return 0;
}