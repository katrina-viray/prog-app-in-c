#include <stdio.h>
#include <stdlib.h>

int main(){
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
#define RECORD_LENGTH 60

    FILE* ptr; // file pointer
    ptr = fopen("PORTFOLIO.DAT", "r"); // opens file with mode specified
    char stock_prices[RECORD_LENGTH + 1];

    if(ptr == NULL){ // give error if file can't be opened
        printf("Can't open file.");
    }
    else{
        // fgets: (pointer to an array of chars where the string read is stored, 
        //          max chars to be read (including null-term),
        //         and pointer to a FILE object that identifies the stream where characters are read from.  )
        while (fgets(stock_prices, RECORD_LENGTH + 1, ptr) != NULL){
            printf("%s\n", stock_prices);
        }
    }
    fclose(ptr); // close the file

/* When a C program executes, 3 files are automatically opened: (if not redirected, then as follows:)
    1. standard input --> pointer constant is stdin, the keyboard
    2. standard output --> pointer constant is stdout, the video display
    3. standard error --> pointer constant is stderr, the video display*/

/* Chapter 9.2: Character Input/Output*************/
/* Functions for reading characters: */
FILE *fp;
char c;
c = fgetc(fp); // returns next character in the specified file or EOF if error/end is reached.
c = getc(fp); // identical to above except usually used as a macro
c = getchar(); // returns next char from the standard input or EOF if error/end is reached.

/* Functions for writing characters: (if error, all return EOF)*/
fputc(c, fp); // writes the char to the file given
putc(c, fp); // identical to above except usually used as a macro
putchar(c); // writes char to standard output

/* Chapter 9: String Input/Output*************/
#define MAX_REC_SIZE 80

FILE* file_ptr;
char record[MAX_REC_SIZE + 1]; // +1 for the null terminator
file_ptr = fopen("file.DAT", "r");
/* fgets- reads a whole string; reads characters from the file into an array until
    whichever one comes first:
    1. max - 1 chars have been read
    2. all chars up to and including next newline char have been reached
    3. EOF is reached  
    - If fgets reads a newline, the newline is stored in the array*/
while(fgets(record, MAX_REC_SIZE + 1, file_ptr) != NULL)
    fputs(record, stdout); // writes to a file; 2nd argument is the pointer to a file
    // since it is stdout, then it instead writes to the standard output.
    // it does not add a newline, so must add it manually! **

fclose(file_ptr);

/* Other functions:
    gets- reads from standard input and reads until it encounters a newline but
    discards the newline and doesn't store it in the receiving array.
        - if no chars were stored/error occurred, returns NULL.
        - adds the null terminator '\0' and returns address of the array 
    puts- writes to standard output; it appends a newline and returns EOF/nonneg value*/
char ans[2];
gets(ans);

/* Chapter 9.5: Formatted Input/Output*************/
/* scanf, fscanf, and sscanf- all are identical except for their input.
    fscanf- reads from an arbitrary file
    scanf- reads from standard input 
    - These scanning functions expect a format string and an address list.
        - Format string- specifies which chars should be taken from the input and 
        how to interpret them
        - Address list- the matching item in the address list specifies which chars 
        should be stored.
    - Each function returns EOF if it reaches the end w/out doing any conversions;
    otherwise, it returns the # of successful conversions that were stored.*/

    /* This program scans the standard input for: integer w/at most 2 digits,
    string with max length 4 and 1 for terminating null, and floating point 
    for no more than 4 decimal chars.
    Given the input 44mice2.97, it would return 3 bc it successfully converted 
    3 items: (44 into integer, "mice" into string, etc) */
    char string[5];
    int integer;
    float real;
    scanf("%2d%4s%4f", &integer, string, &real);
    
    /* printf, fprintf, and sprintf- counterparts to scan except they 
    provide formatted output. 
    NOTE*- sprintf, like its counterpart sscanf, writes to an array trather than
    to a file/standard output or input. */

    /* Character-conversions: check table on page 462. These include 
    tolower, toupper, etc. */

/* Chapter 9.6: Unformatted Input/Output*************/
/* fwrite- writes binary data; writes blocks of data w/out formatting
    to a file opened in binary mode..
   fread- reads unformatted binary data from a file. */

/* Chapter 9: Moving around in a File*************/
/* fseek. ftell, and rewind can change/determine the location of the file position marker. */

/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


/* Chapter 9: H*************/


return 0;
}