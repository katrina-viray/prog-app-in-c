#include <stdio.h>
#include <stdlib.h>

int main() {
    
    /* To create/open/read/write to files, you declare a pointer of type FILE */
    //create file pointer
    FILE *fIN, *fOUT;

    /* Use fopen() to open the file under a certain mode:
     "w" --> writes to a file; can be used to create a new file if the file doesn't exist
     "a" --> appends new data to a file; can also be used to make a new file
     "r" --> reads from a file
    */
    //opens 2 files, one existing on for reading, and a new one for writing to
    fIN=fopen("in.txt","r");
    fOUT=fopen("out.txt","w");

    // check if file opens successfully
    if (fIN==NULL){
        printf("The file in.txt did not successfully open\n");
    }

    // create/initialize variables
    int userInt, nums, count = 0;

    // ask user to enter integer from keyboard
    printf("enter a number:");
    scanf("%d",&userInt);

    // copy integers from file in to file out, ignoring user-entered numbers
    // fscanf() returns a number when it executes; if it tries to read from a file but everything from the file has been read already, 
    // then it returns EOF (as defined in stdio.h). On Windows, EOF = -1, on Apple, EOF = 0.
    while(fscanf(fIN, "%d", &nums) != EOF){
        /* fprintf() is used to insert content into the file opened for writing.
        with "a" mode, or append mode, you add to the end of a file without deleting 
        old content and also use fprintf() to write content to the file. */
       //only adding non-user-entered numbers into fout
        if(nums != userInt)
            fprintf(fOUT,"%d\n",nums);
        else
        {
            //if user num is in file in, add to count
            count = count + 1;
        }
}
    printf("The total number of occurences of the user-entered integer is %d times\n", count);
    fclose(fOUT);
    fclose(fIN);
}
