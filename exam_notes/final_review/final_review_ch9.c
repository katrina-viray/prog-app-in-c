/* All the possible file modes “w”, “w+”, “r”, “wb”, “w+b” */

/* NULL macro. 
    NULL is a macro that represents a null pointer. It is
    often used to initialize pointers before they are 
    assigned a valid memory address. The value of NULL is 
    typically zero, but its use is more portable and can 
    help make code more readable.
    
    FROM LECTURE SLIDES: This is a macro defined in stdio.h.
    This is also known as the memory address 0.
    It is used for pointers ONLY. It can be defined as ((void *)0), 
    AKA a pointer to void. This causes problems with anything 
    BUT pointers. */
#include <stdio.h>

int main() {
    // Declare a pointer and initialize it to NULL
    int *ptr = NULL;

    // Check if the pointer is NULL before dereferencing
    if (ptr == NULL) {
        printf("Pointer is NULL, not pointing to any valid memory address.\n");
    } else {
        // Attempting to dereference a NULL pointer would result in undefined behavior,
        // so it's important to check for NULL before using the pointer.
        printf("Value at the memory address pointed by ptr: %d\n", *ptr);
    }

    return 0;
}

/* fseek( ) with SEEK_SET, SEEK_CUR, SEEK_END 
   fseek() is used to move the file pointer associated 
   with a given file to a specific position.
   
   Syntax, where offset = # of bytes to offset from the position
   int fseek(FILE *pointer, long int offset, int position);

   SEEK_END: It denotes the end of the file.
   SEEK_SET: It denotes starting of the file.
   SEEK_CUR: It denotes the file pointer’s current position. */

   // C Program to demonstrate the use of fseek()
#include <stdio.h>
 
int main()
{
    FILE* fp;
    fp = fopen("test.txt", "r");
 
    // Moving pointer to end
    fseek(fp, 0, SEEK_END);
 
    // Printing position of pointer
    printf("%ld", ftell(fp));
 
    return 0;
}

#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // Open a file in binary mode for reading
    file = fopen("example.txt", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Move to the 5th byte from the beginning of the file
    fseek(file, 4, SEEK_SET);
    printf("Position after fseek(4, SEEK_SET): %ld\n", ftell(file));

    // Move 2 bytes forward from the current position
    fseek(file, 2, SEEK_CUR);
    printf("Position after fseek(2, SEEK_CUR): %ld\n", ftell(file));

    // Move to the 2nd byte from the end of the file
    fseek(file, -2, SEEK_END);
    printf("Position after fseek(-2, SEEK_END): %ld\n", ftell(file));

    // Read and print the character at the current position
    fread(&ch, 1, 1, file);
    printf("Character at the current position: %c\n", ch);

    // Close the file
    fclose(file);

    return 0;
}

/* feof( ) 
    The feof() function is used to check whether the file
    pointer to a stream is pointing to the end of the file
    or not. It returns a non-zero value if the end is 
    reached (usually 1), otherwise, it returns 0.*/
// C program to demonstrate the use of getc(), feof() and
// EOF
#include <stdio.h>
 
int main()
{
    // Open the file "test.txt" in read mode
    FILE* fp = fopen("test.txt", "r");
    // Read the first character from the file
    int ch = getc(fp);
 
    // Loop until the end of the file is
    // reached
    while (ch != EOF) {
        /* display contents of file on screen */
        putchar(ch);
 
        // Read the next character from the file
        ch = getc(fp);
    }
 
    // Check if the end-of-file indicator is
    // set for the file
    if (feof(fp))
        printf("\n End of file reached.");
    else
        printf("\n Something went wrong.");
 
    // Close the file
    fclose(fp);
 
    // Wait for a keypress
    getchar();
    return 0;
}

