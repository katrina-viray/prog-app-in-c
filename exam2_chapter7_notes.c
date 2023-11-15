int main(){

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

/* Chapter 7.6: Pointers and Multidimensional Arrays*************/
/* 2D arrays are 1D arrays where each member is a 1D array. If you wanted to 
store a list of names, make sure that the number of columns is + 1 to include the null term. */
char names[4][11] = {"Fern",
                     "Kat", 
                     "Katnando",
                     "Fearzyn"};

// function to print out the names. **
void print_names(char p[][11], int n){ // p is a pointer to an "array of chars of size 11"
    for(int i = 0; i < n; i++)
    /* p++ increments p by an amount equal to the size of one cell of the array,
    in this case being 11 bytes. Therefore, when we dereference p, we start at each new name to print. */
        printf("%s\n", *p++); 

}

/* Note: the char array "names" above wastes space by allocating extra
space for the longest name. A better way is to allocate the amount of storage needed
by each string and use an array of pointers to point to the storage. */
char* names2[4] = {  "Fern",
                     "Kat", 
                     "Katnando",
                     "Fearzyn"};

void print_names(char* p[], int n);
// alt funct parameters since we're passing in a 1D array of type "pointer to char".
void print_names(char** p, int n); 

/* Chapter 7.7: Command-Line Arguments*************/
/* int main() can have 2 arguments: argv and argc.
   argv- array of pointers to strings
   argc- int equal to number of strings which argv points to. */

/* Chapter 7.8: Pointers to Functions*************/
/* Like array names, function names are a "pointer constant".
   Ex. If there's a function named score which returns an int, the 
   value of score can be regarded as the address of the code which reps
   the function score.
    
   - You may want to use this when passing a function as an argument
   to another function. */

   // here, we're defining a variable ptr to be of type "
   // pointer to a function w/ one parameter of type char and 
   // returns an int."
   int (*ptr)(char);

   // to invoke the function to which ptr points to w/the argument letter, 
   // you must deref ptr and supply the argument:
   ptr(letter);
   (*ptr)(letter); // both forms work;






/* Chapter 8: H*************/


/* Chapter 8: H*************/


/* Chapter 8: H*************/


/* Chapter 8: H*************/


/* Chapter 8: H*************/


/* Chapter 8: H*************/


/* Chapter 8: H*************/





/* Chapter 9.1: Opening and Closing Files (in the stdio.h library)*************/
/* Modes used when opening a file:
   "r" --> reading, error if file does not exist 
   "w" --> opens new file for writing, makes new file if file does not exist
   "a" --> appending (write to end of file), makes new file if file does not exist.
   "r+" --> reading and writing, error if file does not exist 
   "w+" --> opens new file for reading and writing, makes new file if file does not exist
   "a+" --> reading and writing to end of file, makes new file if file does not exist
   NOTE**: if already existing file is opened w/"w" or "w+", old contents are discarded*/

/* Above, those modes are used for "text file" types. However, it is also
   possible to open "binary files". To open binary files, add a "b" to the
   mode string, like "w+b". */

/* Ex. Program */
/* fopen- if successful, returns a pointer to FILE that refs the opened file. 
   if not, it returns NULL.
   fclose- returns 0 is successfully closes the file and EOF otherwise. */


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/
return 0;
}