/* Range of possible integer values for bitfield structures:
   In C, we can specify the size (in bits) of the structure and 
   union members.  The idea of bit-field is to use memory efficiently
   when we know that the value of a field or group of fields will
   never exceed a limit or is within a small range.*/
// e.g. 0<=i2<=15 is the range.
/* *** Range should be 2^# bits, so i2 is 4 bits, 2^4 = 16. 
    Therefore, the range is 0 to 15 for i2.  */
struct mystruct{
    /* data_type can be an int, signed int, or unsigned int. 
       member_name is the name of the bit-field
       width_.. is the # of bits in the bit-field. */
    int  i1:3; // data_type member_name : width_of_bit-field;
    unsigned int i2:4; // unsigned int with only 4 bits
};

// C program to demonstrate use of Bit-fields
#include <stdio.h>
 
// Space optimized representation of the date
struct date { // day, month, year struct!
    // d has value between 0 and 31, so 5 bits
    // are sufficient. *** Range is 0 to 31!
    int d : 5;
 
    // m has value between 0 and 15, so 4 bits
    // are sufficient
    int m : 4;
 
    int y;
};
 
int main()
{
    printf("Size of date is %lu bytes\n",
           sizeof(struct date));
    struct date dt = { 31, 12, 2014 };
    printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
    return 0;
}




/* structure variables wherein one of the fields is 
another structure variable (as in the book). */
#include <stdio.h>
#include <string.h>

// Define the inner structure
struct Address {
    char street[50];
    char city[30];
    char state[20];
    char zip[10];
};

// Define the outer structure with a field that is another structure
struct Person {
    char name[50];
    int age;
    struct Address address; // Embedded structure
};

int main() {
    // Declare and initialize the structure variable in one statement
    struct Person person1 = {
        .name = "John Doe",
        .age = 25,
        .address = {
            .street = "123 Main Street",
            .city = "Anytown",
            .state = "CA",
            .zip = "12345"
        }
    };

    // Display the information
    printf("Person Information:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address:\n");
    printf("  Street: %s\n", person1.address.street);
    printf("  City: %s\n", person1.address.city);
    printf("  State: %s\n", person1.address.state);
    printf("  ZIP: %s\n", person1.address.zip);

    return 0;
}




/* How structure variable are stored in memory 
(can be un-used memory addresses between two fields) 

The memory layout of a struct variable is determined by
each individual data type of its members. The goal of padding is to 
align members at memory addresses that are multiples of their size,
which can improve memory access performance.

OUTPUT IS: 
Size of ExampleStruct: 16
Address of a: 0x7fffbdbd6370
Address of b: 0x7fffbdbd6374
Address of c: 0x7fffbdbd6380

The size of ExampleStruct is 16 bytes, which is the sum of the sizes
    of its members (1 + 4 + 8).
The address of a is 0x7fffbdbd6370.
The address of b is 0x7fffbdbd6374, 
    indicating a padding of 3 bytes (4 bytes for int minus 1 
    byte for char).
The address of c is 0x7fffbdbd6380, indicating a padding of 4 
    bytes (8 bytes for double minus 4 bytes for int).
*/
#include <stdio.h>

struct ExampleStruct {
    char a;    // 1 byte
    int b;     // 4 bytes (on a typical system)
    double c;  // 8 bytes (on a typical system)
};

int main() {
    struct ExampleStruct exampleVar;

    // Display the sizes and addresses of the members
    printf("Size of ExampleStruct: %zu\n", sizeof(struct ExampleStruct));
    printf("Address of a: %p\n", (void*)&exampleVar.a);
    printf("Address of b: %p\n", (void*)&exampleVar.b);
    printf("Address of c: %p\n", (void*)&exampleVar.c);

    return 0;
}




/* Pointer syntax with a pointer to a structure variable. */
#include <stdio.h>
#include <string.h>

// Define a simple structure
struct Student {
    char name[50];
    int age;
    double gpa;
};

int main() {
    // Declare a structure variable and initialize it
    struct Student student1;
    strcpy(student1.name, "John Doe");
    student1.age = 20;
    student1.gpa = 3.75;

    // Declare a pointer to a structure of type Student
    struct Student *ptrStudent;

    // Assign the address of student1 to the pointer
    ptrStudent = &student1;

    // Accessing structure members using the pointer
    /* We access the structure members using the pointer with the 
    -> (arrow) operator. Note that the -> operator is a shorthand 
    for dereferencing the pointer and accessing the structure members.
     It is equivalent to the more explicit (*ptrStudent).member.*/
    printf("Student Information:\n");
    printf("Name: %s\n", ptrStudent->name); // Equivalent to (*ptrStudent).name
    printf("Age: %d\n", ptrStudent->age);   // Equivalent to (*ptrStudent).age
    printf("GPA: %.2f\n", ptrStudent->gpa); // Equivalent to (*ptrStudent).gpa

    return 0;
}




/* Enumerated types. 
The variables are actually 4-byte variables. (b/c they're ints!)

Know how the keywords in the declaration of
an enumerated variable are assigned int values.

Enumeration (or enum) is a user defined data type in C.
It is mainly used to assign names to integral constants, 
the names make a program easy to read and maintain. */

// An example program to demonstrate working
// of enum in C, IT OUTPUTS 2!
#include<stdio.h>
 
enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};
 
int main()
{
    enum week day;
    day = Wed;
    printf("%d",day);
    return 0;
} 


/* In a question on the final, I might provide a
 structure variable that is the complete WAVE file header,
  and ask you to use the provided structure variable and 
  complete the program to do something with the WAVE file.*/
  #include <stdio.h>
#include <stdint.h>

// Define the WAVE file header structure
struct WaveHeader {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
};

int main() {
    // Assume you have a WAVE file header structure variable
    struct WaveHeader waveHeader = {
        {'R', 'I', 'F', 'F'},
        36,
        {'W', 'A', 'V', 'E'},
        {'f', 'm', 't', ' '},
        16,
        1,
        1,
        44100,
        44100 * 2 * sizeof(short),
        2 * sizeof(short),
        16,
        {'d', 'a', 't', 'a'},
        88200
    };

    // Print some information about the WAVE file
    printf("WAVE file information:\n");
    printf("Sample Rate: %u Hz\n", waveHeader.sampleRate);
    printf("Number of Channels: %u\n", waveHeader.numChannels);
    printf("Bits per Sample: %u\n", waveHeader.bitsPerSample);
    printf("Duration: %.2f seconds\n", (float)waveHeader.subchunk2Size / (waveHeader.sampleRate * waveHeader.numChannels * waveHeader.bitsPerSample / 8.0));

    // Add your further processing or actions with the WAVE file here

    return 0;
}

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

return 0;
}