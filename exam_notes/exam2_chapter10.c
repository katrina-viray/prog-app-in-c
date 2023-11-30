#include <stdio.h>
#include <string.h>

int main(){
/* Chapter 10.1: Introduction to Structures (structs)*************/
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

/* NOTE: beware of block scope! If in int main() we declare a struct and then in a sep function
    outside of main we try to make a struct variable, it'll be an error due to block scope.
    Instead declare the struct outside of the int main scope so it can have file scope.*/


/* Chapter 10.3: The typedef Construct*************/
/* typedef- lets the programmer make a synonyms for either a built-in or user-defined 
    data type. */
typedef int AGE; // makes AGE a synonym for int
AGE age_mary; // defines an "int" variable named age_mary

/* typedef and struct elements */
// making a typedef for the data type struct element.
typedef struct element{ // structure to rep an atomic element
    char name[10];
    char symbol[5];
    float aWgt[5];
    float mass;
} Element; // now we can use Element instead of struct element
Element e1, e2, e[1000]; // define variables of type struct element

/* Chapter 10.4: Operations on Structures*************/
/* Continuing the example above, we can initialize the members like so (even in an array). 
    If we initialize fewer values than members, then all remaining members are designed 
    default values of zero. */
Element e[3] = { // initialization example
    {"name", "AU", 3.14, 133}, 
    {"name", "AU", 3.14, 133}, 
    {"name", "AU", 3.14, 133}
};

/* To assign values from all of one structure variable's members to another: */
typedef struct car{
    char* make; 
    char* model;
    int year;
    float price;
} AUTO;

AUTO auto1, auto2;
auto1.make = "Ford"; // and so on for the other members
auto1 = auto2 // assign values in one go instead of manually for each one!


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