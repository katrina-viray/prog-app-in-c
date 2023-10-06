#include <stdio.h> // header file library that lets us work with input and output functions
#include <stdbool.h> // bools are not a built-in data type, so must import it
#include <string.h> // string functions; import this to use them.
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

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */
}