#include <stdio.h> // header file library that lets us work with input and output functions
#include <stdbool.h> // bools are not a built-in data type, so must import it
#include <string.h> // string functions; import this to use them.
#include <math.h> //  list of math functions available, that allows you to perform mathematical tasks on numbers.


int main(){

/* Print Statements******************************************************************* */
/* Printing strings normally does NOT create a newline automatically. You have to use '\n' manually */
printf("Hello!\n");

/* In order to print variables in C, you have to use format specifiers.
    These let the compiler know what type of data the variable is storing.  */
int x = 90;
char str[] = "kat";
printf("%d", x); // 90, integer number
printf("%i", x); // 90, integer number as well (just another way to rep ints)
printf("%c", x); // z, char, ASCII representation of z.
printf("%f", x); // 90.000000, float (decimals)
printf("%e", x); // ?, exponent? 
printf("%lf", x); // 90.000000, double (decimals)
printf("%s", str); // kat, string

// can specify how many decimal digits to print
printf("%.2f", x); // prints 2 decimal digits

/* Getting input from the user******************************************************************* */
/* use scanf() to get user input 
   Two arguments: format specifier and reference operator (&)
   which stores the memoery address of the variable. */
int myNum;
// Get and save the number the user types
scanf("%d", &myNum);

/* You can get multiple inputs too with scanf() */
// Create an int and a char variable
int myNum;
char myChar;
// Get and save the number AND character the user types
scanf("%d %c", &myNum, &myChar);

/* Strings- no need for & and make sure we use a big enough size num to store */
// Create a string
char firstName[30];
// Get and save the text
scanf("%s", firstName);

/* NOTE**: scanf() considers space (whitespace, tabs, etc) as 
a terminating character, which means that it can only
 display a single word. 
 With strings, this is why we usually use fgets() to read
 a line of text; you MUST use 3 arguments:
 the name of the string variable, sizeof(string_name), and stdin */
char fullName[30];
printf("Type your full name: \n");
fgets(fullName, sizeof(fullName), stdin);

/* scanf(): when scanf is used with the %c conversion specifier, 
only 1 character is read and stored in the first cell of the array.
When %s conversion specifier is used, the entire string is read. (for the example below) */
char stooge3[6] = "Larry";
scanf("%c", &stooge3[0]);
scanf("%s", &stooge3[0]);


/* Variables******************************************************************* */
// char (1 byte), float (4 bytes, 6-7 decimal digits), int (2 or 4 bytes), double (8 bytes, 15 decimal digits)
/* char- can be used to store strings. Don't use [] if you want to store 1 character */
char name[] = "kat"; // [] tells C we want to store lots of chars in the variable.

/* Declaring Multiple Variables */
int x = 2, z = 4, y = 4; // NOT int x, y, z = 1, 2, 3

int x, y, z;
x = y = z = 50; // can assign the same value to multiple vars of the same type

/* Type Conversion******************************************************************* */
/* Two Types: Implicit Conversion (automatically) and Explicit Conversion (manually) */

// Implicit Conversion- Done automatically by the compiler
float myFloat = 9;
printf("%f", myFloat); // outputs 9.000000

int myInt = 9.99;
printf("%d", myInt); // outputs 9 --> rounds down!

// Explicit Conversion- Manually by placing parentheses () in front of the value
float sum = (float) 5 / 2;
printf("%f", sum); // NOW will output 2.500000 instead of just 2. 

/* Constants******************************************************************* */
/* To avoid others/yourself changing existing variable values, use the const keyword
   This makes the variables unchangeable and read-only. 
   Best practice is to declare them with uppercase */
   
const int MINPERHOUR = 60;
const int PI;
// PI = 3.14; // this is not allowed, when declaring const vars, it must be assigned a value already

/* Operators******************************************************************* */
/* These are used to perform operations on variables and values.
   There are 5 operator groups: Arithmetic, Assignment, Comparison, Logical, and Bitwise */

// Arithmetic- performs common math operations
/* Includes addition (+), subtraction (-), mult (*), division (/), 
   modulus (%), increment (++), and decrement (--) */

// Assignment- assigns values to vars
/* All the other operators can be used with this, like >>=, |=, etc! */
int x = 10; // = is an assignment operator
x += 10; // += is an addition assignment operator

// Comparison- compares 2 values/variables. 
/* The return value of a comparison is either 1 or 0, true or false
   Includes ==, >, !=, etc. */

// Logical- &&, ||, !

// sizeof() operator- outputs memory size in bytes of a variable/data type

// Bitwise

/* Booleans******************************************************************* */
bool isChecked = true; // notice syntax; returned as integers.
printf("%d", isChecked); // must use %d to print out booleans 

/* Short Hand If...Else (Ternary Operator)******************************************************************* */
/* The ternary operator consists of three operands; 
it can replace multiple lines of code w/a single line */
// variable = (condition) ? expressionTrue : experessionFalse;
int time = 20;
(time > 18) ? printf("greater than 18") : prints("less than 18");

/* Switch Statements******************************************************************* */
int day = 4;

switch (day) {
  case 6:
    printf("Today is Saturday");
    break;
  case 7:
    printf("Today is Sunday");
    break;
  default:
    printf("Looking forward to the Weekend");
}

// Outputs "Looking forward to the Weekend"

/* Loops******************************************************************* */
// just remember there are do while loops, while loops, and for loops. :)

/* Strings******************************************************************* */
/* C doesn't have a string type, so you must use a char array to make strings in C */
char greetings[] = "Hello world!"; // note that you have to use double quotes.
printf("%c", greetings[0]); // use %c to print a single char of the string, %s for the whole str

/* To modify strings, you can index the string and USE SINGLE QUOTES */
greetings[0] = 'J'; // now greetings = "Jello world!"

/* Another way to make strings is w/a set of chars.
   NOTE- YOU HAVE to include the null terminator w/this method to tell C 
   to end the string.  */
char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
printf("%s", greetings);


/* Given a character array, you can make sentences from manually filling the array. 
Let's say we define this array in main(): */
char sentence [201]; // can fill 200 characters + 1 for '\0' for string termination

/* #include <string.h> functions*/
// strlen()- returns the length of the string as an integer. DOES NOT count the NULL terminator, '\0'
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
printf("%d", strlen(alphabet)); // outputs 26

//sizeof()- same length but includes '\0' when counting,
printf("%d", sizeof(alphabet));   // 27

/* Concatenate Strings- to concatenate 2 strings, use strcat() */
char str1[20] = "Hello ";
char str2[] = "World!";
// Concatenate str2 to str1 (result is stored in str1)
strcat(str1, str2); // str1 = Hello World!

/* Copy Strings- copy the value of one string to another, use strcpy() */
char str1[20] = "Hello World!";
char str2[20];
// Copy str1 to str2
strcpy(str2, str1); // now str2 = "Hello World!";

/* Compare Strings- compare two strings, you can use the strcmp() function. */
// returns 0 if the two strings are equal, otherwise a value that is not 0:
/*if Return value < 0 then it indicates str1 is less than str2.
  if Return value > 0 then it indicates str2 is less than str1.
*/
char str1[] = "Hello";
char str3[] = "Hi";
// Compare str1 and str3, and print the result
printf("%d\n", strcmp(str1, str3));  // Returns -4 (the strings are not equal)** why -4?

/* Everytime you pass the 1-D array into a subroutine, it receives the memory address of the 0th cell
of the 1-D array in the main() function */
// read in sentence into character array until '\n' is reached.
void sentence(char s[201]){
    char ch;
    int i = 0;
    
    printf("Enter a sentence (up to 200 characters):\n");
    
    while ((ch = getchar()) != '\n' && i < 200) {
        s[i++] = ch;
    }
    
    // string termination
    s[i] = '\0';
}

// print sentence in reverse order. 
void reverse(char s[201]){
    int l = strlen(s);
    
    for(int i = l - 1; i >= 0; i--){
        if((s[i] != ' ') && (s[i] != '\t')){
            putchar(s[i]);
        }
    }
}

while((ch = getchar()) != '\n' && i < 200){
sentence[i++] = ch;
}
sentence[i] = '\0';

// to get the length of a sentence, use the strlen function
int length = strlen(sentence);

// to print, use the putchar() function
/* The putchar(int char) method in C is used to write a character,
 of unsigned char type, to stdout. This character is passed as the parameter to this method.*/

/* ASCII Representation******************************************************************* */
/* Each character is represented by a number in decimal form.
 For instance, c in decimal form is represented as 99 according to the ASCII table.
 If you want to change the values of a character, you can simply add integers to the character itself:  */
char ch = 'c';
ch += 1;
printf("%c", ch); // outputs d

if(ch == 100)
    printf("%d", ch); // outputs 100, the ASCII rep of d.

/* Arrays******************************************************************* */
// passing in arrays to "subroutines"/functions, etc. 
// how character arrays work
// converting a 2D array to a 1D array.

// follow the syntax like below to initialize an array: use {} to insert values
int myNums[] = {1, 2, 3, 4};

// setting array size: you have to know the size beforehand and cannot 
// change the size of the array after creation. 

/* Math Library******************************************************************* */
// rand, pow, fab, etc
printf("%f", sqrt(16)); // 4, square root

/* The ceil() function rounds a number upwards to its 
nearest integer, and the floor() method rounds a number 
downwards to its nearest integer, and returns the result: */
printf("%f", ceil(1.4));
printf("%f", floor(1.4));

//The pow() function returns the value of x to the power of y (x^y):
printf("%f", pow(4, 3)); // 64, 4*4*4

/* Memory Address******************************************************************* */
/* When we make a variable in C, it is assigned a memory address, 
   which is the location where the var is stored on the CPU. 
   To access it, we use the reference operator, &, to rep where it's stored */
int myAge = 43;
// here, &myAge is a pointer, which stores the memory address of the var
// as its value. To print pointers, use %p. 
printf("%p", &myAge); // Outputs 0x7ffe5367e044

/* Pointers******************************************************************* */
/* A pointer variable points to a data type (like int) of the same type, 
   and is created with the * operator. */
int myAge = 43;     // An int variable
int* ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge
// Output the memory address of myAge with the pointer (0x7ffe5367e044)
printf("%p\n", ptr);

/* Dereferencing- gets the value of the var a pointer points to with * */
// Dereference: Output the value of myAge with the pointer (43)
printf("%d\n", *ptr); // prints 43

/* 2 ways to declare pointer variables in C:  */
int* myNum;
int *myNum;

/* C Pointers and Arrays******************************************************************* */
/* In C, the name of an array is actually a pointer to the first element of the array */
int myNumbers[4] = {25, 50, 75, 100};
// Get the memory address of the myNumbers array
printf("%p\n", myNumbers); // note how u don't need to use & to print pointer (since it IS a pointer)
// Get the memory address of the first array element
printf("%p\n", &myNumbers[0]); // BOTH print 0x7ffe70f9d8f0 and 0x7ffe70f9d8f0

/* Since myNumbers is a pointer to the 1st element in myNumbers, 
   use * to access it. */
// Get the value of the first element in myNumbers
printf("%d", *myNumbers); // prints 25. 

/* To access the rest of the elements in myNumbers, increment it!: */
// Get the value of the second element in myNumbers
printf("%d\n", *(myNumbers + 1)); // + 2 for the third element, etc. 

// loop example!
int myNumbers[4] = {25, 50, 75, 100};
int *ptr = myNumbers;
int i;

for (i = 0; i < 4; i++) {
  printf("%d\n", *(ptr + i));
}

/* changing values of array elements with pointers */
int myNumbers[4] = {25, 50, 75, 100};
// Change the value of the second element to 17
*(myNumbers +1) = 17;
// Get the value of the second element
printf("%d\n", *(myNumbers + 1)); // outputs 17

/* Functions******************************************************************* */
// the full declaration of the array is 
// needed in the function parameter (int myNumbers[5]).
void myFunction(int myNumbers[5]) {
  for (int i = 0; i < 5; i++) {
    printf("%d\n", myNumbers[i]);
  }
}

int main() {
  int myNumbers[5] = {10, 20, 30, 40, 50};
  myFunction(myNumbers);
  return 0;
}

/* Function declarations******************************************************************* */
/* For code optimization, it is recommended to separate the declaration and the definition of the function.

You will often see C programs that have function declaration
 above main(), and function definition below main(). This
  will make the code better organized and easier to read: */
// Function declaration
// Function declaration
int myFunction(int, int);

// The main method
int main() {
  int result = myFunction(5, 3); // call the function
  printf("Result is = %d", result);
  return 0;
}

// Function definition
int myFunction(int x, int y) {
  return x + y;
}

/* File Handling******************************************************************* */
/* In C, you can open/read/write files by declaring a pointer
   of type FILE with the fopen() function. */
FILE *fptr // name of this file pointer is fptr
//fptr = fopen(filename, mode); // 2 params to open the file: filename and mode

/* 3 modes: 'w', 'r', 'a'
   w- write
   r- read
   a- append */

// Write- writes to a file; if the file doesn't exist, it'll make one for u 
/* To insert content to it, you can use the fprintf() function  */
// Open a file in writing mode
fptr = fopen("filename.txt", "w");
// Write some text to the file
fprintf(fptr, "Some text");

// Append- add content to a file without deleting the old content
// a mode appends content at the end of the file:
// Open a file in append mode
fptr = fopen("filename.txt", "a");
// Append some text to the file
fprintf(fptr, "\nHi everybody!");

// Read- 1. make a string which is big enough to store the contents
// of the file. 
// Open a file in read mode
fptr = fopen("filename.txt", "r");
// Store the content of the file
char myString[100];
// use fgets() to read the contents of filename.txt
/*
The first parameter specifies where to store the file content, 
which will be in the myString array we just created.

The second parameter specifies the maximum size of data 
to read, which should match the size of myString (100).

The third parameter requires a file pointer that is used
 to read the file (fptr in our example).
*/
// Read the content and store it inside myString
fgets(myString, 100, fptr);

// Print the file content
printf("%s", myString);

/* NOTE**: the fgets function only reads the first line of the file.  */
// To read every line of the file, you can use a while loop:
// Read the content and print it
while(fgets(myString, 100, fptr)) {
  printf("%s", myString);
}

/* If you try to open a file for reading that does not exist,
 the fopen() function will return NULL.
 e can use an if statement to test for NULL, and print
  some text instead (when the file does not exist): */

fclose(fptr); // make sure to close the file to ensure :
/* Changes are saved properly
Other programs can use the file (if you want)
Clean up unnecessary memory space */

// TOPICS I NEED TO LOOK OVER: 
/* Bitwise operators******************************************************************* */
// &, |, ^, ~, <<, >>

/* Other types of ints******************************************************************* */
// Unsigned int- reps non-negative numbers that can't have a sign (positive or zero).
/* These are usually 2/4 bytes, but depends. 
   Range can be 0 to #, depending on the bits. 
   Overflow- w/arithmetic operations, if the result exceeds the max value,
   the result will wrap around to zero */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */
}