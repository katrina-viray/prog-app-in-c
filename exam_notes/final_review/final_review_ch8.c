/* C Storage Classes are used to describe the 
features of a variable/function. These features
 basically include the scope, visibility, and 
 lifetime which help us to trace the existence of 
 a particular variable during the runtime of a program. */
/* **IMPORTANT: static storage class

Static variables have the property of preserving their 
value even after they are out of their scope 

they are initialized only once and exist till the termination of the program. Thus, no new memory is allocated because they are not re-declared.

Their scope is local to the function to which they were
defined.

Global static variables can be accessed anywhere in the 
program. By default, they are assigned the value 0 by the 
compiler. */

/* auto storage class
This is the default storage class for all the variables 
declared inside a function or a block. Hence, the keyword
auto is rarely used while writing programs in C language.
Auto variables can be only accessed within the block/function
they have been declared and not outside them (which defines
their scope). Of course, these can be accessed within nested 
blocks within the parent block/function in which the auto 
variable was declared.

they can be accessed outside their scope as well
using the concept of pointers given here by pointing
to the very exact memory location where the variables 
reside.*/ 

/* extern storage class
an extern variable is nothing but a global variable 
initialized with a legal value where it is declared
in order to be used elsewhere. It can be accessed within
any function/block.

a normal global variable can be made extern as well by 
placing the ‘extern’ keyword before its declaration/definition
in any function/block. This means we are accessing/using the 
global variable only.

The main purpose of using extern variables is that they 
can be accessed between two different files which are 
part of a large program. */ 

// A C program to demonstrate different storage 
// classes 
#include <stdio.h> 
  
// declaring the variable which is to be made extern 
// an initial value can also be initialized to x 
int x; 
  
void autoStorageClass() 
{ 
  
    printf("\nDemonstrating auto class\n\n"); 
  
    // declaring an auto variable (simply 
    // writing "int a=32;" works as well) 
    auto int a = 32; 
  
    // printing the auto variable 'a' 
    printf("Value of the variable 'a'"
           " declared as auto: %d\n", 
           a); 
  
    printf("--------------------------------"); 
} 

void externStorageClass() 
{ 
  
    printf("\nDemonstrating extern class\n\n"); 
  
    // telling the compiler that the variable 
    // x is an extern variable and has been 
    // defined elsewhere (above the main 
    // function) 
    extern int x; 
  
    // printing the extern variables 'x' 
    printf("Value of the variable 'x'"
           " declared as extern: %d\n", 
           x); 
  
    // value of extern variable x modified 
    x = 2; 
  
    // printing the modified values of 
    // extern variables 'x' 
    printf("Modified value of the variable 'x'"
           " declared as extern: %d\n", 
           x); 
  
    printf("--------------------------------"); 
} 
  
void staticStorageClass() 
{ 
    int i = 0; 
  
    printf("\nDemonstrating static class\n\n"); 
  
    // using a static variable 'y' 
    printf("Declaring 'y' as static inside the loop.\n"
           "But this declaration will occur only"
           " once as 'y' is static.\n"
           "If not, then every time the value of 'y' "
           "will be the declared value 5"
           " as in the case of variable 'p'\n"); 
  
    printf("\nLoop started:\n"); 
  
    for (i = 1; i < 5; i++) { 
  
        // Declaring the static variable 'y' 
        static int y = 5; 
  
        // Declare a non-static variable 'p' 
        int p = 10; 
  
        // Incrementing the value of y and p by 1 
        y++; 
        p++; 
  
        // printing value of y at each iteration 
        printf("\nThe value of 'y', "
               "declared as static, in %d "
               "iteration is %d\n", 
               i, y); 
  
        // printing value of p at each iteration 
        printf("The value of non-static variable 'p', "
               "in %d iteration is %d\n", 
               i, p); 
    } 
  
    printf("\nLoop ended:\n"); 
  
    printf("--------------------------------"); 
} 
  
