#include <stdio.h>
#include <string.h>

int main(){
/* Chapter 10: Introduction to Structures (structs)*************/
/* Structs- let us aggregate variables of different data types to rep
an object like an element.
    Below, element has 4 members. This makes a user-defined data-type,
    called a "struct element". */
struct element{ // structure to rep an atomic element
    char name[10];
    char symbol[5];
    float aWgt[5];
    float mass;
};

// declaring a struct element named e1. It defines an array of 3 
// "struct element" variables.
struct element e1[3];
strcpy(e1[1].name, "hydrogen"); // accessing the name member and setting it to hydrogen.
e1[1].aWgt = 1.0; // accessing aWgt member and setting to 1.0.

/* Can combine declaring a structure and defining a structure variable. */
struct compound{ // structure to rep an atomic element
    char name[10];
    char symbol[5];
    float aWgt[5];
    float mass;
} c1, c[1000]; // defines a c1 variable and c variable (which has an array of 1000 structs).

/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/


/* Chapter 10: H*************/
return 0;
}