/* gets( ) fgets( ) read in blanks along with other characters but
scanf(“%s”,.) and fscanf(“%s”,.. stop reading at the 1st blank) 

gets()- gets() is a simple function that reads a line of
 text from the standard input (keyboard) and stores it as
  a string.
It doesn't take the size of the buffer as an argument, so
 there is a risk of buffer overflow if the input is larger than the buffer size.
It is considered unsafe because it does not perform any 
 bounds checking on the input.

fgets() is a safer alternative to gets() as it takes the 
size of the buffer as an argument, helping to prevent
 buffer overflow.
It reads a line from the specified stream (usually stdin
 for keyboard input) and stores it in the given buffer.
It appends a null character ('\0') to the end of the string.
    - it also stops reading strings either when it reaches
    the null term OR reaches the max # of chars. It leaves
    the rest of the chars to be read in for later. 

** LOOK OVER CH 9 LEC notes/ppt slides on this!
*/

/* Comparing them all */
FILE *fp;
/* NOTE: you can store MAX 799 chars and 1 for '\0'.
    Also, strlen() returns 799 and DOESN'T include '\0'  */
char str[800];
// skips leading white space and terminates when 
// it encounters trailing white space
scanf("%s", str); 
// appends '\0' and reads in white space and stores in array.
fgets(str, 799, fp); // reads up to 799 chars or if newline reached.
// DOES read in white space like blanks and tabs too.
gets(str); // reads until newline. '\0' is appended.

/* fgets example */
#include <stdio.h>
#define RECORD_LENGTH 60
int main(){
    FILE *fp;
    char s[RECORD_LENGTH+1];

    if((fp = fopen("PORTFOLIO.DAT", "r")) == NULL){
        printf("Cannot open file!\n");
    }
    else{
        while(fgets(s, RECORD_LENGTH, fp) != EOF)
            printf("\n%s", s);
        fclose(fp);
    }
}

/* Random NOTE: functions are similar with chars,
such as with fgetc, etc */
FILE *fp1;
char c;
fp1 = fopen("PORTFOLIO.DAT", "r")
c = fgetc(fp1); // reads one char from the file
c = getc(); // reads char from keyboard
c = getc(fp1); // gets next char from file
fputc(c, fp); // writes to file

/* Opening files as binary (unformatted) and accessing /using the 
bytes in the files as in the programming projects after the midterm.

In C, opening files in binary mode means that the file is 
treated as a sequence of bytes rather than as a sequence of 
formatted characters. This is important when dealing with binary
data, such as images, audio files, or any non-text files
where the exact byte values matter. 

To open a file in binary mode, you append "b" to the file
 mode string when using fopen. For example, "rb" for 
 reading binary, "wb" for writing binary, or "ab" for 
 appending in binary.*/

/* fwrite( )- transfers bytes from a location in memory
to a file.  
   fread( )-

   fwrite() and fread() are C standard library functions 
   used for writing and reading binary data to and from 
   files, respectively. They are often used when dealing 
   with raw binary data, such as images, structures, or 
   any data that is not meant to be interpreted as text. */
FILE *ptr = fopen("myfile.bin", "wb");
int n;
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
/* writes 4 (size of int) * 10 bytes into the file.
   n = 10 because this is the number of cells successfully
   written into the file. */
n = fwrite(arr, sizeof(int), 10, ptr); 

/* Another Example: */
#include <stdio.h>

// Define a simple structure for demonstration purposes
struct Person {
    char name[50];
    int age;
};

int main() {
    // Writing binary data to a file using fwrite()

    FILE *binaryFileWrite = fopen("binary_data.bin", "wb");

    if (binaryFileWrite == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Data to be written to the file
    struct Person person1 = {"John Doe", 25};

    // Writing binary data to the file
    fwrite(&person1, sizeof(struct Person), 1, binaryFileWrite);

    // Close the file
    fclose(binaryFileWrite);

    // Reading binary data from a file using fread()

    FILE *binaryFileRead = fopen("binary_data.bin", "rb");

    if (binaryFileRead == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Reading binary data from the file
    struct Person person2;
    fread(&person2, sizeof(struct Person), 1, binaryFileRead);

    // Close the file
    fclose(binaryFileRead);

    // Display the read data
    printf("Read data:\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);

    return 0;
}
