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