int main() 
{ 
  
    printf("A program to demonstrate"
           " Storage Classes in C\n\n"); 
  
    // To demonstrate auto Storage Class 
    autoStorageClass(); 
  
    // To demonstrate extern Storage Class 
    externStorageClass(); 
  
    // To demonstrate static Storage Class 
    staticStorageClass(); 
  
    // exiting 
    printf("\n\nStorage Classes demonstrated"); 
  
    return 0; 
} 

/* OUTPUT OF ABOVE:
A program to demonstrate Storage Classes in C


Demonstrating auto class

Value of the variable 'a' declared as auto: 32
--------------------------------
Demonstrating extern class

Value of the variable 'x' declared as extern: 0
Modified value of the variable 'x' declared as extern: 2
--------------------------------
Demonstrating static class

Declaring 'y' as static inside the loop.
But this declaration will occur only once as 'y' is static.
If not, then every time the value of 'y' will be the declared value 5 as in the case of variable 'p'

Loop started:

The value of 'y', declared as static, in 1 iteration is 6
The value of non-static variable 'p', in 1 iteration is 11

The value of 'y', declared as static, in 2 iteration is 7
The value of non-static variable 'p', in 2 iteration is 11

The value of 'y', declared as static, in 3 iteration is 8
The value of non-static variable 'p', in 3 iteration is 11

The value of 'y', declared as static, in 4 iteration is 9
The value of non-static variable 'p', in 4 iteration is 11

Loop ended:
-------------------------------- */

/* Type qualifier: const 
This can be applied to the declaration of any variable 
to specify that its value will not be changed. */
int main()
{
    const int var = 100;
 
    // Compilation error: assignment of read-only variable
    // 'var'
    var = 200;
 
    return 0;
}
/* You can also have a pointer to a constant variable:
We can change the pointer to point to any other integer
variable, but cannot change the value of the object (entity)
pointed using pointer ptr.
NOTE: const int* ptr; OR int const *ptr; BOTH work!!*/
#include <stdio.h>
int main(void)
{
    int i = 10;
    int j = 20;
    /* ptr is pointer to constant */
    const int* ptr = &i;
 
    printf("ptr: %d\n", *ptr);
    /* error: object pointed cannot be modified
    using the pointer ptr */
    *ptr = 100;
 
    ptr = &j; /* valid */
    printf("ptr: %d\n", *ptr);
 
    return 0;
}

/* ANOTHER scenario: int* const ptr;, where we have
a constant pointer to variable. */
// C program to demonstrate that the value of object pointed
// by pointer can be changed but the pointer can not point
// to another variable
 
#include <stdio.h>
 
int main(void)
{
    int i = 10;
    int j = 20;
    /* constant pointer to integer */
    int* const ptr = &i;
 
    printf("ptr: %d\n", *ptr);
 
    *ptr = 100; /* valid */
    printf("ptr: %d\n", *ptr);
 
    ptr = &j; /* error */
    return 0;
}

/* Type qualifier: volatile 
The volatile qualifier is applied to a variable when we 
declare it. It is used to tell the compiler, that the 
value may change at any time.

volatile tells the compiler not to optimize anything that
has to do with the volatile variable.

There are at least three common reasons to use it, all 
involving situations where the value of the variable can 
change without action from the visible code:
When you interface with hardware that changes the value itself
when there's another thread running that also uses the variable
when there's a signal handler that might change the value of the variable.

 The system always reads the current value of a volatile 
 object from the memory location rather than keeping its 
 value in a temporary register at the point it is requested, 
 even if a previous instruction asked for the value from the 
 same object. 
*/
#include <stdio.h>

// Define a volatile variable representing a hardware register
volatile int hardwareRegister;

// Function simulating an interrupt handler that updates the hardware register
void interruptHandler() {
    hardwareRegister = 42;
}

int main() {
    // Initial value of the hardware register
    printf("Initial value of hardware register: %d\n", hardwareRegister);

    // Simulate an interrupt that updates the hardware register
    interruptHandler();

    // Access the hardware register again
    printf("Updated value of hardware register: %d\n", hardwareRegister);

    return 0;
}

